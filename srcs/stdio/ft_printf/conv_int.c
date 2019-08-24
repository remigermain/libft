/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv_int.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:24:00 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/23 19:32:19 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		get_unumber(t_pf *st)
{
	uintmax_t n;

	if (st->op.flag & LENGH_L)
		n = ((uintmax_t)va_arg(st->va_copy, unsigned long));
	else if (st->op.flag & LENGH_LL)
		n = ((uintmax_t)va_arg(st->va_copy, unsigned long long));
	else if (st->op.flag & LENGH_H)
		n = (uintmax_t)((unsigned short)va_arg(st->va_copy, int));
	else if (st->op.flag & LENGH_HH)
		n = (uintmax_t)((unsigned char)va_arg(st->va_copy, int));
	else if (st->op.flag & LENGH_J)
		n = ((uintmax_t)(va_arg(st->va_copy, uintmax_t)));
	else if (st->op.flag & LENGH_Z)
		n = ((uintmax_t)va_arg(st->va_copy, size_t));
	else
		n = ((uintmax_t)va_arg(st->va_copy, unsigned int));
	if (st->op.flag & PF_SIGN_POS)
		st->op.sign = "+";
	st->op.ul_nb = n;
}

static void		get_number(t_pf *st)
{
	intmax_t n;

	if (st->op.flag & LENGH_L)
		n = ((intmax_t)va_arg(st->va_copy, long));
	else if (st->op.flag & LENGH_LL)
		n = ((intmax_t)va_arg(st->va_copy, long long));
	else if (st->op.flag & LENGH_H)
		n = (intmax_t)((short)va_arg(st->va_copy, int));
	else if (st->op.flag & LENGH_HH)
		n = (intmax_t)((char)va_arg(st->va_copy, int));
	else if (st->op.flag & LENGH_J)
		n = ((intmax_t)(va_arg(st->va_copy, intmax_t)));
	else if (st->op.flag & LENGH_Z)
		n = ((intmax_t)va_arg(st->va_copy, size_t));
	else
		n = ((intmax_t)va_arg(st->va_copy, int));
	if (n < 0)
	{
		st->op.sign = "-";
		n = ABS(n);
	}
	else if (st->op.flag & PF_SIGN_POS)
		st->op.sign = "+";
	st->op.ul_nb = (uintmax_t)n;
}

static void		space_calc(t_pf *st, int len)
{
	if (st->op.flag & PF_HASH && ft_strchr("oO", st->op.conv) &&
		!((!st->op.ul_nb && st->op.flag & PF_HASH && st->op.preci > 0) ||
			(st->op.flag & PF_POINT && !st->op.ul_nb)))
	{
		st->op.flag |= PF_HASH;
		if (st->op.flag & PF_POINT && st->op.preci > len)
			(st->op.preci != 0 ? st->op.preci-- : st->op.preci);
		if (st->op.field < 0)
			st->op.field++;
	}
	else if (st->op.flag & PF_HASH)
		st->op.flag ^= PF_HASH;
	if (st->op.flag & PF_POINT && st->op.preci >= 0 && st->op.flag & PF_ZERO)
		st->op.flag ^= PF_ZERO;
	if (st->op.flag & PF_SPACE && !(st->op.flag & PF_SIGN_POS) &&
		!ft_strlen(st->op.sign) && ft_strchr("uU", st->op.conv))
	{
		put_prefix(st, 0, 1, 0);
		if (st->op.field > 0)
			st->op.field--;
		else if (st->op.field < 0)
			st->op.field++;
	}
}

void			conv_int(t_pf *st)
{
	int len;
	int max;

	if (ft_strchr("idD", st->op.flag))
		get_number(st);
	else
		get_unumber(st);
	if (st->op.flag & PF_POINT && !st->op.ul_nb && !st->op.preci)
		len = 0;
	else
		len = ulen_base(st->op.ul_nb, st->op.base);
	space_calc(st, len);
	max = MAX(len, st->op.preci) + ft_strlen(st->op.sign);
	if (st->op.flag & PF_ZERO)
		put_buff(st, st->op.sign, ft_strlen(st->op.sign), NO_FREE);
	put_prefix(st, max + (st->op.flag & PF_HASH),
							st->op.field, st->op.flag & PF_ZERO);
	if (!(st->op.flag & PF_ZERO))
		put_buff(st, st->op.sign, ft_strlen(st->op.sign), NO_FREE);
	put_prefix(st, 0, st->op.flag & PF_HASH, 1);
	put_prefix(st, len, st->op.preci, 1);
	if (!(st->op.flag & PF_POINT && !st->op.preci && !st->op.ul_nb))
		put_itoa(st, st->op.ul_nb);
	put_prefix(st, max, -st->op.field, 0);
}
