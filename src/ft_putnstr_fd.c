/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 16:24:32 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 19:51:19 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnstr_fd(char const *str, int fd, int len)
{
	int count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0' && count < len)
		ft_putchar_fd(str[count++], fd);
	return (count);
}
