/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/02 11:14:09 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 21:55:19 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnstrw_fd(wchar_t const *s, int len, int fd)
{
	int count;
	int	len2;

	count = 0;
	len2 = 0;
	if (!s)
		return (-1);
	while (s[count] != '\0' && len2 < len)
		len2 += ft_putwchar_fd(s[count++], fd);
	return (len2);
}
