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
	i += parse_option(st, flag[i++], flag + 1);
	while (flag[i] && flag[i] != '|' && j != 2)
	{
		if (flag[i] == ';' && (++j))
			i++;
		while (flag[i] && flag[i] != ';' && flag[i] != '|')
			flags_base(flag[i++], (j == 1 ? F_ADD : F_RM), NULL, 0);
	}
	return (1);
}

static int	find_flags(t_flag *st, char c)
{
	int	i;

	i = 0;
	while (st->flag[i] && st->flag[i] != '|' && st->flag[i] != c)
		i++;
	if (st->flag[i] == c)
		return (add_flags(st->flag[i]));
	while (st->flag[++i])
	{
		if (st->flag[i] == c && i > 0 && st->flag[i - 1] == '|')
			return (find_flags2(st, st->flag + i));
		else
			i += span_alloption(st, st->flag + i);
	}
	return (0);
}

static int	parse_mflag(t_flag *st)
{
	int		min;
	int		max;
	int		len;

	min = 0;
	len = 0;
	if (st->mflag)
		len = ft_strlen(st->mflag);
	while (min < len)
	{
		max = len - ft_strlen(ft_strchr(st->mflag + min, '|')) - min;
		if (!ft_strncmp(st->argv[st->i] + 2, st->mflag + min, max - 3) &&
			(int)ft_strlen(st->argv[st->i] + 2) == (max - 2))
		{
			flags_base(st->mflag[max - 1], F_ADD, NULL, 0);
			find_flags(st, st->mflag[max - 1]);
			return (1);
		}
		min += max + 1;
	}
	unknow_flags(st->argv, st->i, 0);
	return (1);
}

/*
**		flags| flag ; set_flag ; unset_flag | ... ect
**		mflag ; set_flag | ... ect
*/

int			call_flags(t_flag *st)
{
	st->j = 0;
	while (st->argv[st->i][++st->j])
	{
		if (st->argv[st->i][1] != '-')
		{
			if (!find_flags(st, st->argv[st->i][st->j]))
				unknow_flags(st->argv, st->i, st->j);
		}
		else if (st->argv[st->i][1] == '-')
			return (parse_mflag(st));
	}
	return (0);
}

int			init_flags(char **argv, char *flag, char *mflag, enum e_flags mod)
{
	t_flag	st;

	st.i = 1;
	st.mod = mod;
	st.flag = flag;
	st.argv = argv;
	st.mflag = mflag;
	st.argc = ft_maxlen_tab(argv, TAB_LENGHT);
	while (st.argv[st.i] && cout_error_argv(ERROR_GET) < MAX_ERROR)
	{
		if (st.argv[st.i][0] != '-' && st.mod == F_STOP)
			break ;
		st.add = 1;
		if (st.argv[st.i][0] == '-')
			call_flags(&st);
		else if (!add_flags_av(FLAG_ARGV, (void*)st.argv[st.i], STRING))
			return (-many_argv(&st));
		st.i += st.add;
	}
    print_usage(&st);
	if (cout_error_argv(ERROR_GET | ERROR_PRINT))
		return (-1);
	return (st.i);
}
