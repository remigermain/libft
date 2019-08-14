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

t_flagav	*flags_av_struct(void)
{
	static t_flagav av[MAX_FLAGS];
	
	return (av);
}

int			flag_getindice(t_flagav *av, int fl)
{
	int		i;

	i = -1;
	if (fl < 0 || fl > MAX_FLAGS)
		return (-1);
	while (++i < MAX_FLAGS)
		if (av[i].fl == fl)
			return (i);
	return (-1);
}

t_bool		flag_add(t_flagav *av, int fl, void *value, enum e_type type)
{
	if (!av[fl].fl)
		av[fl].fl = fl;
	if (value && av[fl].nb_arg < 30 && ft_strcmp((char*)value, "--"))
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

void		print_flags(void)
{
	t_flagav	*av;
	int			i;
	int			j;

	i = 0;
	av = flags_av_struct();
	ft_printf("\n[ PRINT FLAG ]\n{\n");
	while (++i < MAX_FLAGS)
		if ((av[i].fl || av[i].nb_arg) && (j = -1))
		{
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
	ft_printf("}\n");
}
