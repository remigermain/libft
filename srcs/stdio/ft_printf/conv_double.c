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

static void	remove_zero(t_pf *st, t_ulong *nb, int i, size_t index)
{
	if ((st->op.conv == 'g' || st->op.conv == 'G') && (index == 1 || index == 3))
	{
		while (i < st->op.preci && !nb[i++])
			st->op.preci++;
	}
	if ((st->op.conv == 'g' || st->op.conv == 'G') && (index == 2 || index == 3))
	{
		i = st->op.preci;
		while (i > 1 && nb[i--])
			st->op.preci--;
	}
}

static void	roundup_double(t_pf *st, t_ulong *nb, int i, int max)
{
	remove_zero(st, nb, 1, 3);
	i = st->op.preci + 1;
	max = st->op.preci + 1;
	while (i > 0)
	{
		if ((nb[i] >= (t_ulong)(st->op.base / 2) && i == max) ||
			(nb[i] >= (t_ulong)st->op.base && i > 0))
		{
			nb[i - 1] += 1;
			nb[i] = nb[i] % st->op.base;
		}
		i--;
	}
	remove_zero(st, nb, 1, 2);
}

static void	assign_double(t_pf *st, t_ulong *nb, size_t i, int j)
{
	int		preci;

	preci = st->op.preci + 1;
	nb[i++] = st->op.ul_nb;
	j = (st->op.ful_nb != 0 ? ulen_base(st->op.ful_nb, st->op.base) : 0);
	i += j;
	while (j > 0)
	{
		nb[j--] = st->op.ful_nb % st->op.base;
		st->op.ful_nb /= st->op.base;
	}
	while (preci > 0)
	{
		st->op.fl_nb *= st->op.base;
		nb[i++] = (int)st->op.fl_nb;
		st->op.fl_nb -= (int)st->op.fl_nb;
		preci--;
	}
	roundup_double(st, nb, 0, 0);
}

static int	max_calc(t_pf *st, int max)
{
	if (PF_SPACE(st->op.flag) == 1 && st->op.sign[0] != '+' && ft_strlen(st->op.sign) == 0)
	{
		put_prefix(st, 0, 1, 0);
		if (st->op.field > 0)
			st->op.field--;
		else if (st->op.field < 0)
			st->op.field++;
	}
	max = ulen_base(st->op.ul_nb, st->op.base) + st->op.preci;
	max += ft_strlen(st->op.sign);
	if (!((st->op.conv == 'g' || st->op.conv == 'G') && st->op.preci == 0))
		max += ((PF_POINT(st->op.flag) == 0 || st->op.preci > 0) ? 1 : 0);
	if (st->op.conv == 'e' || st->op.conv == 'E' || ((st->op.conv == 'g' || st->op.conv == 'G') &&
				st->op.preci != 0 && (st->op.exponent < -4 || st->op.exponent >= st->op.preci)))
		max += 2 + MAX(ulen_base(ABS(st->op.exponent), st->op.base), 2);
	return (max);
}

void		conv_double(t_pf *st, t_ulong *nb, int i)
{
	unsigned char	*new;
	int				max;

	max = 0;
	if ((st->op.conv == 'g' || st->op.conv == 'G') && PF_POINT(st->op.flag) == 0)
		st->op.preci -= ulen_base(st->op.ul_nb, st->op.base);
	assign_double(st, nb, 0, 0);
	max = max_calc(st, 0);
	if (PF_ZERO(st->op.flag) == 1)
		put_buff(st, st->op.sign, ft_strlen(st->op.sign), 0);
	put_prefix(st, max, st->op.field, PF_ZERO(st->op.flag));
	if (!PF_ZERO(st->op.flag) == 0)
		put_buff(st, st->op.sign, ft_strlen(st->op.sign), 0);
	put_itoa(st, nb[i++]);
	if (st->op.preci > 0)
		put_buff(st, ".", 1, 0);
	while ((i - 1) < st->op.preci)
		put_itoa(st, nb[i++]);
	if (st->op.conv == 'e' || st->op.conv == 'E' || ((st->op.conv == 'g' || st->op.conv == 'G') &&
				st->op.preci != 0 && (st->op.exponent < -4 || st->op.exponent >= st->op.preci)))
	{
		i = ft_sprintf(&new, "%c%+.2d", (MAJ == 1 ? 'E' : 'e'), st->op.exponent);
		put_buff(st, new, i, 1);
	}
}
