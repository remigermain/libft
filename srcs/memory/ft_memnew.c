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

void    *ft_memnew(void *ptr, size_t len)
{
    void    *new;

    if ((new = ft_memalloc(len)))
        ft_memcpy(new, ptr, len);
    return (new);
}