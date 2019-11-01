/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_lowercase.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/06 12:03:26 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 14:31:19 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_str_is_lowercase(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		if (!ft_islowercase(str[i]))
			return (FALSE);
	return (TRUE);
}
