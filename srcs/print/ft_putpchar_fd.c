/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 16:24:32 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 18:52:01 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_putpchar_fd(char c, int fd)
{
	if (ft_isprint(c) || (c >= 9 && c <= 13))
		return (ft_putchar_fd(c, fd));
	else
	{
		ft_putchar_fd('^', fd);
		ft_putchar_fd(c + 64, fd);
		return (2);
	}
}
