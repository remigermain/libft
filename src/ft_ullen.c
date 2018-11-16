/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ullen.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 04:29:48 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 08:52:47 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_llen_base(long int nb, int base)
{
	int count;

	count = 0;
	if ((nb + 1) == -9223372036854775807)
		return (19);
	if (nb < 0)
		nb = -nb;
	while (nb > base)
	{
		nb /= base;
		count++;
	}
	return (count + 1);
}

int	ft_llen(long int nb)
{
	int count;

	count = 0;
	if ((nb + 1) == -9223372036854775807)
		return (19);
	if (nb < 0)
		nb = -nb;
	while (nb > 10)
	{
		nb /= 10;
		count++;
	}
	return (count + 1);
}

int	ft_ullen(unsigned long int nb)
{
	return (ft_ullen_base(nb, 10));
}

int	ft_ullen_base(unsigned long int nb, unsigned long int base)
{
	int count;

	count = 0;
	while (nb > base)
	{
		nb /= base;
		count++;
	}
	return (count + 1);
}
