/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:24:04 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 20:46:27 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_itoabase_buffer(char *buff, int nb, int base)
{
	int		len;
	long	n;

	n = (long)ABS(nb);
	len = ft_intlen_base(n, base);
	if (nb < 0 && base == 10)
		*buff++ = '-';
	while (len)
	{
		buff[--len] = n % base + (n % base < 10 ? 48 : 55);
		n /= base;
	}
}
