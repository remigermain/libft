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

static int			type_all(t_flag *st, t_finfo *it, t_bool (*type_av)(t_flag *st, t_finfo*, enum e_option))
{
	if (type_av(st, it, CHECK))
	{
		ft_printf("lalal  %b\n", it->isset);
		if (it->isset & OP_MIN)
			type_av(st, it, MIN);
		if (it->isset & OP_MAX)
			type_av(st, it, MAX);
		if (it->isset & OP_EQ)
			type_av(st, it, EQ);
		if (it->isset & OP_PATTERN)
			type_av(st, it, PATTERN);
		if (!it->error)
			type_av(st, it, ADD);
	}
	st->add++;
	return (0);
}

static void 		check_av_option(t_flag *st, t_finfo *it)
{
	static char *type[4] = {"int", "char*", "char", "uint"};
	static t_bool (*func[4])(t_flag * st, t_finfo *, enum e_type) = {check_int, check_string, check_char, check_uint};
	int i;

	if ((st->i + st->add) < st->argc)
	{
		i = 0;
		it->av = st->argv[st->i + st->add];
		while (i < 4 && ft_strcmp(it->type, type[i]))
			i++;
		if (i < 4)
			type_all(st, it, func[i]);
		else
			ft_printf("unknow type %s\n", it->type);
	}
	else
		error_argv(st, "Missing arguments", st->i + st->add, 0);
}

static void			parse_option_number(char *str, int *nb, int *isset, int mod)
{
	*nb = ft_atoi(str);
	*isset |= mod;
}

static t_reg_list	*parse_option_type(t_flag *st, t_finfo *it, t_reg_list *lst)
{
	ft_printf("[<%s>  \"%s\"]\n", lst->token, lst->str);
	it->type = lst->str;
	lst = lst->next;
	it->isset = 0;
	while (lst && !ft_strncmp(lst->token, "opt_", 4))
	{
		if (!ft_strcmp(lst->token, "opt_min"))
			parse_option_number(lst->str, &(it->min), &(it->isset), OP_MIN);
		else if (!ft_strcmp(lst->token, "opt_max"))
			parse_option_number(lst->str, &(it->max), &(it->isset), OP_MAX);
		else if (!ft_strcmp(lst->token, "opt_ex"))
			parse_option_number(lst->str, &(it->eq), &(it->isset), OP_EQ);
		else if (!ft_strcmp(lst->token, "opt_pattern"))
		{
			it->isset |= OP_PATTERN;
			it->pattern = lst->str;
		}
		ft_printf("[<%s>  \"%s\"]\n", lst->token, lst->str);
		lst = lst->next;
	}
	ft_printf("%b\n", it->isset);
	check_av_option(st, it);
	return (lst);
}

t_bool			parse_flags(t_flag *st, t_reg_list *lst)
{
	t_finfo it;

	add_flags(lst->str);
	ft_bzero(&it, sizeof(t_finfo));
	it.flag = lst->str;
	lst = lst->next;
	while (lst && !(lst->token && (!ft_strcmp(lst->token, "alone") ||
									!ft_strcmp(lst->token, "flags"))))
	{
		if (!ft_strcmp(lst->token, "type"))
			lst = parse_option_type(st, &it, lst);
		else
		{
			if (lst->token && !ft_strcmp(lst->token, "set"))
				add_flags(lst->str);
			else if (lst->token && !ft_strcmp(lst->token, "unset"))
				remove_flags(lst->str);
			lst = lst->next;
		}
	}
	return (TRUE);
}
