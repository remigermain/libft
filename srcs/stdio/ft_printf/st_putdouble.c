/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   st_putdouble.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:38:43 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/23 19:33:18 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	st_putdouble_pos(t_pf *st, long double nb, t_ulong coef)
{
	while (((coef * st->op.base) < (t_ulong)nb) && nb != 0)
	{
		coef *= st->op.base;
		st->op.exponent++;
	}
	st->op.ul_nb = (t_ulong)nb / coef;
	st->op.ful_nb = nb - (st->op.ul_nb * coef);
	st->op.fl_nb = nb - (t_ulong)nb;
}

static void	st_putdouble_neg(t_pf *st, long double nb, t_ulong coef)
{
	while (((t_ulong)(coef * nb) <= 0) && nb != 0)
	{
		coef *= st->op.base;
		st->op.exponent--;
	}
	st->op.ul_nb = (t_ulong)(nb * coef);
	st->op.fl_nb = (nb * coef) - st->op.ul_nb;
}

static void	st_putdouble_main(t_pf *st, long double nb)
{
	if (nb < 0)
	{
		nb = -nb;
		st->op.sign = "-";
	}
	else if (nb >= 0 && PF_SIGN_POS(st->op.flag))
		st->op.sign = "+";
	if (PF_POINT(st->op.flag) == 0)
		st->op.preci = 6;
	if ((st->op.conv == 'f' || st->op.conv == 'F') || (st->op.conv == 'g' &&
			st->op.preci >= ulen_base(nb, st->op.base)))
	{
		st->op.ul_nb = (t_ulong)nb;
		st->op.fl_nb = nb - (t_ulong)nb;
	}
	else if ((t_ulong)nb > 0)
		st_putdouble_pos(st, nb, 1);
	else
		st_putdouble_neg(st, nb, 1);
	if (PF_POINT(st->op.flag) == 0 && (st->op.conv == 'e' || st->op.conv == 'E'))
		st->op.preci = MAX(6, ABS(st->op.exponent));
}

void		st_putdouble(t_pf *st)
{
	long double	nb;
	t_ulong		*tab_nb;
	
	if (LENGH_L_MAJ(st->op.flag))
		nb = va_arg(st->va_copy, long double);
	else
		nb = (long double)va_arg(st->va_copy, double);
	if ((1.0 / 0.0) == nb || (-1.0 / 0.0) == nb)
		put_buff(st, (PF_MAJ(st->op.flag) ? "INF" : "inf"), 3, 0);
	else if (nb != nb)
		put_buff(st, (PF_MAJ(st->op.flag) ? "NAN" : "nan"), 3, 0);
	else
	{
		st_putdouble_main(st, nb);
		if (!(tab_nb = (t_ulong*)ft_memalloc(sizeof(t_ulong) *
				(st->op.preci + 2 + ulen_base(st->op.ul_nb, st->op.base)))))
			ftprintf_error(st, "st_putdouble", 1);
		conv_double(st, tab_nb, 0);
	}
}
