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

int			ft_stprintf(char ind, const char *format, ...)
{
	static t_pf	st;
	int			i;

	va_start(st.va_lst, format);
	i = ftprintf_base((char*)format, &st, 0, 0);
	if (ind == OUT_PF && st.str_count > 0)
	{
		i += write(1, st.str, st.str_count);
		ft_memdel((void**)&(st.str));
		st.str_count = 0;
	}
	if (ind == OUT_PF && st.buff_count > 0)
	{
		i += write(1, st.buff, st.buff_count);
		st.buff_count = 0;
	}
	return (i);
}

int			ft_sprintf(t_uchar **dest, const char *format, ...)
{
	t_pf	lst;
	int		i;

	t_pf	st;
	ft_bzero(&st, sizeof(t_pf));
	va_start(st.va_lst, format);
	convert_buff(&lst, NULL, 0);
	i = ftprintf_base((char*)format, &st, 0, 0);
	*dest = lst.str;
	return (i);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	t_pf	st;

	ft_bzero(&st, sizeof(t_pf));
	va_start(st.va_lst, format);
	st.is_print = TRUE;
	st.fd = fd;
	return (ftprintf_base((char*)format, &st, 0, 0));
}


int			ft_printf(const char *format, ...)
{
	t_pf	st;

	ft_bzero(&st, sizeof(t_pf));
	va_start(st.va_lst, format);
	st.is_print = TRUE;
	st.fd = 1;
	return (ftprintf_base((char*)format, &st, 0, 0));
}
