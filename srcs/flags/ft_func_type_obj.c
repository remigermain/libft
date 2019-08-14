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

static void	print_pattern(char *str)
{
	char mem[127];
	int	pass;
	int i;
	int j;

	i = 0;
	pass = 0;
	ft_bzero(mem, 127);
	ft_printf(T_LGREY" Pattern"T_WHITE" can be : ");
	while (str[i])
	{
		i += (str[i] == '|' ? 1 : 0);
		i += ft_spantype(str + i, ft_isspace);		
		j = ft_spanchar(str + i, "|");
		ft_strncpy(mem, str + i, j);
		if (pass && !str[i + ft_spantype(str + i + j, ft_isspace) + j])
			ft_printf(" or ");
		else if (pass && str[i])
			ft_dprintf(2, ", ");
		ft_dprintf(2, T_LGREY"%s"T_WHITE, mem);
		i += ft_spantype(str + i + j, ft_isspace) + j;
		pass = 1;
	}
	ft_dprintf(2, ".\n");
}

void		func_obj_match(t_flag *st, t_finfo *it, char *str)
{
	char	mem[127];
	int		i;
	int		j;

	i = 0;
	ft_bzero(mem, 127);
	while (it->str[i])
	{
		i += (it->str[i] == '|' ? 1 : 0);
		i += ft_spantype(it->str + i, ft_isspace);		
		j = ft_spanchar(it->str + i, "|");
		ft_strncpy(mem, it->str + i, j);
		if (ft_match(str, mem))
			return ;
		i += ft_spantype(it->str + i + j, ft_isspace) + j;
	}
	ft_dprintf(2, T_RED"error: "T_LGREY"String not match \"%s\""\
		 ".\n"T_WHITE, str);
	print_pattern(it->str);
	ft_error_argv(st->argv, st->i + st->add, 0);
	it->error = cout_error_argv(ERROR_SET);
}


void    func_obj_minmax(t_flag *st, t_finfo *it, char *type, enum e_type mod)
{
	unsigned char	*msg;

	ft_sprintf(&msg, "%s c'ant be %s than \"%d\"", type, 
    (mod == MAX ? "more" : "less"), (mod == MAX ? it->max : it->min));
	it->error = error_argv(st, (char*)msg, st->i + st->add, 0);
	ft_strdel((char**)&msg);
}