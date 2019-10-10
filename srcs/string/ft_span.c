/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_span.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgermain <rgermain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:19:09 by rgermain          #+#    #+#             */
/*   Updated: 2019/10/10 17:15:52 by rgermain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int	ft_spantype(const char *str, t_bool (*func)(int))
{
	int i;

	i = 0;
	while (str[i] && func(str[i]))
		i++;
	return (i);
}
