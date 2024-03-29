/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 18:10:38 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/24 17:28:40 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse_bytes(void *bytes, size_t size)
{
	unsigned char	tmp;
	int				mem;
	size_t			divide;

	mem = size;
	if (size == 0)
		return ;
	divide = size / 2;
	while (size-- > divide)
	{
		tmp = ((unsigned char *)bytes)[size];
		((unsigned char *)bytes)[size] = ((unsigned char *)bytes)[mem - size];
		((unsigned char *)bytes)[mem - size] = tmp;
	}
}
