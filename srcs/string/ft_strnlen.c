/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/02 11:14:09 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 21:55:19 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *s, size_t max)
{
	size_t count;

	count = 0;
	while (count < max && s[count] != '\0')
		count++;
	return (count);
}
