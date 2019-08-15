/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_uppercase.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/06 12:05:46 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 15:02:50 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_str_is_uppercase(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		if (!ft_uppercase(str[i]))
			return (FALSE);
	return (TRUE);
}
