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

int			type_all(t_flag *st, t_finfo *it, t_bool(*type_av)
						(t_flag *st, t_finfo*, char*, enum e_type))
{
	int	i;

	i = 0;
	if	(type_av(st, it, it->av, CHECK))
	{
		i = parse_typeoption(it, it->flag);
		if (it->isset & OP_MIN)
			type_av(st, it, it->av, MIN);
		if (it->isset & OP_MAX)
			type_av(st, it, it->av, MAX);
		if (it->isset & OP_PATTERN)
			type_av(st, it, it->av, MATCH);
		if (!it->error)
			type_av(st, it, it->av, ADD);
	}
	st->add++;
	return (i);
}

int			find_type(t_flag *st, char *flag, char fl, int i)
{
	static char	*type[4] = {"int", "char*", "char", "uint"};
	static t_bool(*func_type[4])(t_flag *st, t_finfo*, char*, enum e_type) =
		{check_int, check_string, check_char, check_uint};
	int		ret;
	int		j;

	ret = 0;
	j = 0;
	st->it.fl = fl;
	st->it.flag = flag + ft_spancharspace(flag, ",}{");
	st->it.av = st->argv[i];
	while (j < 4 && ft_strncmp(flag, type[j], ft_strlen(type[j])))
		j++;
	if (j < 4)
		ret = type_all(st, &(st->it), func_type[j]);
	else
		ft_printf("unknow type %.*s\n", j, flag);	
	return (ret);
}

int			is_type(t_flag *st, char *flag, int nb, char fl)
{
	int	i;

	i = ft_spancharspace(flag, ",}{");
	ft_bzero(&(st->it), sizeof(t_finfo));
	if ((st->i + nb) < st->argc)
		i += find_type(st, flag, fl, (st->i + nb));
	else
		error_argv(st, "Missing arguments", st->i + st->add, 0);
	return (span_option(flag + i) + i);
}