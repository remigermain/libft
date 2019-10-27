/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv_other.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 15:24:31 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/27 22:38:27 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conv_boucle_char(t_pf *st)
{
	char	c;
	char	*tmp;

	c = (char)va_arg(st->va_copy, int);
	if (!st->op.field)
		return ;
	if (st->op.field < 0)
		st->op.field = -st->op.field;
	if (!(tmp = (char*)malloc(st->op.field + 1)))
		ftprintf_error(st, "comv_boucle_char", 1);
	ft_memset(tmp, c, st->op.field);
	tmp[st->op.field] = 0;
	put_buff(st, tmp, st->op.field, PF_FREE);
}

static void	conv_error(t_pf *st)
{
	char *name;
	char *str;

	name = va_arg(st->va_copy, char*);
	str = va_arg(st->va_copy, char*);
	ft_putstr_fd("\n  / \\    WARNING\n / | \\    ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("\n/  o  \\\n-------\n         [", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("]     \n\n", 2);
	if (st->op.field == 1)
		exit(0);
}

void		conv_other(t_pf *st)
{
	char	*other;

	other = va_arg(st->va_copy, char*);
	if (!ft_strcmp(other, "error"))
		conv_error(st);
	else if (!ft_strcmp(other, "char"))
		conv_boucle_char(st);
}
