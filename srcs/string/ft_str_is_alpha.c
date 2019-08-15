/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_alpha.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/06 11:57:31 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 15:01:38 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_alpha(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		if (!ft_isalpha(str[i]))
			return (FALSE);
	return (TRUE);
}
