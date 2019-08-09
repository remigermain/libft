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

int		missing_flags(t_flag *st)
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
	while (flag[i] && (!ft_strchr(str, flag[i]) || ft_isspace(flag[i])))
		i++;
	return (i);
}

int			parse_typeoption(t_flag *st, t_fint *it, char *flag)
{
	int j;
	int min;

	j = 1;
	if (flag[0] != '{' || flag[1] == '}')
		return (0);
	if (flag[0] != ',')
	{
		it->min = ft_atoi(flag + j );
		it->isset |= 0b1;
		ft_printf("min = %d\n", it->min);
	}
	j = ft_spanchar(flag, ",");
	if (flag[j] == ',')
		j++;
	if (flag[j] != '}')
	{
		it->max = ft_atoi(flag + j);
		it->isset |= 0b10;
		ft_printf("max = %d\n", it->max);
	}
	j += ft_spanchar(flag + j, "}");
	if (flag[j] == '}')
		j++;
	return (j);
}

void	ft_itoabuffer(char *buff, int nb2)
{
	long	nb;
	int		len;

	nb = (long)nb2;
	len = ft_intlen(nb);
	buff[len] = 0;
	while (len)
	{ 
		ft_printf("len = %d\n", len);
		buff[--len] = nb % 10 + '0';
		nb /= 10;
	}
}

void	print_errorInt(t_flag *st, t_fint it, int nb)
{
	char	msg[50];

	if ((it.isset & 0x1 && nb >= it.min) ||
		((it.isset >> 1) & 0x1 && nb <= it.max))
	{
		ft_strcpy(msg, "number c'ant be ");
		if (it.isset & 0x1 && nb >= it.min)
			ft_strcat(msg, "more than \"");
		if ((it.isset >> 1) & 0x1 && nb <= it.max)
			ft_strcat(msg, "less than \"");
		ft_itoabuffer(msg + 27, nb);
		strcat(msg, "\"");
		wrong_flags(st, "Wrong", msg);
	}
}

int			ft_typeint(t_flag *st, char *flag, char *str)
{
	t_fint	it;
	int		nb;
	int		i;
	int		j;

	i = 0;
	j = ((*str == '-' || *str == '+') ? 1 : 0);
	if (ft_str_is_numeric(str + j))
	{
		ft_bzero(&it, sizeof(t_fint));
		nb = ft_atoi(str); // nedd 
		i = parse_typeoption(st, &it, flag);
		print_errorInt(st, it, nb);
	}
	else
		wrontype_flags(st, "int ");
	return (i);
}

int			ft_typeuint(t_flag *st, char *flag, char *str)
{
	t_fint	it;
	int		nb;
	int		i;
	int		j;

	i = 0;
	j = ((*str == '-' || *str == '+') ? 1 : 0);
	if (ft_str_is_numeric(str + j))
	{
		ft_bzero(&it, sizeof(t_fint));
		nb = ft_atoi(str); // nedd atol uint
		i = parse_typeoption(st, &it, flag);
		print_errorInt(st, it, nb);
	}
	else
		wrontype_flags(st, "unsigned int ");
	return (i);
}

int			ft_typestring(t_flag *st, char *flag, char *str)
{
	if (str[0] && str[0] != '-')
	{
	}
	else
		wrontype_flags(st, "strings");
	return (0);
}

int			ft_typechar(t_flag *st, char *flag, char *str)
{
	if (str[0] && str[0] != '-' && !str[1])
	{
	}
	else
		wrontype_flags(st, "one character");
	return (0);
}

int			test_type(t_flag *st, char *flag, t_foption *op, int(*funct)(t_flag*, char*, char*))
{
	int k;
	int j;

	j = 0;
	k = st->i;
	while (st->argv[k] && st->i + op->nb != k)
		k++;
	if (st->argv[k] && st->i + op->nb == k)
	{
		op->nb_arg++;
	//	ft_printf("\n argv = %s\n", st->argv[k]);
		return (funct(st, flag, st->argv[k]));
	}
	//ft_printf("flag[o] = %c\n", flag[0]);
	missing_flags(st);
	if (flag[0] == '{')
		j = ft_spanchar(flag, "}");
	j += ft_spanchar(flag + j, ",");
	return (j);
}

int			is_type(t_flag *st, t_foption *op, char *flag)
{
	int j;

	j = ft_spanchar(flag, ",}{");
//	ft_printf("\n| type = |%.*s|\n", j, flag);
	if (!ft_strncmp(flag, "int", 3))
		j += test_type(st, flag + j, op, ft_typeint);
	else if (!ft_strncmp(flag, "uint", 4))
		j += test_type(st, flag + j, op, ft_typeuint);
	else if (!ft_strncmp(flag, "char*", 5))
		j += test_type(st, flag + j, op, ft_typestring);
	else if (!ft_strncmp(flag, "char", 4))
		j += test_type(st, flag + j, op, ft_typechar);
	else
	{
		ft_printf("unknow type %.*s\n", j, flag);
	}
	return (j);
}

static int parse_option(t_flag *st, char *flag)
{
	t_foption	op;
	int i;

	op.nb_arg = 1;
	op.nb = 0;
	i = 0;
	if (flag[i] == '{' && (++i))
	{
		while (flag[i] && flag[i] != '}')
		{
			if (flag[i] == ',')
				i++;
			op.nb++;
			i += ft_spantype(flag + i, ft_isspace);
			i += is_type(st, &op, flag + i);
			i += ft_spantype(flag + i, ft_isspace);
	//		ft_printf("%s\n", flag + i);
		}
	}
	st->add = op.nb_arg;
	if (flag[i] == '}')
		i++;
	return (i);
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
		if (ft_strchr(st->flag, st->argv[st->i][st->j]))
			find_flags(st, st->argv[st->i][st->j]);
		else
			unknow_flags(st->argv, st->i, st->j);
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
	st.i = 1;
	while (st.argv[st.i] && (st.j = 0) != 1)
	{
		if (st.argv[st.i][0] != '-' && st.mod == F_STOP)
			return (unknow_flags(NULL, st.i, 0));
		st.add = 1;
		while (st.argv[st.i][++st.j] && st.argv[st.i][0] == '-')
		{
			if (call_flags(&st))
				break ;
		}
		ft_printf("st.i, %d\n st.add %d\n", st.i, st.add);
		st.i += st.add; 
	}
	return (unknow_flags(NULL, st.i, 0));
}
