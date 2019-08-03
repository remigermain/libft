/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_iscntrl.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 16:41:49 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 16:46:59 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_iscntrl(char c)
{
	if ((c >= 0 && c <= 31) || c == 127)
		return (1);
	return (0);
}
