/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 15:09:25 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/07 02:32:41 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			find_conv(t_pf *lst, char *str, int ret)
{
	ret = lst_putoption(lst, str, 1);
	if (CONV == 'n')
		*va_arg(lst->va_copy, int*) = (lst->count + lst->buff_count);
	else if (CONV == 'f' || CONV == 'F' || CONV == 'e' || CONV == 'E' ||
			CONV == 'g' || CONV == 'G')
		lst_putdouble(lst);
	else if (CONV == 't' && str[ret] == 's')
		ret += conv_tabstring(lst);
	else if (CONV == 's' || CONV == 'S' || CONV == 'r')
		conv_string(lst);
	else if (CONV == 'd' || CONV == 'i' || CONV == 'D' || CONV == 'x' ||
			CONV == 'X' || CONV == 'o' || CONV == 'O' || CONV == 'u' ||
			CONV == 'U' || CONV == 'p' || CONV == 'b' || CONV == 'B')
		conv_int(lst);
	else if (CONV == '@')
		conv_other(lst);
	else if (CONV == '{')
		ret += conv_color(lst, str + ret);
	else if (CONV != 0)
		conv_char(lst);
	return (ret);
}
