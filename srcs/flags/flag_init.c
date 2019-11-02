/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flag_init.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <rgermain@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 16:19:09 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/02 18:56:27 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static t_bool	find_mflags(t_flag *st, char *mfl)
{
	t_reg_list *lst;
	t_reg_list *head;

	head = NULL;
	if (!ft_strcmp(mfl, "help"))
		print_usage(st);
	lst = st->reg.capt;
	while (lst)
	{
		if (lst->token && !ft_strcmp(lst->token, "mflags")
						&& !ft_strcmp(lst->str, mfl))
			return (parse_flags(st, lst, head));
		head = lst;
		lst = lst->next;
	}
	error_argv(st, "unknow flags", st->i, 0);
	return (FALSE);
}

static t_bool	find_sflags(t_flag *st, int sfl)
{
	t_reg_list *lst;
	t_reg_list *head;

	head = NULL;
	if (sfl == 'h')
		print_usage(st);
	lst = st->reg.capt;
	while (lst)
	{
		if (lst->token && !ft_strcmp(lst->token, "sflag")
						&& *lst->str == sfl)
			return (parse_flags(st, lst, head));
		head = lst;
		lst = lst->next;
	}
	error_argv(st, "unknow flags", st->i, st->j);
	return (FALSE);
}

static t_bool	call_flags(t_flag *st)
{
	st->add = 1;
	if (st->argv[st->i][0] == '-')
	{
		st->j = 0;
		while (st->argv[st->i][++st->j] && AV_ERROR(ERROR_GET) <= MAX_ERROR)
		{
			if (st->argv[st->i][1] == '-')
				return (find_mflags(st, st->argv[st->i] + 2));
			else
				find_sflags(st, st->argv[st->i][st->j]);
		}
	}
	else if (!add_flags_av(NO_FLAG, NO_FLAG, (void *)st->argv[st->i], STRING))
	{
		ft_regex_free(&(st->reg));
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	flag_mod(t_flag *st)
{
	if ((st->argv[st->i][0] != '-' && st->mod & F_NOF) ||
			!ft_strcmp("--", st->argv[st->i]) && st->mod & F_STOP)
		return (FALSE);
	return (TRUE);
}

int				flag_init(char **argv, char *flag, char *usa, enum e_flags mod)
{
	t_flag	st;

	st.i = 1;
	st.mod = mod;
	st.argv = argv;
	st.usage = usa;
	st.argc = ft_maxlen_tab(argv, TAB_LENGHT);
	ft_regex_exec(&(st.reg), flag, REGEX_ARGV_PARSE);
	while (st.argv[st.i] && AV_ERROR(ERROR_GET) <= MAX_ERROR && flag_mod(&st))
	{
		if (!call_flags(&st))
			return (error_argv(&st, "To many arguments", st.i + st.add, 0));
		st.i += st.add;
	}
	while (st.argv[st.i] &&
			add_flags_av(NO_FLAG, NO_FLAG, (void*)st.argv[st.i], STRING))
		st.i++;
	ft_regex_free(&(st.reg));
	return (AV_ERROR(ERROR_GET | ERROR_PRINT) ? -1 : st.i);
}
