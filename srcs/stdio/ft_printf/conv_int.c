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

static void	st_putnb_unb(t_pf *st)
{
	if (LENGH_H(st->op.flag) && st->op.conv != 'O' && st->op.conv != 'U'
			&& st->op.conv != 'D')
		st->op.ul_nb = (unsigned short)va_arg(st->va_copy, t_ulong);
	else if (LENGH_HH(st->op.flag) && st->op.conv != 'O' && st->op.conv != 'U'
			&& st->op.conv != 'D')
		st->op.ul_nb = (unsigned char)va_arg(st->va_copy, t_ulong);
	else if (LENGH_L(st->op.flag))
		st->op.ul_nb = va_arg(st->va_copy, long);
	else if (LENGH_LL(st->op.flag))
		st->op.ul_nb = va_arg(st->va_copy, t_ulong);
	else if (LENGH_J(st->op.flag))
		st->op.ul_nb = va_arg(st->va_copy, INTMAX_T);
	else if (LENGH_Z(st->op.flag))
		st->op.ul_nb = va_arg(st->va_copy, size_t);
	else if (st->op.conv == 'o' || st->op.conv == 'x' || st->op.conv == 'X' ||
			st->op.conv == 'u' || st->op.conv == 'X')
		st->op.ul_nb = va_arg(st->va_copy, unsigned int);
	else
		st->op.ul_nb = va_arg(st->va_copy, t_ulong);
	if (PF_SIGN_POS(st->op.flag) && (st->op.conv == 'd' || st->op.conv == 'D' ||
				st->op.conv == 'I' || st->op.conv == 'i'))
		st->op.sign = "+";
}

static void	st_putnb_snb(t_pf *st)
{
	long nb_tmp;

	if (LENGH_H(st->op.flag))
		nb_tmp = (short)va_arg(st->va_copy, int);
	else if (LENGH_HH(st->op.flag))
		nb_tmp = (char)va_arg(st->va_copy, int);
	else if (LENGH_L(st->op.flag))
		nb_tmp = va_arg(st->va_copy, long);
	else if (LENGH_LL(st->op.flag))
		nb_tmp = va_arg(st->va_copy, long);
	else if (LENGH_J(st->op.flag))
		nb_tmp = va_arg(st->va_copy, INTMAX_T);
	else if (LENGH_Z(st->op.flag))
		nb_tmp = va_arg(st->va_copy, size_t);
	else if (st->op.conv == 'D' || st->op.conv == 'I' || LENGH_NO(st->op.flag))
		nb_tmp = va_arg(st->va_copy, long);
	else
		nb_tmp = va_arg(st->va_copy, int);
	if (PF_SIGN_POS(st->op.flag) && nb_tmp >= 0 && (st->op.conv == 'd' ||
				st->op.conv == 'D' || st->op.conv == 'I' || st->op.conv == 'i'))
		st->op.sign = "+";
	else if (nb_tmp < 0)
		st->op.sign = "-";
	st->op.ul_nb = (nb_tmp < 0 ? -nb_tmp : nb_tmp);
}

void		st_putint(t_pf *st)
{
	if (st->op.conv == 'd' || (st->op.conv == 'i') ||
			(st->op.conv == 'D' && !LENGH_NO(st->op.flag)))
		st_putnb_snb(st);
	else
		st_putnb_unb(st);
	if (st->op.conv == 'p' || ((st->op.conv == 'x' || st->op.conv == 'X')
			&& PF_HASH(st->op.flag) && st->op.ul_nb != 0))
		st->op.sign = (PF_MAJ(st->op.flag) ? "0X" : "0x");
}

static void	ft_spacecalc(t_pf *st, int len)
{
	if ((PF_HASH(st->op.flag) && (st->op.conv == 'o' || st->op.conv == 'O')) &&
		!((st->op.ul_nb == 0 && PF_HASH(st->op.flag) == 1 && st->op.preci > 0) ||
			(PF_POINT(st->op.flag) && st->op.ul_nb == 0)))
	{
		st->op.flag |= (1 << HASH);
		if ((PF_POINT(st->op.flag) == 1 && st->op.preci > len))
			st->op.preci = (st->op.preci != 0 ? st->op.preci - 1 : st->op.preci);
		if (st->op.field < 0)
			st->op.field++;
	}
	else if (PF_HASH(st->op.flag))
		st->op.flag ^= (1 << HASH);
	if (PF_POINT(st->op.flag) && st->op.preci >= 0)
		st->op.flag ^= (1 << ZERO);
	if (PF_SPACE(st->op.flag) && !PF_SIGN_POS(st->op.flag) && !ft_strlen(st->op.sign)
			&& st->op.conv != 'u' && st->op.conv != 'U')
	{
		put_prefix(st, 0, 1, 0);
		if (st->op.field > 0)
			st->op.field--;
		else if (st->op.field < 0)
			st->op.field++;
	}
}

void		conv_int(t_pf *st)
{
	int len;
	int max;

	st_putint(st);
	len = ulen_base(st->op.ul_nb, st->op.base);
	if (st->op.ul_nb == 0 && PF_POINT(st->op.flag) && st->op.preci == 0)
		len = 0;
	ft_spacecalc(st, len);
	max = MAX(len, st->op.preci) + ft_strlen(st->op.sign);
	if (PF_ZERO(st->op.flag))
		put_buff(st, st->op.sign, ft_strlen(st->op.sign), 0);
	put_prefix(st, max + PF_HASH(st->op.flag), st->op.field, ZERO);
	if (!PF_ZERO(st->op.flag))
		put_buff(st, st->op.sign, ft_strlen(st->op.sign), 0);
	put_prefix(st, 0, PF_HASH(st->op.flag), 1);
	put_prefix(st, len, st->op.preci, 1);
	if (!(PF_POINT(st->op.flag) && st->op.preci == 0 && st->op.ul_nb == 0))
		put_itoa(st, st->op.ul_nb);
	put_prefix(st, max, -st->op.field, 0);
}
