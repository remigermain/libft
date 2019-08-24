/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 16:24:32 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 18:52:01 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_inttab_del(int **ap, int size)
{
	int	count;

	count = 0;
	while (ap && count < size)
		ft_memdel((void**)&(ap[count++]));
	if (ap)
		ft_memdel((void**)&ap);
}
