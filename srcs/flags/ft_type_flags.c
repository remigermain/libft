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

int			type_int(t_flag *st, char fl, char *flag, char *str)
{
	t_finfo	it;
	int		nb;
	int		i;
	int		j;

	i = 0;
	j = ((*str == '-' || *str == '+') ? 1 : 0);
	if (ft_str_is_numeric(str + j))
	{
		ft_bzero(&it, sizeof(t_finfo));
		nb = ft_atoi(str); // nedd 
		i += parse_typeoption(st, &it, flag);
		error_optionInt(st, &it, nb);
		if (!it.error)
			add_flags_av(fl, (void*)&nb, INT);
	}
	else
		wrong_type(st, "int ");
	st->add++;	
	return (i);
}

int			type_string(t_flag *st, char fl, char *flag, char *str)
{
	t_finfo	it;
	int		i;

	i = 0;
	if (str[0] && str[0] != '-')
	{
		ft_bzero(&it, sizeof(t_finfo));
		i += parse_typeoption(st, &it, flag);
		error_optionString(st, &it, str);
		if ((it.isset >> 2) & 0x1)
			name_option_match(st, &it, str);
		if (!it.error)
			add_flags_av(fl, (void*)str, STRING);
	}
	else
		wrong_type(st, "strings");
	st->add++;	
	return (i);
}

int			type_char(t_flag *st, char fl, char *flag, char *str)
{
	t_finfo	it;
	int i;

	i = 0;
	if (str[0] && str[0] != '-' && !str[1])
	{
		ft_bzero(&it, sizeof(t_finfo));
		i += parse_typeoption(st, &it, flag);
		if (it.isset >> 2 & 0x1)
			name_option_match(st, &it, str);
		if (!it.error)
			add_flags_av(fl, (void*)str, CHAR);
	}
	else
		wrong_type(st, "one character");
	st->add++;
	return (i);
}

int			is_type(t_flag *st, t_foption *op, char *flag)
{
	int	i;
	int j;

	i = st->i + op->nb;
	j = ft_spancharspace(flag, ",}{");
	if ((st->i + op->nb) >= st->argc)
		missing_argv(st);
	else
	{
		if (!ft_strncmp(flag, "int", 3))
			j += type_int(st, op->fl, flag + j, st->argv[i]);
		else if (!ft_strncmp(flag, "char*", 5))
			j += type_string(st, op->fl, flag + j, st->argv[i]);
		else if (!ft_strncmp(flag, "char", 4))
			j += type_char(st, op->fl, flag + j, st->argv[i]);
		else
			ft_printf("unknow type %.*s\n", j, flag);
	}
	j += ft_spanoption(flag + j);
	return (j);
}