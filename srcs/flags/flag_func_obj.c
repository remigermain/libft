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

void	func_pattern(t_flag *st, t_finfo *it)
{
	t_regex	reg;

	if (ft_regex_exec(&reg, it->av, it->pattern) == 0)
	{
		ft_dprintf(2, T_RED"error: "T_LGREY"The %s need to be \"%s\""\
			".\n"T_WHITE, it->type, it->pattern);
		ft_error_argv(st->argv, st->i + st->add, 0);
		it->error = AV_ERROR(ERROR_SET);
	}
	ft_regex_free(&reg);
}

void	func_lenght(t_flag *st, t_finfo *it, char *str, int nb)
{
	unsigned char	*msg;

	ft_sprintf(&msg, str, nb);
	it->error = error_argv(st, (char*)msg, st->i + st->add, 0);
	ft_strdel((char**)&msg);
}
