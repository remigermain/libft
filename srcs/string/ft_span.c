/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_span.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <rgermain@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/06 11:57:31 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/02 17:50:33 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_span(const char *flag, const char *str)
{
	int	i;

	i = 0;
	while (flag[i] && ft_strchr(str, flag[i]))
		i++;
	return (i);
}
