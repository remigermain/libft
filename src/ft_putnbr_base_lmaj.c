/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 13:38:11 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 03:49:54 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_lmaj(long n, int base, int maj)
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
	ft_abs(n);
	if (n >= base)
	{
		ft_putnbr_base_lmaj((n / base), base, maj);
		ft_putnbr_base_lmaj((n % base), base, maj);
	}
	else if (n < 10)
		ft_putchar_fd((n + '0'), 1);
	else if (maj == 1)
		ft_putchar_fd((n + 55), 1);
	else
		ft_putchar_fd((n + 87), 1);
}
