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

void	ft_printtab_fd(char **tab, int fd)
{
	int	count1;

	count1 = 0;
	while (tab[count1] != NULL)
	{
		ft_putstr_fd(tab[count1], fd);
		if (tab[count1][ft_strlen(tab[count1]) - 1] != '\n')
			ft_putchar_fd('\n', fd);
		count1++;
	}
}
