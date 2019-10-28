/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flags.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 16:21:27 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/20 16:22:02 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_flags_inf	*flags_av_struct(void)
{
	static t_flags_inf	st;

	return (&st);
}

int			flag_getindice(t_flags_inf *st, char *fl)
{
	size_t		i;

	i = 0;
	while (i < st->nb_flags)
	{
		if (!ft_strcmp(st->av[i].fl, fl))
			return (i);
		i++;
	}
	return (-1);
}

t_bool		flag_add(t_flags_inf *st, char *fl, void *value, enum e_type type)
{
	size_t	pos;

	pos = st->nb_flags;
	if (!st->av[pos].fl)
		st->av[pos].fl = fl;
	if (value && st->av[pos].nb_arg < 30)
	{
		if (type == STRING)
		{
			st->av[pos].exist_string |= (1 << st->av[pos].nb_arg);
			st->av[pos].string[st->av[pos].nb_arg++] = (char*)value;
		}
		else if (type == CHAR)
		{
			st->av[pos].exist_char |= (1 << st->av[pos].nb_arg);
			st->av[pos].schar[st->av[pos].nb_arg++] = *((char*)value);
		}
		else if (type == INT)
		{
			st->av[pos].exist_int |= (1 << st->av[pos].nb_arg);
			st->av[pos].number[st->av[pos].nb_arg++] = *(int*)(value);
		}
	}
	else if (value)
		return (FALSE);
	return (TRUE);
}

void		print_flags(void)
{
	t_flags_inf	*st;
	size_t		i;
	int			j;

	i = 0;
	st = flags_av_struct();
	ft_printf("\n[ PRINT FLAG ]\n{\n");
	while (i < st->nb_flags)
	{
		if ((st->av[i].fl || st->av[i].nb_arg) && (j = -1))
		{
			ft_printf("\t[ FLAG  \"%c\" ]\n\t{\n", st->av[i].fl);
			ft_printf("\t\t[ NB ARG  %d ]\n\t\t{\n", st->av[i].nb_arg);
			while (++j < st->av[i].nb_arg)
			{
				ft_printf("\t\t\t[%2d]", j);
				if ((st->av[i].exist_string >> j) & 01)
					ft_printf("[ String  :  %s ]\n", st->av[i].string[j]);
				else if ((st->av[i].exist_char >> j) & 01)
					ft_printf("[ character  :  %c ]\n", st->av[i].schar[j]);
				else if ((st->av[i].exist_int >> j) & 01)
					ft_printf("[ Number   :  %d ]\n", st->av[i].number[j]);
			}
			ft_printf("\t\t}\n\t}\n");
		}
		i++;
	}
	ft_printf("}\n");
}
