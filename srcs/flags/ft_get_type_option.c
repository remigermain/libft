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

static int	parse_number(char *flag, int *number, int *set, enum e_option e_set)
{
	int i;

	i = 0;
	if (flag[i] && flag[i] != '}' && flag[i] != ',')
	{
		(*number) = ft_atoi(flag + i );
		(*set) |= e_set;
		i += ft_spancharspace(flag + i, ",}");
	}
	return (i);
}

static int	parse_pattern(char *flag, char *str, int *set, enum e_option e_set)
{
	int i;

	i = 0;
	if (flag[i] && flag[i] != '}' && flag[i] != ',')
	{
		ft_strncpy(str, flag + i, ft_spancharspace(flag + i, "}"));
		(*set) |= e_set;
		i += ft_spancharspace(flag + i, ",}");
	}
	return (i);
}

int			parse_typeoption(t_finfo *it, char *flag)
{
	int i;

	i = 1;
	if (flag[0] != '{' || flag[1] == '}')
		return (0);
	i += ft_spantype(flag, ft_isspace);
	i += parse_number(flag + i, &(it->min), &(it->isset), OP_MIN);
	i += ft_spantype(flag + i, ft_isspace) + 1;
	i += parse_number(flag + i, &(it->max), &(it->isset), OP_MAX);
	i += ft_spantype(flag + i, ft_isspace) + 1;
	i += parse_pattern(flag + i, it->str, &(it->isset), OP_PATTERN);
	return (i);
}