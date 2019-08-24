/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/02 11:14:09 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 21:55:19 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_maxlen_tab(char **tab, int index)
{
	int a;
	int b;
	int len;

	a = 0;
	len = 0;
	while (tab[a] != NULL)
	{
		b = 0;
		while (tab[a][b] != '\0')
			b++;
		if (b > len)
			len = b;
		a++;
	}
	if (index == 1)
		return (len);
	return (a);
}
