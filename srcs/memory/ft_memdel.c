/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:34:30 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 19:06:20 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdeltab(char **ap)
{
	int count;

	count = 0;
	if (!ap)
		return ;
	while (ap[count])
	{
		free(ap[count]);
		ap[count++] = NULL;
	}
	free(ap);
}

void	ft_memdel(void **ap)
{
	int count;

	count = 0;
	if (!ap)
		return ;
	while (ap[count])
	{
		free(ap[count]);
		ap[count] = NULL;
	}
}
