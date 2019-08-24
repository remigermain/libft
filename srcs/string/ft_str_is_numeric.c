/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_numeric.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/06 12:01:16 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 15:02:15 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_str_is_numeric(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (!ft_isdigit(str[i]))
			return (FALSE);
	return (TRUE);
}
