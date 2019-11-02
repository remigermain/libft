/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <rgermain@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 11:49:01 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/02 17:49:17 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			count;
	unsigned char	*src2;
	unsigned char	*dest2;

	count = 0;
	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	while (count < n)
	{
		dest2[count] = src2[count];
		count++;
	}
	return (dest);
}
