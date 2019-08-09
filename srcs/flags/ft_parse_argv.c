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

int		wrong_flags(t_flag *st, char *msg, char *type)
{
	static int error = 0;

	ft_dprintf(2, T_RED"error: "T_LGREY"%s %s.\n"T_WHITE, msg, type);
	ft_error_argv(st->argv, st->i, st->j);
	return (error++);
}

int		wrontype_flags(t_flag *st, char *type)
{
	return (wrong_flags(st, "Wrong argument type, need ", type));
}

int		missing_flags(t_flag *st, char *type)
{
	return (wrong_flags(st, "Missing arguments", ""));
}

int			ft_spantype(char *str, int (*func)(int))
{
	int i;

	i = 0;
	while (str[i] && func(str[i]))
		i++;
	return (i);
}

int			ft_spanchar(char *flag, char *str)
{
	int i;

	i = 0;
	while (flag[i] && !ft_strchr(str, flag[i]) && !ft_isspace(flag[i]))
		i++;
	return (i);
}

int			ft_typeint(t_flag *st, char *str)
{
	(void)str;

	if (ft_str_is_numeric(str))
	{
		//ft_printf("int  |%s|\n", str);
	}
	else
		wrontype_flags(st, "int ");
		//ft_atol(str);
	return (0);
}

int			ft_typeuint(t_flag *st, char *str)
{
	(void)str;
	//ft_atol(str);
	//ft_printf("uint\n");
	return (0);
}

int			ft_typestring(t_flag *st, char *str)
{
	(void)str;
	//ft_atol(str);
//	ft_printf("char*\n");
	return (0);
}

int			ft_typechar(t_flag *st, char *str)
{
	(void)str;
	//ft_atol(str);
//	ft_printf("char\n");
	return (0);
}

int			test_type(t_flag *st, int nb, int(*funct)(t_flag*, char*))
{
	int k;

	k = st->i;
	while (st->argv[k] && st->i + nb != k)
		k++;
	if (st->argv[k] && st->i + nb == k)
	{
		(void)funct(st, st->argv[k]);
	}
	else
		missing_flags(st, "flag missing");
	//sleep(1);
	return (0);
}

int			is_type(t_flag *st, char *flag, int nb)
{
	int j;

	j = ft_spanchar(flag, ",}");
	if (!ft_strncmp(flag, "int", j))
		test_type(st, nb, ft_typeint);
	else if (!ft_strncmp(flag, "uint", j))
		test_type(st, nb, ft_typeuint);
	else if (!ft_strncmp(flag, "char", j))
		test_type(st, nb, ft_typechar);
	else if (!ft_strncmp(flag, "char*", j))
		test_type(st, nb, ft_typestring);
	else
		ft_printf("nothing\n");
	return (j);
}

void		ddebug(char *str, int i, int j, int nb_arg)
{
	ft_printf("[str] \"%s\"\n[i] %d\n[j] %d\n[nb_arg] %d\n", str, i, j, nb_arg);
}
static int parse_option(t_flag *st, char *flag)
{
	int i;
	int j;
	int k;
	int nb;
	int	nb_arg;

	i = 0;
	j = 0;
	nb_arg = 0;
	k = 0;
	nb = 0;
	//ddebug(flag + i, i, j, nb_arg);
	if (flag[i] == '{')
	{
		i++;
		nb_arg = ft_atoi(flag + i);
		i += ft_spantype(flag + i, ft_isdigit);
		while (nb_arg && flag[i] && flag[i] != '}')
		{
			if (flag[i] == ',')
				i++;
			i += ft_spantype(flag + i, ft_isspace);
			i += is_type(st, flag + i, nb);
			i += ft_spantype(flag + i, ft_isspace);
			nb++;
		}
	}
	st->add = nb;
	return (nb_arg);
}

static int	find_flags2(t_flag *st, char *flag)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	flags_base(st->flag[i++], F_ADD);
	i += parse_option(st, flag + 1);
	while (st->flag[i] && st->flag[i] != '|' && j != 2)
	{
		if (st->flag[i] == ';' && (++j))
			i++;
		while (st->flag[i] && st->flag[i] != ';' && st->flag[i] != '|')
			flags_base(st->flag[i++], (j == 1 ? F_ADD : F_RM));
	}
	return (0);
}

static int	find_flags(t_flag *st, char c)
{
	int	i;

	i = 0;
	while (st->flag[i] && st->flag[i] != '|' && st->flag[i] != c)
		i++;
	if (st->flag[i] == c)
		return (flags_base(c, F_ADD));
	while (st->flag[++i])
	{
		if (st->flag[i] == c && i > 0 && st->flag[i - 1] == '|')
			return (find_flags2(st, st->flag + i));
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
			flags_base(st->mflag[max - 1], F_ADD);
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
	if (st->argv[st->i][1] != '-')
	{
		st->add = 0;
		if (ft_strchr(st->flag, st->argv[st->i][st->j]))
			find_flags(st, st->argv[st->i][st->j]);
		else
			unknow_flags(st->argv, st->i, st->j);
		ft_printf("i = %d, %d\n", st->i, st->add);
		st->i += st->add;
	}
	else if (st->argv[st->i][1] == '-')
		return (parse_mflag(st));
	return (0);
}

int			init_flags(char **argv, char *flag, char *mflag, enum e_flags mod)
{
	t_flag	st;

	ft_bzero(&st, sizeof(t_flag));
	st.argv = argv;
	st.flag = flag;
	st.mflag = mflag;
	st.mod = mod;
	while (st.argv[++st.i] && (st.j = 0) != 1)
	{
		if (st.argv[st.i][0] != '-' && st.mod == F_STOP)
			return (unknow_flags(NULL, st.i, 0));
		while (st.argv[st.i][++st.j] && st.argv[st.i][0] == '-')
		{
			if (call_flags(&st))
				break ;
		}
	}
	return (unknow_flags(NULL, st.i, 0));
}
