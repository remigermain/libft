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

int		len_wchar(wchar_t *str)
{
	size_t	count;
	size_t	a;

	count = 0;
	a = 0;
	while (str[a] != '\0')
		count += len_wchar_single(str[a++]);
	return (count);
}
