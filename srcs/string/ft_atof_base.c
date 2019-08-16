/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/02 11:14:09 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/19 21:55:19 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h" 

static double   ft_atof_base2(const char *str, double nb, int base)
{
    double val;
    double f;

    f = 1.0;
    val = 0.0;
    if (*str == '.')
        str++;
    while (*str && ft_base_string(*str, base))
	{
        f *= (double)((double)base / 100);
		if (ft_isdigit(*str))
			val += (f * (*str++ - '0'));
		else
			val += (f * (*str++ - 'a' + 10));
	}
    return(val + nb);
}

double          ft_atof_base(const char *str, int base)
{
    double  nb;
	int     neg;

	nb = 0;
	neg = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str && ft_base_string(*str, base))
	{
		if (ft_isdigit(*str))
			nb = ((nb * base) + (*str++ - '0'));
		else
			nb = ((nb * base) + (*str++ - 'a' + 10));
	}
	return (ft_atof_base2(str, nb, base) * neg);
}