/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 13:38:11 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 05:27:09 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlnbr(long int nb)
{
	ft_putlnbr_fd(nb, 1);
}

void	ft_putlnbr_fd(long int nb, int fd)
{	
	if ((nb + 1) == -9223372036854775807)
	{
		ft_putchar('9');
		nb = 223372036854775808;
	}
	if (nb < 0)
		nb = -nb;
	if (nb > 9)
	{
		ft_putlnbr_fd((nb / 10), fd);
		ft_putlnbr_fd((nb % 10), fd);
	}
	else
		ft_putchar_fd((nb + '0'), fd);
}
