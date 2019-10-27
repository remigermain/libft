/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isword.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgermain <rgermain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:48:43 by rgermain          #+#    #+#             */
/*   Updated: 2019/09/27 21:04:21 by rgermain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

t_bool  ft_isword(int c)
{
    if (ft_isdigit(c) || ft_isalpha(c) || c == '_')
        return (TRUE);
    return (FALSE);
}