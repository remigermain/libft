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

int	ft_putwchar_fd(wchar_t c, int fd)
{
	unsigned char	new[4];
	int				a;

	a = 0;
	if (c <= 0x7F)
		new[a++] = c;
	else if (c <= 0x7FF)
		new[a++] = 192 + (c / 64);
	else
	{
		if (c > 0xFFFF)
		{
			new[a++] = 240 + (c / 262144);
			new[a++] = 128 + ((c / 4096) % 64);
		}
		else
			new[a++] = 224 + (c / 4096);
		new[a++] = 128 + ((c / 64) % 64);
	}
	if (c > 0x7F)
		new[a++] = 128 + (c % 64);
	write(fd, new, a);
	return (a);
}
