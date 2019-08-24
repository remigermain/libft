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

t_bool	add_flags_av(int fl, void *value, enum e_type type)
{
	t_flagav *av;

	av = flags_av_struct();
	return (flag_add(av, fl, value, type));
}

t_bool	add_flags(int fl)
{
	t_flagav *av;

	av = flags_av_struct();
	return (flag_add(av, fl, NULL, 0));
}

t_bool	exist_flags(int fl)
{
	t_flagav *av;

	av = flags_av_struct();
	return (flag_getindice(av, fl) == -1 ? FALSE : TRUE);
}

void	remove_flags(int fl)
{
	t_flagav	*av;
	int			i;

	av = flags_av_struct();
	i = flag_getindice(av, fl);
	if (i != -1)
		ft_bzero(&(av[i]), sizeof(t_flagav));
}

void	*get_flags_av(int fl, int nb)
{
	t_flagav *av;

	av = flags_av_struct();
	if (flag_getindice(av, fl) == -1)
		return (NULL);
	if (av[fl].fl == fl && av[fl].nb_arg > nb)
	{
		if (av[fl].exist_string & (1 << nb))
			return ((void**)(av[fl].string[nb]));
		if (av[fl].exist_char & (1 << nb))
			return ((void**)&(av[fl].schar[nb]));
		if (av[fl].exist_int & (1 << nb))
			return ((void**)&(av[fl].number[nb]));
	}
	return (NULL);
}
