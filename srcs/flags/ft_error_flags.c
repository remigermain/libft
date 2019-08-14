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

int		cout_error_argv(enum e_error_flag mod)
{
	static int error = 0;
	
	if (mod & ERROR_SET)
		error++;
	if (mod & ERROR_GET && mod & ERROR_PRINT && error)
	{
		if (error > MAX_ERROR)
			ft_dprintf(2, T_RED"error: "T_LGREY"To many error.\n"T_WHITE);
		ft_dprintf(2, "%d%s ", error, (error > MAX_ERROR ? "+" : ""));
		ft_dprintf(2, "error generate\n", error);
	}
	return (error);
}

int		wrong_type(t_flag *st, char *type)
{
	ft_dprintf(2, T_RED"error: "T_LGREY"Wrong argument type, need "\
		 "%s.\n"T_WHITE, type);
	ft_error_argv(st->argv, st->i + st->add, 0);
	return (cout_error_argv(ERROR_SET));
}

int		error_argv(t_flag *st, char *str, int i, int j)
{
	error_line(str);
	ft_error_argv(st->argv, i, j);
	return (cout_error_argv(ERROR_SET));
}