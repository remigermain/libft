/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:38:22 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 19:49:15 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	strlen_perc(const char *str, size_t j)
{
	while (str[j] != '\0' && str[j] != '%')
		j++;
	return (j);
}

static int		ftprintf_base(char *str, t_pf *lst, size_t i, size_t j)
{
	va_copy(lst->va_copy, lst->va_lst);
	while (str[i] != '\0')
	{
		j = strlen_perc(str + i, 0);
		put_buff(lst, str + i, j, 0);
		if (str[i + j] == '%')
			i += find_conv(lst, (str + i + j), 0);
		i += j;
	}
	va_end(lst->va_lst);
	va_end(lst->va_copy);
	return (lst->count + lst->buff_count);
}

int				ft_sprintf(UCHAR **dest, const char *format, ...)
{
	t_pf	*lst;
	int		i;

	lst = lst_init();
	va_start(lst->va_lst, format);
	i = ftprintf_base((char*)format, lst, 0, 0);
	convert_buff(lst, NULL, 0);
	*dest = lst->str;
	return (i);
}

int				ft_dprintf(int fd, const char *format, ...)
{
	t_pf	*lst;
	int		i;

	lst = lst_init();
	va_start(lst->va_lst, format);
	i = ftprintf_base((char*)format, lst, 0, 0);
	if (lst->count != 0)
		write(fd, lst->str, lst->count);
	if (lst->buff_count != 0)
		write(fd, lst->buff, lst->buff_count);
	if (lst->str != NULL)
		free(lst->str);
	free(lst->str);
	free(lst);
	return (i);
}

int				ft_printf(const char *format, ...)
{
	t_pf	*lst;
	int		i;

	lst = lst_init();
	va_start(lst->va_lst, format);
	i = ftprintf_base((char*)format, lst, 0, 0);
	if (lst->count != 0)
		write(1, lst->str, lst->count);
	if (lst->buff_count != 0)
		write(1, lst->buff, lst->buff_count);
	if (lst->str != NULL)
		free(lst->str);
	free(lst);
	return (i);
}
