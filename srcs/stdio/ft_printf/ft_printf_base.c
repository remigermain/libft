/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:38:22 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 18:50:27 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conv_nlen(t_pf *st)
{
	int	*tmp;

	tmp = va_arg(st->va_copy, int*);
	if (tmp != NULL)
		*tmp = (st->str_count + st->buff_count);
}

static int	find_conv(t_pf *st, char *str, int ret)
{
	ret = get_option(st, str, 1);
	if (st->op.conv == 'n')
		conv_nlen(st);
	else if (ft_strchr("fFeEgGaA", st->op.conv))
		conv_double(st);
	else if (st->op.conv == 't' && str[ret] == 's')
		ret += conv_tabstring(st);
	else if (ft_strchr("sSrm", st->op.conv))
		conv_string(st);
	else if (ft_strchr("diDxXoOuUpbB", st->op.conv))
		conv_int(st);
	else if (st->op.conv == '@')
		conv_other(st);
	else if (st->op.conv != 0)
		conv_char(st);
	return (ret);
}

int			ftprintf_base(char *str, t_pf *st, size_t i, size_t j)
{
	va_copy(st->va_copy, st->va_lst);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] != '%')
			j++;
		put_buff(st, str + i, j, NO_FREE);
		if (str[i + j] == '%')
			i += find_conv(st, (str + i + j), 0);
		i += j;
	}
	va_end(st->va_lst);
	va_end(st->va_copy);
	if (st->is_print)
	{
		if (st->str_count != 0)
			write(st->fd, st->str, st->str_count);
		if (st->buff_count != 0)
			write(st->fd, st->buff, st->buff_count);
		if (st->str != NULL)
			ft_memdel((void**)&(st->str));
	}
	return (st->str_count + st->buff_count);
}
