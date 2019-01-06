/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv_double.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:38:32 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 19:38:57 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	remove_zero(t_pf *lst, ULONG nb[BUFF_FLOAT], int i, size_t index)
{
	if ((CONV == 'g' || CONV == 'G') && (index == 1 || index == 3))
	{
		while (i < PRECI)
		{
			if (nb[i] == 0)
				PRECI++;
			else
				break ;
			i++;
		}
	}
	if ((CONV == 'g' || CONV == 'G') && (index == 2 || index == 3))
	{
		i = PRECI;
		while (i > 1)
		{
			if (nb[i] == 0)
				PRECI--;
			else
				break ;
			i--;
		}
	}
}

static void	put_double(t_pf *lst, ULONG nb[BUFF_FLOAT], int i, int max)
{
	remove_zero(lst, nb, 1, 3);
	i = PRECI + 1;
	max = PRECI + 1;
	while (i > 0)
	{
		if ((nb[i] >= (BASE / 2) && i == max) ||
			(nb[i] >= BASE && i > 0))
		{
			nb[i - 1] += 1;
			nb[i] = nb[i] % BASE;
		}
		i--;
	}
	remove_zero(lst, nb, 0, 2);
	put_itoa(lst, nb[i++]);
	if (PRECI > 0)
		put_buff(lst, ".", 1, 0);
	while ((i - 1) < PRECI)
		put_itoa(lst, nb[i++]);
}

static void	assign_double(t_pf *lst, size_t i, int j)
{
	ULONG	nb[BUFF_FLOAT];
	size_t	preci;
	size_t	verif;

	preci = PRECI + 1;
	nb[i++] = lst->ul_nb;
	verif = 0;
	j = (lst->ful_nb != 0 ? ulen_base(lst->ful_nb, BASE) : 0);
	i += j;
	while (j > 0)
	{
		nb[j--] = lst->ful_nb % BASE;
		lst->ful_nb /= BASE;
	}
	while (preci > 0)
	{
		lst->fl_nb *= BASE;
		if ((int)lst->fl_nb != 0 && verif == 0)
			preci--;
		else if ((int)lst->fl_nb != 0)
			verif = 0;
		nb[i++] = (int)lst->fl_nb;
		lst->fl_nb -= (int)lst->fl_nb;
	}
	put_double(lst, nb, 0, 0);
}

static int	max_calc(t_pf *lst, int max)
{
	if (SPACE == 1 && SIGN != '+' && PSIGN == 0)
	{
		put_prefix(lst, 0, 1, 0);
		if (FIELD > 0)
			FIELD--;
		else if (FIELD < 0)
			FIELD++;
	}
	if (lst->ul_nb > 9223372036854775807)
		max = 3;
	else
	{
		if ((CONV == 'g' || CONV == 'G') && lst->ul_nb != 0)
			PRECI = (PRECI == 0 ? 0 : PRECI - 1);
		max = ulen_base(lst->ul_nb, BASE) + PRECI;
		max += (PSIGN != 0 ? 1 : 0);
		max += ((POINT == 0 || PRECI > 0) ? 1 : 0);
		if (CONV == 'e' || CONV == 'E')
			max += 2 + MAX(ulen_base(ABS(EXPONENT), BASE), 2);
	}
	return (max);
}

void		conv_double(t_pf *lst)
{
	UCHAR		*new;
	int			ret;
	int			max;
	char		c;

	max = 0;
	lst_putdouble(lst);
	max = max_calc(lst, 0);
	if (ZERO == 1)
		put_sign(lst);
	put_prefix(lst, max, FIELD, ZERO);
	if (ZERO == 0)
		put_sign(lst);
	if (lst->ul_nb > 9223372036854775807)
		put_buff(lst, ft_ustrdup((UCHAR*)("nan")), 3, 1);
	else
		assign_double(lst, 0, 0);
	if (CONV == 'e' || CONV == 'E')
	{
		c = (MAJ == 1 ? 'E' : 'e');
		ret = ft_sprintf(&new, "%c%+.2d", c, EXPONENT);
		put_buff(lst, new, ret, 1);
	}
}
