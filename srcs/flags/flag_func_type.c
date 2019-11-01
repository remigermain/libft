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
		func_lenght(st, it, "Number c'ant be upper than %d", it->max);
	else if (mod == MIN && it->min > nb)
		func_lenght(st, it, "Number c'ant be less than %d", it->min);
	else if (mod == EQ && it->eq != nb)	
		func_lenght(st, it, "Number need to be equal than %d", it->eq);
	else if (mod == ADD)
		add_flags_av(it->mfl, it->sfl, (void *)&nb, INT);
	return (TRUE);
}

t_bool	check_char(t_flag *st, t_finfo *it, enum e_type mod)
{
	if (mod == CHECK && !(it->av[0] && it->av[0] != '-' && !it->av[1]))
		return (wrong_type(st, "character"));
	else if (mod == MATCH)
		func_pattern(st, it);
	else if (mod == ADD)
		add_flags_av(it->mfl, it->sfl, (void *)it->av, CHAR);
	return (TRUE);
}

t_bool	check_string(t_flag *st, t_finfo *it, enum e_type mod)
{
	int len;

	len = ft_strlen(it->av);
	if (mod == CHECK && !(it->av[0] && it->av[0] != '-'))
		return (wrong_type(st, "string"));
	else if (mod == MAX && it->max < len)
		func_lenght(st, it, "Lenght c'ant be upper than %d", it->max);
	else if (mod == MIN && it->min > len)
		func_lenght(st, it, "Lenght c'ant be less than %d", it->min);
	else if (mod == EQ && it->eq != len)
		func_lenght(st, it, "Lenght need to be equal than %d", it->eq);
	else if (mod == PATTERN)
		func_pattern(st, it);
	else if (mod == ADD)
		add_flags_av(it->mfl, it->sfl, (void *)it->av, STRING);
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
		func_lenght(st, it, "Number c'ant be upper than %d", it->max);
	else if (mod == MIN && it->min > nb)
		func_lenght(st, it, "Number c'ant be less than %d", it->min);
	else if (mod == EQ && it->eq != nb)	
		func_lenght(st, it, "Number need to be equal than %d", it->eq);
	else if (mod == ADD)
		add_flags_av(it->mfl, it->sfl, (void *)&nb, INT);
	return (TRUE);
}

# include <fcntl.h>
t_bool check_file(t_flag *st, t_finfo *it, enum e_type mod)
{
	
	int fd;
	int len;

	len = ft_strlen(it->av);
	if (mod == CHECK)
	{
		fd = open(it->av, O_RDONLY);
		close(fd);
		if (fd == -1)
			return (wrong_type(st, "c'ant open file"));
	}
	else if (mod == MAX && it->max < len)
		func_lenght(st, it, "File lenght c'ant be upper than %d", it->max);
	else if (mod == MIN && it->min > len)
		func_lenght(st, it, "File lenght c'ant be less than %d", it->min);
	else if (mod == EQ && it->eq != len)
		func_lenght(st, it, "File lenght need to be equal than %d", it->eq);
	else if (mod == PATTERN)
		func_pattern(st, it);
	else if (mod == ADD)
		add_flags_av(it->mfl, it->sfl, (void *)it->av, STRING);
	return (TRUE);
}