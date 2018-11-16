/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 17:24:37 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 16:06:01 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		count;
	char	*dest;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	count = 0;
	if (!(dest = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s1[count] != '\0')
	{
		dest[count] = s1[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
