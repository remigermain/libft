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
	static t_bool		pass = FALSE;

	if (pass == FALSE)
	{
		ft_bzero(&st, sizeof(t_flags_inf));
		pass = TRUE;
	}

	return (&st);
}

int			flag_getindice(t_flags_inf *st, char *mfl, char *sfl)
{
	int	i;

	i = 0;
	while (i <= st->nb_flags)
	{
		if ((mfl && st->av[i].mfl && !ft_strcmp(st->av[i].mfl, mfl)) ||
			(sfl && st->av[i].sfl && !ft_strcmp(st->av[i].sfl, sfl)))
			return (i);
		i++;
	}
	return (-1);
}

int			flag_add_name(t_flags_inf *st, char *mfl, char *sfl, int pos)
{
	if (mfl || sfl)
	{
		pos = flag_getindice(st, mfl, sfl);
		if (pos == -1)
			pos = ++st->nb_flags;
		if (mfl && !st->av[pos].mfl)
			st->av[pos].mfl = ft_strdup(mfl);
		if (sfl && !st->av[pos].sfl)
			st->av[pos].sfl = ft_strdup(sfl);
	}
	return (pos);
}

t_bool		flag_add(char *mfl, char *sfl, void *value, enum e_type type)
{
	t_flags_inf	*st;
	int			pos;

	st = flags_av_struct();
	pos = flag_add_name(st, mfl, sfl, 0);
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
	int			i;
	int			j;

	i = -1;
	st = flags_av_struct();
	ft_printf("\n[ PRINT FLAG ]\n{\n");
	while (++i <= st->nb_flags && (j = -1))
	{
		ft_printf("\t[ MFLAG  \"%s\" ]\n", st->av[i].mfl);
		ft_printf("\t[ SFLAG  \"%s\" ]\n\t{\n", st->av[i].sfl);
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
	ft_printf("}\n");
}
