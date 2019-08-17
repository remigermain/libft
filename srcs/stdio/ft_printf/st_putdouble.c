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

static void	remove_zero(t_pf *st)
{
	long double	nb;
	int			preci;
	int			rm;

	rm = 1;
	nb = st->op.fl_nb;
	preci = st->op.preci + 1;
	while (preci--)
	{
		if ((int)nb == 0)
			rm++;
		else
			rm = 0;
		nb = ((nb - (intmax_t)nb) * 10.0);
	}
	st->op.preci -= rm;
}

static void round_double(t_pf *st)
{
	long double round;
	int			preci;

	round = (double)(st->op.base / 2);
	preci = st->op.preci + 1;
	while (preci--)
		round /= (double)st->op.base;
	st->op.fl_nb += round;
}

static void	atapt_preci(t_pf *st)
{
	if (ft_strchr("gG", st->op.conv) && (intmax_t)st->op.fl_nb)
		st->op.preci -= ulen_base((intmax_t)st->op.fl_nb, st->op.base);
	else if (ft_strchr("gG", st->op.conv) && !(intmax_t)st->op.fl_nb)
		st->op.preci++;
	if (ft_strchr("eE", st->op.conv) && st->op.exponent < 0)
		st->op.preci += -st->op.exponent + 1;
	round_double(st);
	if (ft_strchr("gG", st->op.conv))
		remove_zero(st);
}

void mod_double(t_pf *st)
{
	long double nb;
	
	nb = (intmax_t)st->op.fl_nb;
	if ((ft_strchr("gG", st->op.conv) && st->op.fl_nb >= ft_pow(st->op.base, st->op.preci)) ||
		(ft_strchr("eE", st->op.conv) && nb >= st->op.base))
	{
		while (nb > ft_pow(st->op.base, st->op.exponent))
		{
			st->op.fl_nb /= (double)st->op.base;
			st->op.exponent++;
		}
	}
	else if ((ft_strchr("gG", st->op.conv) && nb < -0.0001) ||
			(ft_strchr("eE", st->op.conv) && nb < 1.0))
	{
		while ((intmax_t)st->op.fl_nb == 0)
		{
			st->op.fl_nb *= (double)st->op.base;
			st->op.exponent--;
		}
	}
	if (st->op.flag & PF_POINT && ft_strchr("eE", st->op.conv))
		st->op.preci = MAX(6, ABS(st->op.exponent));
	atapt_preci(st);
}

