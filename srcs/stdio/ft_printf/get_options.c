/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_putoption.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:26:12 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/21 03:03:02 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void st_base(t_pf *st)
{
	if (BASE_16(st->op.conv))
		st->op.base = 16;
	else if (BASE_8(st->op.conv))
		st->op.base = 8;
	else if (BASE_2(st->op.conv))
		st->op.base = 2;
	else
		st->op.base = 10;
	if (ft_isuppercase(st->op.conv))
		st->op.flag |= (1 << MAJ);
	st->op.sign = "";
}

static int	st_putconv(t_pf *st, char *str, int count)
{
	if (str[count] == 'h')
		st->op.flag |= (1 << CAST_H);
	else if (str[count] == 'l' && !LENGH_L(st->op.flag))
		st->op.flag |= (1 << CAST_L);
	else if (str[count] == 'l')
		st->op.flag |= (1 << CAST_LL);
	else if (str[count] == 'j')
		st->op.flag |= (1 << CAST_J);
	else if (str[count] == 'z')
		st->op.flag |= (1 << CAST_Z);
	else if (str[count] == 'L')
		st->op.flag |= (1 << CAST_L_MAJ);
	else
		st->op.conv = str[count];
	return (++count);
}

static int	st_putdigit(t_pf *st, char *str, int count)
{
	int nb_tmp;

	nb_tmp = 0;
	if (str[count] == '+' && (++count))
		st->op.flag |= (1 << SIGN_POS);
	else if (str[count] == '-' && (++count))
		st->op.flag |= (1 << SIGN_NEG);
	else
	{
		nb_tmp = ft_atoi(str + count);
		count += ft_spantype(str + count, ft_isdigit);
		if (str[count] == '$')
		{
			va_end(st->va_copy);
			va_copy(st->va_copy, st->va_lst);
			while (--nb_tmp >= 0)
				va_arg(st->va_copy, int);
		}
		if ((str[count] == '*' || str[count] == '$') && (++count))
			nb_tmp = va_arg(st->va_copy, int);
		if (POINT_PF(st->op.flag))
			st->op.preci = nb_tmp;
		else
			st->op.field = nb_tmp;
	}
	return (count);
}

int			get_option(t_pf *st, char *str, int count)
{
	ft_bzero(&(st->op), sizeof(t_pf_flag));
	while (str[count] && !st->op.conv)
	{
		if (str[count] == '.' && (++count))
			st->op.flag |= (1 << POINT);
		else if (str[count] == '0' && (++count))
			st->op.flag |= (1 << ZERO);
		else if (str[count] == '\'' && (++count))
			st->op.flag |= (1 << LOCAL);
		else if (str[count] == '#' && (++count))
			st->op.flag |= (1 << HASH);
		else if (str[count] == ' ' && (++count))
			st->op.flag |= (1 << SPACE);
		else if (ft_isdigit(str[count]) || str[count] == '+' ||
				str[count] == '-' || str[count] == '*' || str[count] == '$')
			count = st_putdigit(st, str, count);
		else
			count = st_putconv(st, str, count);
	}
	st_base(st);
	return (count);
}
