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

char    *ft_strpbrk(const char *s1, const char *s2)
{
    while (*s1 && ft_strchr(s2, *s1))
        s1++;
    return ((char*)s1);
}