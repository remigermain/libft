/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_type.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <rgermain@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/06 11:57:31 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/02 18:37:12 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_str_is_type(char *str, t_bool (*func)(int c))
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		if (!func(str[i]))
			return (FALSE);
	return (TRUE);
}
