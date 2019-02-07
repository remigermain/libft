/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_freetabi.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 10:42:01 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/01 10:57:56 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_freetabi(int **tab, size_t len)
{
	size_t	count;

	count = -1;
	if (tab == NULL)
		return ;
	while (++count < len)
		free(tab[count]);
	free(tab);
}
