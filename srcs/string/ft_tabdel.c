/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:34:30 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/19 13:04:26 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(char **ap)
{
	size_t count;

	count = 0;
	while (ap && ap[count]))
		ft_memdel((void**)&(ap[count++]));
    if (ap)
	    ft_memdel((void**)&ap);
}
