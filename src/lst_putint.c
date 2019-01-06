/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_putint.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:39:19 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 16:39:21 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	lst_putnb_unb(t_pf *lst)
{
	if (LENGHT == 1 && CONV != 'O' && CONV != 'U'
			&& CONV != 'D')
		lst->ul_nb = (unsigned short)va_arg(lst->va_copy, ULONG);
	else if (LENGHT == 2 && CONV != 'O' && CONV != 'U'
			&& CONV != 'D')
		lst->ul_nb = (unsigned char)va_arg(lst->va_copy, ULONG);
	else if (LENGHT == 10)
		lst->ul_nb = va_arg(lst->va_copy, long);
	else if (LENGHT == 20)
		lst->ul_nb = va_arg(lst->va_copy, ULONG);
	else if (LENGHT == 100)
		lst->ul_nb = va_arg(lst->va_copy, intmax_t);
	else if (LENGHT == 1000)
		lst->ul_nb = va_arg(lst->va_copy, size_t);
	else if (CONV == 'o' || CONV == 'x' || CONV == 'X' ||
			CONV == 'u' || CONV == 'X')
		lst->ul_nb = va_arg(lst->va_copy, unsigned int);
	else
		lst->ul_nb = va_arg(lst->va_copy, ULONG);
	if (SIGN == '+' && (CONV == 'd' || CONV == 'D' ||
				CONV == 'I' || CONV == 'i'))
		PSIGN = 2;
}

static void	lst_putnb_snb(t_pf *lst)
{
	long nb_tmp;

	if (LENGHT == 1)
		nb_tmp = (short)va_arg(lst->va_copy, int);
	else if (LENGHT == 2)
		nb_tmp = (char)va_arg(lst->va_copy, int);
	else if (LENGHT == 10)
		nb_tmp = va_arg(lst->va_copy, long);
	else if (LENGHT == 20)
		nb_tmp = va_arg(lst->va_copy, long);
	else if (LENGHT == 100)
		nb_tmp = va_arg(lst->va_copy, intmax_t);
	else if (LENGHT == 1000)
		nb_tmp = va_arg(lst->va_copy, size_t);
	else if (CONV == 'D' || CONV == 'I' || LENGHT != 0)
		nb_tmp = va_arg(lst->va_copy, long);
	else
		nb_tmp = va_arg(lst->va_copy, int);
	PSIGN = (nb_tmp < 0 ? 1 : 0);
	if (SIGN == '+' && nb_tmp >= 0 && (CONV == 'd' ||
				CONV == 'D' || CONV == 'I' || CONV == 'i'))
		PSIGN = 2;
	lst->ul_nb = (nb_tmp < 0 ? -nb_tmp : nb_tmp);
}

void		lst_putint(t_pf *lst)
{
	if (CONV == 'd' || (CONV == 'i') ||
			(CONV == 'D' && LENGHT == 0))
		lst_putnb_snb(lst);
	else
		lst_putnb_unb(lst);
	if (CONV == 'p' || ((CONV == 'x' || CONV == 'X')
				&& HASH == 1 && lst->ul_nb != 0))
		PSIGN = 3;
}
