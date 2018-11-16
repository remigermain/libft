/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   memset.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 16:02:07 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 13:36:10 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				count;
	unsigned char	*dest;

	count = 0;
	dest = (unsigned char*)b;
	while (len-- > 0)
		dest[count++] = (unsigned char)c;
	b = (void*)dest;
	return (b);
}
