/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_spantype.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <rgermain@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/06 11:57:31 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/02 18:02:02 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
