/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:24:04 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 20:51:37 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(int nb, int base)
{
	char	*str;
	int		len;
	long	n;

	n = (long)ABS(nb);
	len = ft_intlen_base(n, base);
	if (!(str = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (nb < 0 && base == 10)
		*str++ = '-';
	while (len)
	{
		str[--len] = n % base + (n % base < 10 ? 48 : 55);
		n /= base;
	}
	return (nb < 0 && base == 10 ? str - 1 : str);
}
