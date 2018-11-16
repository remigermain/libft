/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_createtab.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 11:44:53 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 12:01:08 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	**ft_createtab(int nb, char c)
{
	char	**tab;
	int		a;
	int		b;

	a = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (nb + 1))))
		return (NULL);
	while (a < nb)
	{
		b = 0;
		if (!(tab[a] = malloc(sizeof(char*) * (nb + 1))))
			return (NULL);
		while (b < nb)
			tab[a][b++] = c;
		tab[a][b] = '\0';
		a++;
	}
	tab[a] = NULL;
	return (tab);
}
