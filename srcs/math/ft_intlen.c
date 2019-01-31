/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_intlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 15:05:08 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 17:20:41 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen_base(int nb, int base)
{
	if (nb < 0)
		nb = -nb;
	return (1 + (nb >= base ? ft_intlen_base(nb / base, base) : 0));
}

int	ft_intlen(int n)
{
	return (ft_intlen_base(n, 10));
}
