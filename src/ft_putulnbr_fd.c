/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 13:38:11 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 09:00:55 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putulnbr_base(unsigned long int nb, unsigned long int base)
{
	if (nb > base)
	{
		ft_putulnbr_base((nb / base), base);
		ft_putulnbr_base((nb % base), base);
	}
	else
		ft_putchar((nb + '0'));
}

void	ft_putulnbr_fd(unsigned long int nb, int fd)
{
	if (nb > 9)
	{
		ft_putulnbr_fd((nb / 10), fd);
		ft_putulnbr_fd((nb % 10), fd);
	}
	else
		ft_putchar_fd((nb + '0'), fd);
}
