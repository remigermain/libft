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

t_bool	check_uint(t_flag *st, t_finfo *it, enum e_type mod)
{
	long	nb;

	nb = ft_atol(it->av);
	if (mod == CHECK && (!ft_str_is_numeric(it->av) || !IS_UINT(nb)))
		return (wrong_type(st, "unsigned int"));
	else if (mod == MAX && it->max < nb)
		it->error = func_lenght(st, "Number c'ant be upper than %d", it->max);
	else if (mod == MIN && it->min > nb)
		it->error = func_lenght(st, "Number c'ant be less than %d", it->min);
	else if (mod == EQ && it->eq != nb)	
		it->error = func_lenght(st, "Number need to be equal than %d", it->eq);
	else if (mod == ADD)
		add_flags_av(it->flag, (void *)&nb, INT);
	return (TRUE);
}

t_bool	check_char(t_flag *st, t_finfo *it, enum e_type mod)
{
	if (mod == CHECK && !(it->av[0] && it->av[0] != '-' && !it->av[1]))
		return (wrong_type(st, "character"));
	else if (mod == MATCH)
		func_pattern(st, it);
	else if (mod == ADD)
		add_flags_av(it->flag, (void *)it->av, CHAR);
	return (TRUE);
}

t_bool	check_string(t_flag *st, t_finfo *it, enum e_type mod)
{
	int len;

	len = ft_strlen(it->av);
	if (mod == CHECK && !(it->av[0] && it->av[0] != '-'))
		return (wrong_type(st, "string"));
	else if (mod == MAX && it->max < len)
		it->error = func_lenght(st, "Lenght c'ant be upper than %d", it->max);
	else if (mod == MIN && it->min > len)
		it->error = func_lenght(st, "Lenght c'ant be less than %d", it->min);
	else if (mod == EQ && it->eq != len)
		it->error = func_lenght(st, "Lenght need to be equal than %d", it->eq);
	else if (mod == PATTERN)
		func_pattern(st, it);
	else if (mod == ADD)
		add_flags_av(it->flag, (void *)it->av, STRING);
	return (TRUE);
}

t_bool	check_int(t_flag *st, t_finfo *it, enum e_type mod)
{
	long	nb;
	int		j;

	nb = ft_atol(it->av);
	j = ((*it->av == '-' || *it->av == '+') ? 1 : 0);
	if (mod == CHECK && (!ft_str_is_numeric(it->av + j) || !IS_INT(nb)))
		return (wrong_type(st, "int"));
	else if (mod == MAX && it->max < nb)
		it->error = func_lenght(st, "Number c'ant be upper than %d", it->max);
	else if (mod == MIN && it->min > nb)
		it->error = func_lenght(st, "Number c'ant be less than %d", it->min);
	else if (mod == EQ && it->eq != nb)	
		it->error = func_lenght(st, "Number need to be equal than %d", it->eq);
	else if (mod == ADD)
		add_flags_av(it->flag, (void*)&nb, INT);
	return (TRUE);
}
