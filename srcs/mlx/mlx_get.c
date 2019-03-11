/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mlx_key.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 12:18:23 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 12:40:33 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lib_mlx.h"

int		mlx_getkey(int key, void *s)
{
	t_mlxkey	*st;

	st = (t_mlxkey*)s;
	st->key[key][0] = (st->key[key][0] ? 0 : 1);
	if (st->print)
		ft_printf("%{T_BLUE}[mlx_getkey]\n%{T_EOC}  -key = %d\n\n", key);
	return (1);
}

int		mlx_getmouse(int key, int x, int y, void *s)
{
	t_mlxmouse	*st;

	st = (t_mlxmouse*)s;
	st->key[key][0] = (st->key[key][0] ? 0 : 1);
	st->motion.x = x;
	st->motion.y = y;
	if (st->print)
	{
		ft_printf("%{T_BLUE}[mlx_getmouse]\n%{T_EOC}  -mouse = %d", key);
		ft_printf("[x = %7d ||  y = %7d]\n", x, y);
	}
	return (1);
}

int		mlx_getmotion(int x, int y, void *s)
{
	t_mlxmotion	*st;

	st = (t_mlxmotion*)s;
	st->x = x;
	st->y = y;
	if (st->print)
	{
		ft_printf("%{T_BLUE}[mlx_getmotion]\n%{T_EOC}");
		ft_printf("[x = %7d ||  y = %7d]\n", x, y);
	}
	return (1);
}
