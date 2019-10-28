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

t_bool	add_flags_av(char *fl, void *value, enum e_type type)
{
	t_flags_inf *st;

	st = flags_av_struct();
	return (flag_add(st, fl, value, type));
}

t_bool	add_flags(char *fl)
{
	t_flags_inf *st;

	st = flags_av_struct();
	return (flag_add(st, fl, NULL, 0));
}

t_bool	exist_flags(char *fl)
{
	t_flags_inf *st;

	st = flags_av_struct();
	return (flag_getindice(st, fl) == -1 ? FALSE : TRUE);
}

void	remove_flags(char *fl)
{
	t_flags_inf	*st;
	int			i;

	st = flags_av_struct();
	i = flag_getindice(st, fl);
	if (i != -1)
		ft_bzero(&(st->av[i]), sizeof(t_flags_inf));
}

void	*get_flags_av(char *fl, int nb)
{
	t_flags_inf	*st;
	int			index;

	st = flags_av_struct();
	index = flag_getindice(st, fl);
	if (index == -1)
		return (NULL);
	if (st->av[index].nb_arg > nb)
	{
		if (st->av[index].exist_string & (1 << nb))
			return ((void**)(st->av[index].string[nb]));
		if (st->av[index].exist_char & (1 << nb))
			return ((void**)&(st->av[index].schar[nb]));
		if (st->av[index].exist_int & (1 << nb))
			return ((void**)&(st->av[index].number[nb]));
	}
	return (NULL);
}
