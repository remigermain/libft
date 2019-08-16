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

void	ft_itoabase_buffer(char *buff, int nb2, int base)
{
	long	nb;
	int		len;
	int		min;

	nb = (long)nb2;
	min = 0;
	len = ft_intlen_base(nb, base);
	buff[len] = 0;
    if (nb2 < 0)
	{
		nb2 = -nb2;
		if (base == 10)
		{
			min = 1;
        	buff[0] = '-';
		}
	}
	while (len)
	{ 
		buff[min + --len] = nb % base + '0';
		nb /= base;
	}
}
