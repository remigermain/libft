/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_countwchar.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/19 21:57:13 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 15:57:51 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		nlen_wchar(wchar_t *str, size_t len)
{
	size_t	count;
	size_t	count2;
	size_t	a;

	count = 0;
	count2 = 0;
	a = 0;
	while (str[a] != '\0')
	{
		count = len_wchar_single(str[a]);
		if ((count2 + count) > len)
			return (count2);
		else if ((count2 + count) == len)
			return (count2 + count);
		else
			count2 += count;
		a++;
	}
	return (count2);
}