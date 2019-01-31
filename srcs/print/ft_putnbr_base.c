/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 13:38:11 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 17:28:22 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int n, int base)
{
	if (base > 16 || base < 2)
		return ;
	if (n == -2147483648 && base == 10)
	{
		ft_putchar_fd('-', 1);
		ft_putchar_fd('2', 1);
		n = 147483648;
	}
	if (n < 0 && base == 10)
	{
		ft_putchar_fd('-', 1);
		n = n * -1;
	}
	else if (n < 0)
		n = -n;
	if (n > base)
	{
		ft_putnbr_base((n / base), base);
		ft_putnbr_base((n % base), base);
	}
	else if (n < 10)
		ft_putchar_fd((n + '0'), 1);
	else
		ft_putchar_fd(((n % 10) + 65), 1);
}
