/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_printable.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/06 12:06:59 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 15:12:59 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_str_is_printable(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		if (!ft_isprint(str[i]))
			return (FALSE);
	return (TRUE);
}
