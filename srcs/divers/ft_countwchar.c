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

size_t	convert_wchar(unsigned char *new, wchar_t wc)
{
	size_t j;

	j = 0;
	new[j++] = ((unsigned char*)&wc)[0];
	if (wc > 0x7FF)
		new[j++] = ((unsigned char*)&wc)[1];
	if (wc > 0xFFFF)
		new[j++] = ((unsigned char*)&wc)[2];
	if (wc > 0x10FFFF)
		new[j++] = ((unsigned char*)&wc)[3];
	new[j] = '\0';
	return (j);
}
