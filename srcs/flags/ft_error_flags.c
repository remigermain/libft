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
		ft_dprintf(2, "%d%s ", error, (error > MAX_ERROR ? "+" : ""));
		ft_dprintf(2, "error generate\n", error);
	}
	return (error);
}

int	wrong_argv(t_flag *st, char *msg)
{
	ft_dprintf(2, T_RED"error: "T_LGREY"%s.\n"T_WHITE, msg);
	ft_error_argv(st->argv, st->i + st->add, 0);
	return (cout_error_argv(ERROR_SET));
}

int		wrong_type(t_flag *st, char *type)
{
	ft_dprintf(2, T_RED"error: "T_LGREY"Wrong argument type, need "\
		 "%s.\n"T_WHITE, type);
	ft_error_argv(st->argv, st->i + st->add, 0);
	return (cout_error_argv(ERROR_SET));
}

void		print_match_patern(char *str)
{
	char mem[127];
	int i;
	int j;

	i = 0;
	ft_bzero(mem, 127);
	ft_printf(T_LGREY" Pattern"T_WHITE" can be : ");
	while (str[i])
	{
		if (i)
			ft_dprintf(2, " or ");
		if (str[i] == '|')
			i++;
		i += ft_spantype(str + i, ft_isspace);		
		j = ft_spanchar(str + i, "|");
		ft_strncpy(mem, str + i, j);
		ft_dprintf(2, "\""T_LGREY"%s"T_WHITE"\"", mem);
		i += j;
		i += ft_spantype(str + i, ft_isspace);
	}
	ft_dprintf(2, ".\n");
}

int		not_match(t_flag *st, char *str, char *match)
{
	ft_dprintf(2, T_RED"error: "T_LGREY"String not match \"%s\""\
		 ".\n"T_WHITE, str);
	print_match_patern(match);
	ft_error_argv(st->argv, st->i + st->add, 0);
	return (cout_error_argv(ERROR_SET));
}

int		missing_argv(t_flag *st)
{
	ft_dprintf(2, T_RED"error: "T_LGREY"Missing arguments.\n"T_WHITE);
	return (cout_error_argv(ERROR_SET));
}

int		many_argv(t_flag *st)
{
	ft_dprintf(2, T_RED"error: "T_LGREY"To many arguments !\n"T_WHITE);
	ft_error_argv(st->argv, st->i + st->add, 0);
	return (cout_error_argv(ERROR_GET | ERROR_SET));
}

int		unknow_flags(char **argv, int i, int j)
{
	ft_dprintf(2, T_RED"error: "T_LGREY"unknow flags.\n"T_WHITE);
	ft_error_argv(argv, i, j);
	return (cout_error_argv(ERROR_SET));
}

void	error_optionInt(t_flag *st, t_finfo *it, int nb)
{
	char	msg[50];

	if ((it->isset & 0x1 && nb < it->min) ||
		((it->isset >> 1) & 0x1 && nb > it->max))
	{
		ft_strcpy(msg, "number c'ant be ");
		if (it->isset & 0x1 && nb < it->min)
		{
			ft_strcat(msg, "less than \"");
			ft_itoabuffer(msg + 27, it->min);
		}			
		if ((it->isset >> 1) & 0x1 && nb > it->max)
		{
			ft_strcat(msg, "more than \"");
			ft_itoabuffer(msg + 27, it->max);
		}
		strcat(msg, "\"");
		//wrong_flags(st, "Wrong", msg);
		it->error = wrong_argv(st, msg);
	}
}

void	error_optionString(t_flag *st, t_finfo *it, char *str)
{
	char	msg[50];
	int		len;

	len = ft_strlen(str);
	if ((it->isset & 0x1 && len < it->min) ||
		((it->isset >> 1) & 0x1 && len > it->max))
	{
		ft_strcpy(msg, "string c'ant be ");
		if (it->isset & 0x1 && len < it->min)
		{
			ft_strcat(msg, "less than \"");
			ft_itoabuffer(msg + 27, it->min);
		}			
		if ((it->isset >> 1) & 0x1 && len > it->max)
		{
			ft_strcat(msg, "more than \"");
			ft_itoabuffer(msg + 27, it->max);
		}
		strcat(msg, "\" character");
		it->error = wrong_argv(st, msg);
	}
}
