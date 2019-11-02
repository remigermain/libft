/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_parse.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <rgermain@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 16:19:09 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/02 19:15:10 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int			type_all(t_flag *st, t_finfo *it,
					t_bool (*type_av)(t_flag *st, t_finfo *, enum e_type))
{
	if (type_av(st, it, CHECK))
	{
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

static void			check_av_option(t_flag *st, t_finfo *it)
{
	static char		*type[MAX_TYPE_AV] =
	{"int", "string", "char", "uint", "file"};
	static t_bool	(*func[MAX_TYPE_AV])(t_flag *, t_finfo *, enum e_type) =
	{check_int, check_string, check_char, check_uint, check_file};
	int				i;

	if ((st->i + st->add) < st->argc)
	{
		i = 0;
		it->av = st->argv[st->i + st->add];
		while (i < MAX_TYPE_AV && ft_strcmp(it->type, type[i]))
			i++;
		if (i < MAX_TYPE_AV)
			type_all(st, it, func[i]);
		else
			ft_printf("unknow type %s\n", it->type);
	}
	else
		error_argv(st, "Missing arguments", st->i + st->add, 0);
}

static t_reg_list	*parse_option_type(t_flag *st, t_finfo *it, t_reg_list *lst)
{
	it->type = lst->str;
	lst = lst->next;
	it->isset = 0;
	while (lst && !ft_strncmp(lst->token, "opt_", 4))
	{
		if (!ft_strcmp(lst->token, "opt_min"))
			AV_ADD_NUM(ft_atoi(lst->str), &(it->min), &(it->isset), OP_MIN);
		else if (!ft_strcmp(lst->token, "opt_max"))
			AV_ADD_NUM(ft_atoi(lst->str), &(it->max), &(it->isset), OP_MAX);
		else if (!ft_strcmp(lst->token, "opt_eq"))
			AV_ADD_NUM(ft_atoi(lst->str), &(it->eq), &(it->isset), OP_EQ);
		else if (!ft_strcmp(lst->token, "opt_pattern"))
			AV_ADD_PATTERN(lst->str, it->pattern, &(it->isset), OP_PATTERN);
		lst = lst->next;
	}
	check_av_option(st, it);
	return (lst);
}

static t_reg_list	*put_name_flag(t_finfo *it, t_reg_list *head)
{
	if (head && head->token && !ft_strcmp(head->token, "separator"))
		head = head->next;
	if (head && head->token && !ft_strcmp(head->token, "mflags"))
	{
		it->mfl = head->str;
		head = head->next;
	}
	if (head && head->token && !ft_strcmp(head->token, "sflag"))
	{
		it->sfl = head->str;
		head = head->next;
	}
	return (head);
}

t_bool				parse_flags(t_flag *st, t_reg_list *lst, t_reg_list *head)
{
	t_finfo	it;

	ft_bzero(&it, sizeof(t_finfo));
	lst = put_name_flag(&it, head ? head : lst);
	add_flags(it.mfl, it.sfl);
	while (lst && !(lst->token && !ft_strcmp(lst->token, "separator")))
	{
		if (!ft_strcmp(lst->token, "type"))
			lst = parse_option_type(st, &it, lst);
		else
		{
			if (lst->token && !ft_strcmp(lst->token, "set"))
				add_flags(lst->str, NULL);
			else if (lst->token && !ft_strcmp(lst->token, "unset"))
				remove_flags(lst->str);
			lst = lst->next;
		}
	}
	return (TRUE);
}
