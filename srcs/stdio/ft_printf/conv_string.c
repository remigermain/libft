/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv_string.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:38:13 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/20 18:11:15 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strplen(unsigned char *str, int len)
{
	int	i;
	int	max;

	i = -1;
	max = 0;
	while (str[++i] && i < len)
	{
		if (!ft_isprint(str[i]))
			max++;
		max++;
	}
	return (i);
}

static void		conv_pstr(t_pf *st, unsigned char *str, int max)
{
	int	i;
	int	c;

	i = -1;
	while (str[++i] != '\0' && i < max)
	{
		if (str[i] == '\n')
			put_buff(st, "$", 1, NO_FREE);
		if (ft_isprint(str[i]) || str[i] == '\n' || str[i] == '\t')
			put_buff(st, str + i, 1, NO_FREE);
		else
		{
			put_buff(st, "^", 1, NO_FREE);
			c = str[i] + 64;
			put_buff(st, &c, 1, NO_FREE);
		}
	}
}

static void		comv_wstr(t_pf *st, wchar_t *wstr, int max)
{
	int i;

	i = 0;
	while (((unsigned char*)wstr)[i] && i < max)
		put_buff(st, &((unsigned char*)wstr)[i++], 1, NO_FREE);
}

static void		pf_string(t_pf *st, unsigned char *str)
{
	size_t	max;

	max = ft_strlen((char*)str);
	if ((st->op.flag & LENGH_L || st->op.flag & LENGH_LL ||
			st->op.conv == 'S') && st->op.flag & PF_POINT)
		max = nlen_wchar((wchar_t*)str, st->op.preci);
	else if (st->op.flag & LENGH_L || st->op.flag & LENGH_LL ||
												st->op.conv == 'S')
		max = len_wchar((wchar_t*)str);
	else if (st->op.conv == 'r' && st->op.flag & PF_POINT)
		max = ft_strplen(str, st->op.preci);
	else if (st->op.conv == 'r')
		max = ft_strplen(str, max);
	else if (st->op.flag & PF_POINT)
		max = ft_strnlen((char*)str, st->op.preci);
	put_prefix(st, max, st->op.field, st->op.flag & PF_ZERO);
	if (st->op.flag & LENGH_L || st->op.flag & LENGH_LL ||
												st->op.conv == 'S')
		comv_wstr(st, (wchar_t*)str, max);
	else if (st->op.conv == 'r')
		conv_pstr(st, str, max);
	else
		put_buff(st, str, max, NO_FREE);
	put_prefix(st, max, -st->op.field, 0);
}

void			conv_string(t_pf *st)
{
	unsigned char	*str;

	if (LENGH_L & st->op.flag || LENGH_LL & st->op.flag || st->op.conv == 'S')
		str = (unsigned char *)va_arg(st->va_copy, wchar_t*);
	else if (st->op.conv == 'm')
		str = (unsigned char *)ft_strerror(errno);
	else
		str = (unsigned char *)va_arg(st->va_copy, char*);
	if (!str)
		str = (unsigned char *)("(null)");
	pf_string(st, str);
}
