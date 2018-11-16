/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 17:59:00 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 15:40:09 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	len_s1;
	size_t	i;
	size_t	n;
	size_t	ret;

	len_s1 = 0;
	while (s1[len_s1] != '\0' && len_s1 < size)
		len_s1++;
	i = 0;
	if (size <= (len_s1 + 1))
		return (len_s1 + ft_strlen(s2));
	n = ft_strlen(s1);
	ret = n + ft_strlen(s2);
	while (s2[i] != '\0')
	{
		if (n < size - 1)
		{
			s1[n] = s2[i];
			n++;
		}
		i++;
	}
	s1[n] = '\0';
	return (ret);
}
