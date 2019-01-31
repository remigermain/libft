/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_trjoin.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 17:55:10 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 18:58:16 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		count;
	int		count_2;
	int		len;
	char	*new;

	count = 0;
	count_2 = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s1[count] != '\0')
	{
		new[count] = s1[count];
		count++;
	}
	while (s2[count_2] != '\0')
		new[count++] = s2[count_2++];
	new[len] = '\0';
	return (new);
}
