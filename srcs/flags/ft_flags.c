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

void	print_flag(t_flagav *av)
{
	int i;
	int j;

	i = -1;
	ft_printf("\n[ PRINT FLAG ]\n{\n");
	while (++i < MAX_FLAGS)
	{
		if (av[i].fl || av[i].nb_arg)
		{
			j = -1;
			if (i == FLAG_ARGV)
				ft_printf("\t[ NO FLAG ]\n\t{\n");
			else
				ft_printf("\t[ FLAG  \"%c\" ]\n\t{\n", av[i].fl);
			ft_printf("\t\t[ NB ARG  %d ]\n\t\t{\n", av[i].nb_arg);
			while (++j < av[i].nb_arg)
			{
				ft_printf("\t\t\t[%2d]", j);
				if ((av[i].exist_string >> j) & 01)
					ft_printf("[ String  :  %s ]\n", av[i].string[j]);
				else if ((av[i].exist_char >> j) & 01)
					ft_printf("[ character  :  %c ]\n", av[i].schar[j]);
				else if ((av[i].exist_int >> j) & 01)
					ft_printf("[ Number  %d ]\n", av[i].number[j]);
			}
			ft_printf("\t\t}\n\t}\n");
		}
	}
	ft_printf("}\n");
}

int		flag_getindice(t_flagav *av, int fl)
{
	int		i;

	i = -1;
	while (i < MAX_FLAGS)
	{
		if (av[i].fl == fl)
			return (i);
	}
	return (-1);
}

void	flag_remove(t_flagav *av, int fl)
{
	int i;

	i = flag_getindice(av, fl);
	if (i != -1)
		ft_bzero(&(av[i]), sizeof(t_flagav));
}

t_bool	flag_add(t_flagav *av, int fl, void *value, enum e_type type)
{
	if (!av[fl].fl)
		av[fl].fl = fl;
	if (value && av[fl].nb_arg < 30)
	{
		if (type == STRING)
		{
			av[fl].exist_string |=  (1 << av[fl].nb_arg);
			av[fl].string[av[fl].nb_arg++] = (char*)value;
		}
		else if (type == CHAR)
		{
			av[fl].exist_char |=  (1 << av[fl].nb_arg);			
			av[fl].schar[av[fl].nb_arg++] = *((char*)value);
		}
		else if (type == INT)
		{
			av[fl].exist_int |= (1 << av[fl].nb_arg);
			av[fl].number[av[fl].nb_arg++] = *(int*)(value);
		}
	}
	else if (value)
		return (FALSE);
	return (TRUE);
}

t_bool	flags_base(int fl, enum e_flags mod, void *value, enum e_type type)
{
	static t_flagav av[MAX_FLAGS];

	if (mod == F_ADD)
		return (flag_add(av, fl, value, type));
	else if (mod == F_EXIST)
		return (flag_getindice(av, fl) == -1 ? FALSE : TRUE);
	else if (mod == F_RM)
		flag_remove(av, fl);
	else if (mod == F_PRINT)
		print_flag(av);
	return (TRUE);
}

t_bool	add_flags_av(int fl, void *value, enum e_type type)
{
	return (flags_base(fl, F_ADD, value, type));
}

t_bool	add_flags(int fl)
{
	return (flags_base(fl, F_ADD, NULL, 0));
}

int		exist_flags(int fl)
{
	return (flags_base(fl, F_EXIST, NULL, 0));
}

void	remove_flags(int fl)
{
	flags_base(fl, F_RM, NULL, 0);
}

int		print_flags(void)
{
	return (flags_base('f', F_PRINT, NULL, 0));
}
