/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 17:51:08 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 18:58:47 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		count;
	char	*new;

	count = 0;
	if (!s)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len-- > 0)
	{
		new[count] = s[count + start];
		count++;
	}
	new[count] = '\0';
	return (new);
}
