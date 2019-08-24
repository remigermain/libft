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

t_bool	check_uint(t_flag *st, t_finfo *it, char *str, enum e_type mod)
{
	int	j;
	int	nb;

	nb = ft_atoi(str);
	j = ((*str == '-' || *str == '+') ? 1 : 0);
	if (mod == CHECK && !ft_str_is_numeric(str + j))
		return (wrong_type(st, "int"));
	else if ((mod == MAX && it->max < nb) || (mod == MIN && it->min > nb))
		func_obj_minmax(st, it, "number", mod);
	else if (mod == ADD)
		add_flags_av(it->fl, (void*)&nb, INT);
	return (TRUE);
}

t_bool	check_char(t_flag *st, t_finfo *it, char *str, enum e_type mod)
{
	if (mod == CHECK && !(str[0] && str[0] != '-' && !str[1]))
		return (wrong_type(st, "character"));
	else if (mod == MATCH)
		func_obj_match(st, it, str);
	else if (mod == ADD)
		add_flags_av(it->fl, (void*)str, CHAR);
	return (TRUE);
}

t_bool	check_string(t_flag *st, t_finfo *it, char *str, enum e_type mod)
{
	if (mod == CHECK && !(str[0] && str[0] != '-'))
		return (wrong_type(st, "string"));
	else if ((mod == MAX && it->max < (int)ft_strlen(str)) ||
			(mod == MIN && it->min > (int)ft_strlen(str)))
		func_obj_minmax(st, it, "string", mod);
	else if (mod == MATCH)
		func_obj_match(st, it, str);
	else if (mod == ADD)
		add_flags_av(it->fl, (void*)str, STRING);
	return (TRUE);
}

t_bool	check_int(t_flag *st, t_finfo *it, char *str, enum e_type mod)
{
	int	j;
	int	nb;

	nb = ft_atoi(str);
	j = ((*str == '-' || *str == '+') ? 1 : 0);
	if (mod == CHECK && !ft_str_is_numeric(str + j))
		return (wrong_type(st, "int"));
	else if ((mod == MAX && it->max < nb) || (mod == MIN && it->min > nb))
		func_obj_minmax(st, it, "number", mod);
	else if (mod == ADD)
		add_flags_av(it->fl, (void*)&nb, INT);
	return (TRUE);
}
