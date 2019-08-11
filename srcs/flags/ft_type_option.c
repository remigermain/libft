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

void		name_option_match(t_flag *st, t_finfo *it, char *str)
{
	char mem[127];
	int i;
	int j;

	i = 0;
	ft_bzero(mem, 127);
	while (it->str[i])
	{
		if (it->str[i] == '|')
			i++;
		i += ft_spantype(it->str + i, ft_isspace);		
		j = ft_spanchar(it->str + i, "|");
		ft_strncpy(mem, it->str + i, j);
		if (ft_match(str, mem))
			return ;
		i += j;
		i += ft_spantype(it->str + i, ft_isspace);
	}
	it->error = not_match(st, str, it->str);
}

int			parse_typeoption(t_flag *st, t_finfo *it, char *flag)
{
	int j;

	j = 1;
	if (flag[0] != '{' || flag[1] == '}')
		return (0);
	j += ft_spantype(flag, ft_isspace);
	if (flag[j] != ',')
	{
		it->min = ft_atoi(flag + j );
		it->isset |= 0b1;
		j += ft_spancharspace(flag + j, ",}");
	}
	j += ft_spantype(flag + j, ft_isspace) + 1;
	if (flag[j] != '}' && flag[j] != ',')
	{
		it->max = ft_atoi(flag + j);
		it->isset |= 0b10;
		j += ft_spancharspace(flag + j, ",}");
	}
	j += ft_spantype(flag + j, ft_isspace);
	if (flag[j++] == ',')
	{
		ft_strncpy(it->str, flag + j, ft_spancharspace(flag + j, "}"));
		it->isset |= 0b100;
		j += ft_spancharspace(flag + j, ",}");
	}
	return (j);
}