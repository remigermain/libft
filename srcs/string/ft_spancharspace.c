/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spancharspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgermain <rgermain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:19:09 by rgermain          #+#    #+#             */
/*   Updated: 2019/10/10 17:15:44 by rgermain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int			ft_spancharspace(const char *flag, const char *str)
{
	int i;

	i = 0;
	while (flag[i] && (!ft_strchr(str, flag[i]) || ft_isspace(flag[i])))
		i++;
	return (i);
}
