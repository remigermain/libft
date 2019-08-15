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

int	span_option(char *flag)
{
	int j;

	j = 0;
	if (flag[0] == '{')
		j = ft_spancharspace(flag, "}");
	j += ft_spancharspace(flag + j, ",;");
	return (j);
}

int span_alloption(char *flag)
{
	int i;

	i = ft_spantype(flag, ft_isspace);
	if (flag[i] == '{' && (++i))
	{
		while (flag[i] && flag[i] != '}' && flag[i] != ';')
		{
			if (flag[i] == ',')
				i++;
			i += ft_spantype(flag + i, ft_isspace);
			i += span_option(flag + i);
			i += ft_spantype(flag + i, ft_isspace);
		}
	}
	if (flag[i] == '}')
		i++;
	return (i);
}

int parse_option(t_flag *st, char fl, char *flag)
{
	int	nb;
	int i;

	nb = 0;
	i = ft_spantype(flag, ft_isspace);
	if (flag[i] == '{' && (++i))
	{
		while (flag[i] && flag[i] != '}' && flag[i] != ';')
		{
			if (flag[i] == ',')
				i++;
			nb++;
			i += ft_spantype(flag + i, ft_isspace);
			i += is_type(st, flag + i, nb, fl);
			i += ft_spantype(flag + i, ft_isspace);
		}
	}
	if (flag[i] == '}')
		i++;
	return (i);
}

