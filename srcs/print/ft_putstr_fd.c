/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putendl_fd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:13:25 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 23:45:28 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char const *s, int fd)
{
	int count;

	if (!s)
		return (-1);
	count = ft_strlen(s);
	write(fd, s, count);
	return (count);
}
