/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv_char.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:37:51 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/23 19:31:56 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void			conv_char(t_pf *st)
{
	size_t	max;
	int		c;

	if (st->op.conv != 'c' && st->op.conv != 'C')
		c = st->op.conv;
	else
		c = va_arg(st->va_copy, int);
	if (LENGH_L(st->op.flag) || st->op.conv == 'S')
		max = len_wchar_single((wchar_t)c);
	else
		max = 1;
	put_prefix(st, max, st->op.field, PF_ZERO(st->op.flag));
	put_buff(st, &c, max, NO_FREE);
	put_prefix(st, max, -st->op.field, 0);
}
