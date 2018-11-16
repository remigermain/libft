/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printtab.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 13:42:29 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 11:42:33 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_printtab(char **tab)
{
	int count1;

	count1 = 0;
	while (tab[count1] != NULL)
	{
		ft_putstr(tab[count1]);
		if (tab[count1][ft_strlen(tab[count1]) - 1] != '\n')
			ft_putchar('\n');
		count1++;
	}
}
