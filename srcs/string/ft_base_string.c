/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgermain <rgermain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 11:14:09 by rgermain          #+#    #+#             */
/*   Updated: 2019/09/22 17:34:14 by rgermain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

<<<<<<< HEAD

#include "libft.h" 
=======
#include "libft.h"
>>>>>>> master

t_bool	ft_base_string(char letter, int base)
{
	char	*base_string;

	base_string = "00123456789abcdef";
	letter = ft_tolower(letter);
	if (ft_strchr(base_string, letter))
		return (TRUE);
	return (FALSE);
}
