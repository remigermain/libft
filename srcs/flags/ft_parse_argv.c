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

static int	find_flags2(t_flag *st, char *flag)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	add_flags(flag[i]);
	i = parse_option(st, flag[i], flag + 1) + 1;
	while (flag[i] && flag[i] != '|' && j != 2)
	{
		if (flag[i] == ';' && (++j))
			i++;
		while (flag[i] && flag[i] != ';' && flag[i] != '|')
		{
			if (j == 1)
				add_flags(flag[i++]);
			else
				remove_flags(flag[i++]);
		}
	}
	return (1);
}

static int	find_flags(t_flag *st, char c)
{
	int	i;

	i = 0;
	if (c == 'h')
		print_usage(st);
	while (st->flag[i] && st->flag[i] != '|' && st->flag[i] != c)
		i++;
	if (st->flag[i] == c)
		return (add_flags(st->flag[i]));
	while (st->flag[++i])
	{
		if (st->flag[i] == c && i > 0 && st->flag[i - 1] == '|')
			return (find_flags2(st, st->flag + i));
		else
			i += span_alloption(st->flag + i);
	}
	return (0);
}

static int	parse_mflag(t_flag *st)
{
	int		len;
	int		i;
	int		j;

	if (!ft_strcmp(ft_strlowcase(st->argv[st->i] + 2), "help"))
		print_usage(st);
	j = 0;
	i = 0;
	len = ft_strlen(st->mflag);
	while (i + j < len)
	{
		i = ft_spanchar(st->mflag + j, ";");
		if (!ft_strncmp(st->argv[st->i] + 2, st->mflag + j, i))
		{
			if (!st->mflag[i + j + 1])
				ft_printf("%1@", "error", "wrong parsing", "mflag");
			add_flags(st->mflag[i + j + 1]);
			find_flags(st, st->mflag[i + j + 1]);
			return (1);
		}
		j += i + ft_spanchar(st->mflag + i + j, "|") + 1;
	}
	error_argv(st, "unknow flags", st->i, 0);
	return (1);
}

static int	call_flags(t_flag *st)
{
	st->j = 0;
	while (st->argv[st->i][++st->j] && cout_error_argv(ERROR_GET) <= MAX_ERROR)
	{
		if (st->argv[st->i][1] != '-')
		{
			if (!find_flags(st, st->argv[st->i][st->j]))
				error_argv(st, "unknow flags", st->i, st->j);
		}
		else if (st->argv[st->i][1] == '-')
			return (parse_mflag(st));
	}
	return (0);
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

int			init_flags(char **argv, char *flag, char *mflag, enum e_flags mod)
{
	t_flag	st;

	st.i = 1;
	st.mod = mod;
	st.flag = flag;
	st.argv = argv;
	st.mflag = mflag;
	st.argc = ft_maxlen_tab(argv, TAB_LENGHT);
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
	if (cout_error_argv(ERROR_GET | ERROR_PRINT))
		return (-1);
	return (st.i);
}
