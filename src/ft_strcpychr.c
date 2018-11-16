/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcpychr.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 14:58:16 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 15:01:23 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpychr(const char *s, int c)
{
	int count;

	count = 0;
	if (!s)
		return (NULL);
	while (s[count] != '\0' && s[count] != c)
		count++;
	return (ft_strncpy(ft_strnew(count), s, count));
}
