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
	return (flags_base(fl, F_ADD, value, type));
}

t_bool	add_flags(int fl)
{
	return (flags_base(fl, F_ADD, NULL, 0));
}

int		exist_flags(int fl)
{
	return (flags_base(fl, F_EXIST, NULL, 0));
}

void	remove_flags(int fl)
{
	flags_base(fl, F_RM, NULL, 0);
}

int		print_flags(void)
{
	return (flags_base('f', F_PRINT, NULL, 0));
}
