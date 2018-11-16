/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_intlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 15:05:08 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 05:54:06 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long n)
{
	return (ft_intlen_base(n, 10));
}

int	ft_intlen2(int n)
{
	return (ft_intlen2_base(n, 10));
}

int	ft_uintlen(unsigned int n)
{
	return (ft_uintlen_base(n, 10));
}

int	ft_intlen2_base(int n, int base)
{
	int count;

	count = 0;
	if (n == -2147483648)
	{
		count++;
		n = 147483648;
	}
	if (n < 0)
		n = n * -1;
	while (n >= base)
	{
		count++;
		n = n / base;
	}
	return (count + 1);
}

int	ft_intlen_base(int n, int base)
{
	int count;

	count = 0;
	if (n < 0 && base == 10)
	{
		n = n * -1;
		count++;
	}
	while (n >= base)
	{
		count++;
		n = n / base;
	}
	return (count + 1);
}

int	ft_uintlen_base(unsigned int n, unsigned int base)
{
	int count;

	count = 0;
	while (n >= base)
	{
		count++;
		n = n / base;
	}
	return (count + 1);
}
