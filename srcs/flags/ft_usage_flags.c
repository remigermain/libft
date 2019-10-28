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
	else if (!ft_strcmp(lst->str, "char*"))
		ft_dprintf(2, "< string ");
	else if (!ft_strcmp(lst->str, "char"))
	    ft_dprintf(2, "< character ");
	else if (!ft_strcmp(lst->str, "size_t"))
		ft_dprintf(2, "< unsigned number ");
	lst = lst->next;
	while (lst && !ft_strncmp(lst->token, "opt_", 4))
	{
		if (!ft_strcmp(lst->token, "opt_min"))
			ft_dprintf(2, " min: %d ", ft_atoi(lst->str));
		else if (!ft_strcmp(lst->token, "opt_max"))
			ft_dprintf(2, " max: %d ", ft_atoi(lst->str));
		else if (!ft_strcmp(lst->token, "opt_ex"))
			ft_dprintf(2, " euqual: %d ", ft_atoi(lst->str));
		else if (!ft_strcmp(lst->token, "opt_pattern"))
			ft_dprintf(2, " pattern: %s ", lst->str);
		lst = lst->next;
	}
	ft_dprintf(2, ">\n");
	return (lst);
}

static void  usage_type(t_reg_list *lst, char *text)
{
	ft_dprintf(2, "\t%s\t\t%s\n", lst->str, text);
	lst = lst->next;
	while (lst && !(lst->token && (!ft_strcmp(lst->token, "alone") ||
								   !ft_strcmp(lst->token, "flags"))))
	{
		if (!ft_strcmp(lst->token, "type"))
			lst = usage_option(lst);
		else
		{
			//if (lst->token && !ft_strcmp(lst->token, "set"))
			//	
			//else if (lst->token && !ft_strcmp(lst->token, "unset"))
			//	(void);
			lst = lst->next;
		}
	}
}

static void usage_flag(t_reg_list *lst, char *flag, char *text)
{
	while (lst)
	{
		//ft_printf("[%s  %s]\n", lst->token, lst->str);
		if (lst->token && (!ft_strcmp(lst->token, "alone") ||
			!ft_strcmp(lst->token, "flags")) && !ft_strcmp(lst->str, flag))
		{
			usage_type(lst, text);
			break ;
		}
		lst = lst->next;
	}
}

char   *init_usage(char *str)
{
    static char *text = NULL;

    if (!text)
        text = str;
    return (text);
}

#define REGEX_ARGV_USAGE "^(\\s*(?<flags>[\\w_]+)\\s*,\\s*(?<short_flags>[\\w_]+)\\s*,\\s*\\\"(?<text>[^\"]+)\\\"\\s*\\|)+$"
void        print_usage(t_flag *st)
{
	t_regex		reg;
	t_reg_list *lst;
	t_reg_list *lst2;
	char	*str;
	t_bool ret;
	ret = 0;
	str = init_usage(NULL);
	ret = ft_regex_exec(&reg, str, REGEX_ARGV_USAGE);
	if (ret > 0)
	{
		lst = reg.capt;
		ft_dprintf(2, "%s usage\n\n\t[ FLAGS ]\n", st->argv[0]);
		while (lst && lst->next && lst->next->next)
		{
			lst2 = st->reg.capt;
			usage_flag(lst2, lst->str, lst->next->next->str);
			lst = lst->next->next->next;
		}
	}
	ft_regex_print(&reg);
	if (ret == 0)
	{
		ft_printf("lalal %d   %s\n", reg.error_pos, reg.s1);
		error_line_pos("error parsing", 76, reg.error_pos);
		error_line_e(reg.s1, reg.error_pos);
	}
	ft_regex_free(&reg);
	ft_dprintf(2, "\n");
    exit(0);
}