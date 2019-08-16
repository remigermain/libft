/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 19:19:53 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/26 11:02:34 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strtok(char *s1, const char *delim)
{
    static char *str = NULL;

    if (s1)
        str = s1;
    if (!str)
        return (NULL);
    while (*str && ft_strchr(delim, *str))
        str++;
    while (str && !ft_strchr(delim, *str))
        str++;
    if (!*str)
        return (NULL);
    return (str);
}