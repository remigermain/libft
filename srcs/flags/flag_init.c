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

static t_bool	find_mflags(t_flag *st, char *mfl)
{
	t_reg_list *lst;
	t_reg_list *head;

	head = NULL;
	if (!ft_strcmp(mfl, "help"))
		print_usage(st);
	lst = st->reg.capt;
	while (lst)
	{
		if (lst->token && !ft_strcmp(lst->token, "mflags")
						&& !ft_strcmp(lst->str, mfl))
			return (parse_flags(st, lst, head));
		head = lst;
		lst = lst->next;
	}
	error_argv(st, "unknow flags", st->i, 0);
	return (FALSE);
}

static t_bool find_sflags(t_flag *st, int sfl)
{
	t_reg_list *lst;
	t_reg_list *head;

	head = NULL;
	if (sfl == 'h')
		print_usage(st);
	lst = st->reg.capt;
	while (lst)
	{
		if (lst->token && !ft_strcmp(lst->token, "sflag")
						&& *lst->str == sfl)
			return (parse_flags(st, lst, head));
		head = lst;
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
			return (find_mflags(st, st->argv[st->i] + 2));
		else
			find_sflags(st, st->argv[st->i][st->j]);
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

int			flag_init(char **argv, char *flag, enum e_flags mod)
{
	t_flag	st;

	st.i = 1;
	st.argv = argv;
	st.argc = ft_maxlen_tab(argv, TAB_LENGHT);
	ft_regex_exec(&(st.reg), flag, REGEX_ARGV_PARSE);
	while (st.argv[st.i] && cout_error_argv(ERROR_GET) <= MAX_ERROR)
	{
		if ((st.argv[st.i][0] != '-' && mod == F_STOP) ||
				!ft_strcmp("--", st.argv[st.i]))
			break ;
		st.add = 1;
		if (st.argv[st.i][0] == '-')
			call_flags(&st);
		else if (!add_flags_av(FLAG_AV, FLAG_AV, (void*)st.argv[st.i], STRING))
		{
			ft_regex_free(&(st.reg));
			return (error_argv(&st, "To many arguments", st.i + st.add, 0));
		}
		st.i += st.add;
	}
	while (st.argv[st.i])
		add_flags_av(FLAG_AV, FLAG_AV, (void*)st.argv[st.i++], STRING);
	ft_regex_free(&(st.reg));
	return (cout_error_argv(ERROR_GET | ERROR_PRINT) ? -1 : st.i);
}
