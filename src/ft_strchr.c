/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchar.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 18:06:43 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 18:36:14 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		locat;
	int		count;
	char	*dest;

	locat = 0;
	count = 0;
	dest = (char*)s;
	while (dest[count] != '\0')
	{
		if (dest[count] == (char)c)
			return (dest + count);
		count++;
	}
	if (dest[count] == (char)c)
		return (dest + count);
	return (NULL);
}
