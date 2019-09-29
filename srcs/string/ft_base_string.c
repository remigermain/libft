/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgermain <rgermain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 11:14:09 by rgermain          #+#    #+#             */
/*   Updated: 2019/09/29 17:01:09 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

t_bool	ft_base_string(char letter, int base)
{
	char	*base_string;
	int		i;
	int		isset;

	i = -1;
	isset = 0;
	base_string = "0123456789abcdef";
	letter = ft_tolower(letter);
	while (++i < base)
	{
		if (base_string[i] == letter)
			isset = 1;		
	}
	if (isset)
		return (TRUE);
	return (FALSE);
}
