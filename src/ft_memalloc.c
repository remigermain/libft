/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:30:47 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 10:37:58 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int		count;
	void	*new;

	count = 0;
	if (size > 2147483647)
		return (NULL);
	if (!(new = (void*)malloc(sizeof(void) * size + 1)))
		return (NULL);
	ft_memset(new, 0, size);
	return (new);
}
