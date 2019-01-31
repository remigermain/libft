/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_putdouble.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:38:43 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/31 16:35:43 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	lst_putdouble_pos(t_pf *lst, long double nb, ULONG coef)
{
	while (((coef * BASE) < (ULONG)nb) && nb != 0)
	{
		coef *= BASE;
		EXPONENT++;
	}
	lst->ul_nb = (ULONG)nb / coef;
	lst->ful_nb = nb - (lst->ul_nb * coef);
	lst->fl_nb = nb - (ULONG)nb;
}

static void	lst_putdouble_neg(t_pf *lst, long double nb, ULONG coef)
{
	while (((ULONG)(coef * nb) <= 0) && nb != 0)
	{
		coef *= BASE;
		EXPONENT--;
	}
	lst->ul_nb = (ULONG)(nb * coef);
	lst->fl_nb = (nb * coef) - lst->ul_nb;
}

static void	lst_putdouble_main(t_pf *lst, long double nb)
{
	if (nb < 0)
	{
		nb = -nb;
		PSIGN = "-";
	}
	else if (nb >= 0 && SIGN == '+')
		PSIGN = "+";
	if (POINT == 0)
		PRECI = 6;
	if ((CONV == 'f' || CONV == 'F') || (CONV == 'g' &&
			PRECI >= ulen_base(nb, BASE)))
	{
		lst->ul_nb = (ULONG)nb;
		lst->fl_nb = nb - (ULONG)nb;
	}
	else if ((ULONG)nb > 0)
		lst_putdouble_pos(lst, nb, 1);
	else
		lst_putdouble_neg(lst, nb, 1);
	if (POINT == 0 && (CONV == 'e' || CONV == 'E'))
		PRECI = MAX(6, ABS(EXPONENT));
}

void		lst_putdouble(t_pf *lst)
{
	long double	nb;
	ULONG		*tab_nb;

	if (LENGHT == 100000)
		nb = va_arg(lst->va_copy, long double);
	else
		nb = (long double)va_arg(lst->va_copy, double);
	if ((1.0 / 0.0) == nb || (-1.0 / 0.0) == nb)
		put_buff(lst, (MAJ == 1 ? "INF" : "inf"), 3, 0);
	else if (nb != nb)
		put_buff(lst, (MAJ == 1 ? "NAN" : "nan"), 3, 0);
	else
	{
		lst_putdouble_main(lst, nb);
		if (!(tab_nb = (ULONG*)ft_memalloc(sizeof(ULONG) *
						(PRECI + 2 + ulen_base(lst->ul_nb, BASE)))))
			ERROR(lst, "lst_putdouble", 1);
		conv_double(lst, tab_nb, 0);
	}
}
