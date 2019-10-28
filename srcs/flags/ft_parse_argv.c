/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse_argv.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 16:19:09 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/20 16:26:06 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static t_bool	find_flags(t_flag *st, char *c)
{
	t_reg_list *lst;

	ft_printf("find_flag  %s\n", c);
	if (!ft_strcmp(c, "help") || *c == 'h')
		print_usage(st);
	lst = st->reg.capt;
	while (lst)
	{
		if (lst->token && (!ft_strcmp(lst->token, "alone") ||
		!ft_strcmp(lst->token, "flags")) && !ft_strcmp(lst->str, c))
			return (parse_flags(st, lst));
		lst = lst->next;
	}
	error_argv(st, "unknow flags", st->i, st->j);
	return (FALSE);
}

static t_bool	call_flags(t_flag *st)
{
	st->j = 0;
	while (st->argv[st->i][++st->j] && cout_error_argv(ERROR_GET) <= MAX_ERROR)
	{
		if (st->argv[st->i][1] == '-')
		{
			st->j = 0;
			return (find_flags(st, st->argv[st->i] + 2));
		}
		else
		{
			ft_printf("icici\n");
			find_flags(st, &(st->argv[st->i][st->j]));
		}
	}
	return (TRUE);
}

/*
**		usage :
**
**		mod :  F_STOP  stop get flag when he have other than '-'
**
**		alone_flag  |  flag  { type {min, max, pattern} , ....} ; set_flag ; unset_flag | ... ect
**		type :  char*	{min, max, pattern}
**				int		{min, max}
**				char	{min, max, pattern}
**				file	{min, max, pattern}
**
**		pattern :  name  | name | ..ect
**		pipe is for "or"
**		if in name as * , is match for all character like : *.cor match with  explosivekitty.cor or bazou.cor
**
**		mflag ; set_flag | ... ect
**		animation;a|  --animation is same as -a
*/

#define REGEX_ARGV_PARSE "^(\\s*(?<alone>[\\w\\-]*)\\s*,)*\\s*\\|(\\s*(?<flags>[\\w\\-]+)\\s*(\\(\\s*((?<type>[a-zA-Z*_]+)\\s*((\\{\\s*((?<opt_min>[\\d]*)\\s*,\\s*(?<opt_max>[\\d]*)\\s*(\\s*,\\s*\"(?<opt_pattern>[^\"]+)\"\\s*)?|\\s*(?<opt_ex>[\\d]*)\\s*)\\s*\\})?\\s*,\\s*)?)*\\s*\\))?\\s*;\\s*((?<set>[\\w\\-]*)\\s*,\\s*)*\\s*;\\s*((?<unset>[\\w\\-]*)\\s*,\\s*)*\\s*;\\s*\\|)*$"
int			init_flags(char **argv, char *flag, char *mflag, enum e_flags mod)
{
	t_flag	st;

	
	st.i = 1;
	st.mod = mod;
	st.flag = flag;
	st.argv = argv;
	st.mflag = mflag;
	st.argc = ft_maxlen_tab(argv, TAB_LENGHT);
	ft_printf("[FLAG   %s ]\n\n", flag);
	t_bool ret = ft_regex_exec(&(st.reg), flag, REGEX_ARGV_PARSE);
	if (ret > 0)
		ft_printf("\033[38;5;326mTRUE  %d\n" T_WHITE, ret);
	else if (ret == 0)
		ft_printf("\033[1;31mFALSE  %d\n" T_WHITE, ret);
	else
		ft_printf("\033[1;31mERROR MALLOC %d\n" T_WHITE, ret);

	if (ret == 0)
	{
		ft_printf("lalal %d   %s\n", st.reg.error_pos, st.reg.s1);
		error_line_pos("error parsing", 76, st.reg.error_pos);
		error_line_e(st.reg.s1, st.reg.error_pos);
	}

	ft_regex_print(&(st.reg));
	while (st.argv[st.i] && cout_error_argv(ERROR_GET) <= MAX_ERROR)
	{
		if ((st.argv[st.i][0] != '-' && st.mod == F_STOP) ||
				!ft_strcmp("--", st.argv[st.i]))
			break ;
		st.add = 1;
		if (st.argv[st.i][0] == '-')
			call_flags(&st);
		else if (!add_flags_av(FLAG_ARGV, (void*)st.argv[st.i], STRING))
			return (error_argv(&st, "To many arguments", st.i + st.add, 0));
		st.i += st.add;
	}
	while (st.argv[st.i])
		add_flags_av(FLAG_ARGV, (void*)st.argv[st.i++], STRING);
	ft_regex_free(&(st.reg));
	if (cout_error_argv(ERROR_GET | ERROR_PRINT))
		return (-1);
	return (st.i);
}
