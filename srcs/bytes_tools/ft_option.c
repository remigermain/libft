/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 18:10:38 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/31 18:26:18 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "libft.h"

static int  *get_interne_option(void)
{
    static int option = 0;

    return (&option);
}

void        add_option(int fl)
{
    int *option;

    option = get_interne_option();
    *option |= 1 << fl;
}

t_bool      exist_option(int fl)
{
    int *option;

    option = get_interne_option();
    if (*option & 1 << fl)
        return (TRUE);
    return (FALSE);
}

void        remove_option(int fl)
{
    int *option;

    option = get_interne_option();
    if (exist_option(fl))
        *option ^= 1 << fl;
}