/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgermain <rgermain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:22:10 by rgermain          #+#    #+#             */
/*   Updated: 2019/10/03 19:24:30 by rgermain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error_line(const char *str)
{
	ft_dprintf(2, T_RED"error: "T_LGREY"%s.\n"T_WHITE, str);
}

void	error_line_pos(const char *error, int line, int pos)
{
	if (line != -1)
		ft_dprintf(2, "%d:", line);
	if (pos != -1)
		ft_dprintf(2, "%d:", pos);
	ft_dprintf(2, " ");
	error_line(error);
}

void	error_line_e(const char *str, int pos)
{
	int i;

	i = 0;
	ft_dprintf(2, "\t");
	while (*str)
	{
		if (i == pos)
			ft_dprintf(2, T_RED);
		ft_dprintf(2, "%c", *str);
		if (i == pos)
			ft_dprintf(2, T_WHITE);
		if (i <= pos)
			i++;
		str++;
	}
	ft_dprintf(2, "\n\t%*@"T_RED"^"T_WHITE"\n", pos, "char", ' ');
}
