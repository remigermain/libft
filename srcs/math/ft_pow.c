/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recursive_power.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/03 16:21:54 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 17:59:14 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

double  ft_pow(double x, int y)
{
    double temp;

    if (y == 0)  
        return 1;  
    temp = ft_pow(x, y / 2);  
    if (y % 2 == 0)  
        return (temp * temp);
    else
    {  
        if (y > 0)  
            return (x * temp * temp);
        else
            return ((temp * temp) / x);
    }  
}