/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:24:04 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 16:11:32 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_cal(char *str, long n, int len, int base, int maj)
{
	int pos;

	if (maj == 1)
		pos = 55;
	else
		pos = 87;
	if ((n % base) < 10)
		str[len--] = (char)(n % base) + 48;
	else
		str[len--] = (char)(n % base) + pos;
	while (n >= base)
	{
		n = n / base;
		if ((n % base) < 10)
			str[len--] = (char)(n % base) + 48;
		else
			str[len--] = (char)(n % base) + pos;
	}
	return (str);
}

char		*ft_itoa_base(long nb, int base, int maj)
{
	int		len;
	char	*str;
	long	n;

	n = (long)nb;
	if (base < 2 || base > 16)
		return (NULL);
	if (n < 0 && base != 10)
		n = -n;
	len = (int)ft_intlen_base((long)n, base);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	if (n < 0 && base == 10)
	{
		str[0] = '-';
		n = n * -1;
	}
	len--;
	return (ft_itoa_cal(str, n, len, base, maj));
}
