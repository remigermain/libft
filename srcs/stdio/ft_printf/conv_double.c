/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv_double.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:38:32 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/23 19:32:08 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_exponent(t_pf *st)
{
	if (st->op.exponent)
	{
		put_buff(st, (st->op.flag & PF_MAJ ? "E" : "e"), 1, 0);
		put_buff(st, (st->op.exponent > 0 ? "+" : "-"), 1, 0);
		st->op.exponent = ABS(st->op.exponent);
		if (st->op.exponent < 10)
			put_buff(st, "0", 1, 0);
		put_itoa(st, st->op.exponent);
	}
}

void		asign_double(t_pf *st)
{
	int max;

	mod_double(st);
	max = ulen_base(st->op.ul_nb, st->op.base) + st->op.preci;
	max += ft_strlen(st->op.sign);
	if (st->op.exponent)
		max += 2 + MAX(ulen_base(st->op.exponent, 10), 2);
	if (st->op.flag & PF_ZERO)
		put_buff(st, st->op.sign, ft_strlen(st->op.sign), 0);
	put_prefix(st, max, st->op.field, st->op.flag & PF_ZERO);
	if (!(st->op.flag & PF_ZERO))
		put_buff(st, st->op.sign, ft_strlen(st->op.sign), 0);
	put_itoa(st, (uintmax_t)st->op.fl_nb);
	if (st->op.preci > 0)
		put_buff(st, ".", 1, 0);
	while (st->op.preci-- > 0)
	{
		st->op.fl_nb = ((st->op.fl_nb - (long)st->op.fl_nb) * 10.0);
		put_itoa(st, (uintmax_t)st->op.fl_nb);
	}
	print_exponent(st);
}

void		conv_double(t_pf *st)
{
	if (st->op.flag & LENGH_L_MAJ)
		st->op.fl_nb = va_arg(st->va_copy, long double);
	else
		st->op.fl_nb = (long double)va_arg(st->va_copy, double);
	if ((1.0 / 0.0) == st->op.fl_nb || (-1.0 / 0.0) == st->op.fl_nb)
		put_buff(st, (st->op.flag & PF_MAJ ? "INF" : "inf"), 3, 0);
	else if (st->op.fl_nb != st->op.fl_nb)
		put_buff(st, (st->op.flag & PF_MAJ ? "NAN" : "nan"), 3, 0);
	else
	{
		if (st->op.fl_nb < 0)
		{
			st->op.fl_nb = ABS(st->op.fl_nb);
			st->op.sign = "-";
		}
		else if (st->op.flag & PF_SIGN_POS)
			st->op.sign = "+";
		if (!(st->op.flag & PF_POINT))
			st->op.preci = 6;
		if (ft_strchr("gG", st->op.conv) && !st->op.preci)
			st->op.preci = 1;
		asign_double(st);
	}
}
