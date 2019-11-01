/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse_argv.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 16:19:09 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/20 16:26:06 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void       flag_free(void)
{
	t_flags_inf	*st;
    int			i;

	i = -1;
	st = flags_av_struct();
    while (++i <= st->nb_flags)
	{
		if (st->av[i].mfl)
			ft_strdel(&(st->av[i].mfl));
		if (st->av[i].sfl)
			ft_strdel(&(st->av[i].sfl));
	}
}