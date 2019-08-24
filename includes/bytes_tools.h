/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 18:10:38 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/31 18:26:18 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef BYTES_TOOLS_H
# define BYTES_TOOLS_H
# define MEM_SEPARATOR 16

enum	e_print_memory
{
	MEM_ASCII = 0b1,
	MEM_ADD = 0b10,
	MEM_SP = 0b100,
};

void			ft_print_memory(void *type, size_t s, enum e_print_memory f);
void			reverse_bytes(void *bytes, size_t size);
unsigned char	**ft_create_bytes_tab(size_t size);

/*
**-------------------------------------------------------
**          ft_option.c
**-------------------------------------------------------
*/
t_bool			exist_option(int fl);
void			remove_option(int fl);
void			add_option(int fl);

#endif
