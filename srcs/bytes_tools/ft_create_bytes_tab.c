/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv_double.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 15:38:32 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/23 19:32:08 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	calcul_malloc(size_t size)
{
	size_t len;

	len = size / 8;
	if (size % 8)
		len++;
	return (len);
}

unsigned char	**ft_create_bytes_tab(size_t size)
{
	unsigned char	**tab;
	size_t			len;
	size_t			i;

	i = 0;
	len = calcul_malloc(size);
	if (!len)
		return (NULL);
	if (!(tab = (unsigned char**)ft_memalloc(sizeof(unsigned char*) * len)))
		return (NULL);
	while (i < len)
	{
		if (!(tab[i++] = (unsigned char*)ft_memalloc(
								sizeof(unsigned char) * len)))
		{
			ft_tabdel((char ***)&tab);
			return (NULL);
		}
	}
	return (tab);
}
