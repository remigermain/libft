/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv_int.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:24:00 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 19:38:04 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sign_calc(t_pf *lst)
{
	if (PSIGN == 1 || PSIGN == 2)
		return (1);
	else if (PSIGN == 3)
		return (2);
	return (0);
}

static int	ft_hashcalc(t_pf *lst, int index, int len)
{
	if (HASH == 1 && (CONV == 'o' || CONV == 'O'))
	{
		if (lst->ul_nb == 0 && POINT == 1 && PRECI > 0)
			return (0);
		if (POINT == 0 && lst->ul_nb == 0)
			return (0);
		index = 1;
		if ((POINT == 1 && PRECI > len))
		{
			if (PRECI != 0)
				PRECI--;
		}
		if (FIELD < 0)
			FIELD++;
	}
	return (index);
}

static void	ft_spacecalc(t_pf *lst)
{
	if (HASH == 1 && (CONV == 'u' || CONV == 'U'))
		HASH = 0;
	if (POINT == 1 && PRECI >= 0)
		ZERO = 0;
	if (SPACE == 1 && (CONV == 'o' || CONV == 'O' ||
				CONV == 'x' || CONV == 'X'))
		SPACE = 0;
	if (SPACE == 1 && SIGN != '+' && PSIGN == 0
			&& CONV != 'u' && CONV != 'U')
	{
		put_prefix(lst, 0, 1, 0);
		if (FIELD > 0)
			FIELD--;
		else if (FIELD < 0)
			FIELD++;
	}
}

void		conv_int(t_pf *lst)
{
	int len;
	int max;
	int sign;

	lst_putint(lst);
	len = ulen_base(lst->ul_nb, BASE);
	sign = sign_calc(lst);
	if (lst->ul_nb == 0 && POINT == 1 && PRECI == 0)
		len = 0;
	HASH = ft_hashcalc(lst, 0, len);
	ft_spacecalc(lst);
	max = MAX(len, PRECI) + sign;
	if (ZERO == 1)
		put_sign(lst);
	put_prefix(lst, max + HASH, FIELD, ZERO);
	if (ZERO == 0)
		put_sign(lst);
	put_prefix(lst, 0, HASH, 1);
	put_prefix(lst, len, PRECI, 1);
	if (!(POINT == 1 && PRECI == 0 && lst->ul_nb == 0))
		put_itoa(lst, lst->ul_nb);
	put_prefix(lst, max, -FIELD, 0);
}
