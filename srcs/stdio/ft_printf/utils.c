/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:38:55 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/30 16:25:30 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftprintf_error(t_pf *st, char *str, size_t index)
{
	ft_putstr_fd("\n  / \\    WARNING\n / | \\  FT_PRINT ERROR", 2);
	ft_putstr_fd("\n/  o  \\\n-------\n     	[", 2);
	if (index == 1)
		ft_putstr_fd(ft_strerror(errno), 2);
	ft_putstr_fd("\"", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("]     \n\n", 2);
	if (st->str != NULL)
		free(st->str);
	exit(0);
}

int		ulen_base(t_ulong nb, size_t base)
{
	return (nb >= base ? ulen_base(nb / base, base) + 1 : 1);
}
