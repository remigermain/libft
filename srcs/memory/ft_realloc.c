/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 16:24:32 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 18:52:01 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void    *ft_realloc(void *ptr, size_t len)
{
    void    *new;
    int     i;

    if ((new = ft_memalloc(len)))
    {
        i = -1;
        while (((unsigned char*)ptr)[++i])
            ((unsigned char*)new)[i] = ((unsigned char*)ptr)[i];
    }
    ft_memdel(&ptr);
    return (new);
}