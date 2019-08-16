/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcapitalize.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/06 14:27:19 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 15:03:39 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcapitalize(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		if (ft_isuppercase(str[i]))
			str[i] = str[i] + 32;
	i = -1;
	while (str[++i] != '\0')
		if (i > 0 && ft_isspace(str[i - 1]) && 
				ft_isalpha(str[i]))
			str[i] = str[i] - 32;
	return (str);
}
