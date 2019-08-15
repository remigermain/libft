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

void	convert_wchar(unsigned char **new, wchar_t wc, size_t *i)
{
	(*new)[(*i)++] = ((unsigned char*)wc)[0];
	if (wc > 0x7FF)
		(*new)[(*i)++] = ((unsigned char*)wc)[1];
	if (wc > 0xFFFF)
		(*new)[(*i)++] = ((unsigned char*)wc)[2];
	if (wc > 0x10FFFF)
		(*new)[(*i)++] = ((unsigned char*)wc)[3];
	(*new)[(*i)] = '\0';
}
