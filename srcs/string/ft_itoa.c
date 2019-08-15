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

char	*ft_itoa(int n)
{
	return (ft_itoa_base(n, 10));
}

void	ft_itoabasebuffer(char *buff, int nb2, int base)
{
	long	nb;
	int		len;

	nb = (long)nb2;
	len = ft_intlen_base(nb, base);
	buff[len] = 0;
	while (len)
	{ 
		buff[--len] = nb % base + '0';
		nb /= 10;
	}
}

void	ft_itoabuffer(char *buff, int nb)
{
	ft_itoabasebuffer(buff, nb, 10);
}

