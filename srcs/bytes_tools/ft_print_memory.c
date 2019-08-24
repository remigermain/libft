/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conv_double.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 15:38:32 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/24 17:28:29 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	print_ascci_mem(unsigned char *mem, int i)
{
	int	j;

	if (i % MEM_SEPARATOR)
		j = i - (i % MEM_SEPARATOR) - 1;
	else
		j = i - MEM_SEPARATOR - 1;
	ft_printf("  |");
	while (++j < i)
	{
		if (ft_isprint(mem[j]))
			ft_printf("%c", mem[j]);
		else
			ft_printf(".");
	}
	ft_printf("|");
}

static void	memory_space(unsigned char *mem, int i, enum e_print_memory flag)
{
	if (i && i % MEM_SEPARATOR == 0)
	{
		if (flag & MEM_ASCII)
			print_ascci_mem(mem, i);
		ft_printf("\n");
	}
	else if (flag & MEM_SP && i && i % 2 == 0)
		ft_printf(" ");
	else if (!(flag & MEM_SP) && i)
		ft_printf(" ");
	if (i && i % MEM_SEPARATOR && i % 8 == 0)
		ft_printf(" ");
	if (i % MEM_SEPARATOR == 0 && flag & MEM_ADD)
		ft_printf("0x%.6x  ", i);
}

void		ft_print_memory(void *mem, size_t size, enum e_print_memory flag)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		memory_space(((unsigned char *)mem), i, flag);
		ft_printf("%hh.2x", ((unsigned char *)mem)[i++]);
	}
	if (flag & MEM_ASCII && i > 0)
		print_ascci_mem(mem, i);
	ft_printf("\n");
}
