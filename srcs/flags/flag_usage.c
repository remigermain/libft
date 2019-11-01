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


static t_reg_list *usage_option(t_reg_list *lst)
{
	ft_dprintf(2, "\t\t");
	if (!ft_strcmp(lst->str, "int"))
		ft_dprintf(2, "< number ");
	else if (!ft_strcmp(lst->str, "string"))
		ft_dprintf(2, "< string ");
	else if (!ft_strcmp(lst->str, "char"))
	    ft_dprintf(2, "< character ");
	else if (!ft_strcmp(lst->str, "uint"))
		ft_dprintf(2, "< unsigned number ");
	else if (!ft_strcmp(lst->str, "file"))
		ft_dprintf(2, "< file ");
	lst = lst->next;
	while (lst && !ft_strncmp(lst->token, "opt_", 4))
	{
		if (!ft_strcmp(lst->token, "opt_min"))
			ft_dprintf(2, " min: %d ", ft_atoi(lst->str));
		else if (!ft_strcmp(lst->token, "opt_max"))
			ft_dprintf(2, " max: %d ", ft_atoi(lst->str));
		else if (!ft_strcmp(lst->token, "opt_eq"))
			ft_dprintf(2, " euqual: %d ", ft_atoi(lst->str));
		else if (!ft_strcmp(lst->token, "opt_pattern"))
			ft_dprintf(2, " pattern: %s ", lst->str);
		lst = lst->next;
	}
	ft_dprintf(2, ">\n");
	return (lst);
}

t_reg_list *usage_name(t_reg_list *lst)
{
	if (lst && lst->token && !ft_strcmp(lst->token, "separator"))
		lst = lst->next;
	ft_dprintf(2, "\t");
	if (lst && lst->token && !ft_strcmp(lst->token, "mflags"))
	{
		ft_dprintf(2, "--%s ", lst->str);
		lst = lst->next;
	}
	if (lst && lst->token && !ft_strcmp(lst->token, "sflag"))
	{
		ft_dprintf(2, " -%s ", lst->str);
		lst = lst->next;
	}
	return (lst);
}

static t_reg_list	*usage_set_unset(t_reg_list *lst, char *str, char *mode)
{
	t_bool	isset;

	isset = FALSE;
	ft_dprintf(2, "\t\t<Flags %s :", str);
	while (lst && lst->token && !ft_strcmp(lst->token, mode))
	{
		if (isset)
			ft_dprintf(2, ",");
		ft_dprintf(2, " %s", lst->str);
		lst = lst->next;
		isset = TRUE;
	}
	ft_dprintf(2, " >\n");
	return (lst);
}

static t_reg_list *usage_flag(t_reg_list *lst, t_reg_list *text)
{
	t_bool	isset;

	isset = FALSE;
	lst = usage_name(lst);
	ft_dprintf(2, "\t\t%s.\n", text ? text->str : "No Description");
	while (lst && !(lst->token && !ft_strcmp(lst->token, "separator")))
	{
		if (!ft_strcmp(lst->token, "type"))
			lst = usage_option(lst);
		else if (lst->token && !ft_strcmp(lst->token, "set"))
			lst = usage_set_unset(lst, "Enable", "set");
		else if (lst->token && !ft_strcmp(lst->token, "unset"))
			lst = usage_set_unset(lst, "Disable", "unset");
		else
			lst = lst->next;
		isset = TRUE;
	}
	if (lst && lst->next && isset)
		ft_dprintf(2, "\n");
	return (lst);
}

void        print_usage(t_flag *st)
{
	t_regex		reg;
	t_reg_list	*lst;
	t_reg_list	*text;

	if (ft_regex_exec(&reg, st->usage, REGEX_ARGV_USAGE) > 0)
	{
		lst = st->reg.capt;
		text = reg.capt;
		ft_dprintf(2, "Usage %s %s\nOptions:\n", st->argv[0], text->str);
		ft_dprintf(2, "\t--help  -h \tTo display command line options.\n");
		text = text->next;
		while (lst && lst->next)
		{
			if (text && text->token && !ft_strcmp(text->token, "separator"))
				text = text->next;
			lst = usage_flag(lst, text);
			if (text)
				text = text->next;
		}
		ft_dprintf(2, "\n\t__Compiled with GCC %d.%d__\n", __GNUC__,__STDC__);
	}
	ft_regex_free(&reg);
    exit(0);
}