/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_createtab.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 11:44:53 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 10:52:45 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	**ft_createtab(int nb, char c)
{
	int		a;
	char	**tab;

	a = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (nb + 1))))
		return (NULL);
	while (a < nb)
	{
		if (!(tab[a] = (char*)ft_memalloc(sizeof(char*) * (nb + 1))))
		{
			ft_memdeltab(tab);
			return (NULL);
		}
		ft_memset(tab[a], c, nb);
		tab[a++][nb] = '\0';
	}
	tab[a] = NULL;
	return (tab);
}
