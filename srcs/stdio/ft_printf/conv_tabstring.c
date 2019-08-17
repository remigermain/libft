/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv_tabstring.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:39:28 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/23 19:34:07 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_puttab_back(t_pf *st, int len, int b)
{
	int			llen;
	int			ret;
	t_uchar		*str;

	llen = ulen_base(len, 10) + st->op.preci;
	llen -= (((len % 10) == 0) ? 1 : 0);
	if (st->op.preci == 1)
	{
		ret = ft_sprintf(&str, " %{T_BLUE}%*s%{T_EOC} |", llen, "\\0");
		put_buff(st, str, ret, 1);
	}
	while ((b + st->op.preci) < len)
	{
		ret = ft_sprintf(&str, " %*C |", llen, ' ');
		put_buff(st, str, ret, 1);
		b++;
	}
}

static void	pf_puttab_end(t_pf *st, int larg, int max)
{
	t_uchar	*str;
	int		ret;

	if (st->op.preci == 1)
	{
		ret = ft_sprintf(&str, "\n[%.*d]| %{T_BLUE}$NULL%{T_EOC}", larg, max);
		put_buff(st, str, ret, 1);
	}
}

static void	pf_puttab(t_pf *st, char **tab, int len, int larg)
{
	t_uchar		*str;
	int			llen;
	int			a;
	int			b;
	int			ret;

	llen = ulen_base(len, 10) + st->op.preci;
	llen -= (((len % 10) == 0) ? 1 : 0);
	a = 0;
	while (tab[a] != NULL)
	{
		b = 0;
		ret = ft_sprintf(&str, "\n[%.*d]|", larg, a);
		put_buff(st, str, ret, 1);
		while (tab[a][b] != '\0')
		{
			ret = ft_sprintf(&str, " %*C |", llen, tab[a][b]);
			put_buff(st, str, ret, 1);
			b++;
		}
		pf_puttab_back(st, len, b);
		a++;
	}
	pf_puttab_end(st, larg, ft_maxlen_tab(tab, 0));
}

static void	pf_doublestring(t_pf *st, char **tab, int len, int larg)
{
	t_uchar		*str;
	int			b;
	int			ret;
	int			llen;

	b = 0;
	len = ft_maxlen_tab(tab, 1) + st->op.preci;
	larg = ft_maxlen_tab(tab, 0);
	larg = ulen_base(MIN(larg - 1, larg), 10);
	llen = ulen_base(len, 10) + st->op.preci;
	llen -= (((len % 10) == 0) ? 1 : 0);
	ret = ft_sprintf(&str, "%*.c |", larg + 1, ' ');
	put_buff(st, str, ret, 1);
	while (b < len)
	{
		ret = ft_sprintf(&str, "[%.*d]|", llen, b++);
		put_buff(st, str, ret, 1);
	}
	pf_puttab(st, tab, len, larg);
}

int			conv_tabstring(t_pf *st)
{
	char		**tab;

	tab = va_arg(st->va_copy, char**);
	if (tab == NULL)
		put_buff(st, "(tab null)", 10, 0);
	else
	{
		if (st->op.flag & PF_POINT)
			pf_doublestring(st, tab, 0, 0);
		else
		{
			while (*tab != NULL)
			{
				put_buff(st, (t_uchar*)*tab, ft_strlen(*tab), 0);
				if (*tab++ != NULL)
					put_buff(st, "\n", 1, 0);
			}
		}
	}
	return (1);
}
