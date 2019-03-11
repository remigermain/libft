/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf_drawline.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/07 18:58:39 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 12:41:00 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lib_mlx.h"

/*
** --------------------------------------------------------------------------
**|																			|
**|				octant de 8 && 4											|
**|																			|
** --------------------------------------------------------------------------
*/

static void	draw_line8_4(t_mlxline *st)
{
	t_mlx_br	br;

	br.e = ABS(st->x2 - st->x1);
	br.dx = br.e * 2;
	br.dy = (st->y2 - st->y1) * 2;
	while (st->x1 <= st->x2)
	{
//		mlx_pixel_put(st->mlx_ptr, st->win_ptr, st->x1++, st->y1, color);
		br.e -= br.dy;
		if (br.e < 0)
		{
			st->y1++;
			br.e += br.dx;
		}
	}
}

/*
** --------------------------------------------------------------------------
**|																			|
**|				octant de 7 && 3											|
**|																			|
** --------------------------------------------------------------------------
*/

static void	draw_line7_3(t_mlxline *st)
{
	t_mlx_br	br;

	br.e = ABS(st->y2 - st->y1);
	br.dy = br.e * 2;
	br.dx = (st->x2 - st->x1) * 2;
	while (st->y1 <= st->y2)
	{
//		mlx_pixel_put(st->mlx_ptr, st->win_ptr, st->x1, st->y1++, color);
		br.e -= br.dx;
		if (br.e < 0)
		{
			st->x1++;
			br.e += br.dy;
		}
	}
}

/*
** --------------------------------------------------------------------------
**|																			|
**|				octant de 5 && 1											|
**|																			|
** --------------------------------------------------------------------------
*/

static void	draw_line5_1(t_mlxline *st)
{
	t_mlx_br	br;

	br.e = ABS(st->x2 - st->x1);
	br.dx = br.e * 2;
	br.dy = (st->y1 - st->y2) * 2;
	while (st->x1 <= st->x2)
	{
//		mlx_pixel_put(st->mlx_ptr, st->win_ptr, st->x1++, st->y1, color);
		br.e -= br.dy;
		if (br.e < 0)
		{
			st->y1--;
			br.e += br.dx;
		}
	}
}

/*
** --------------------------------------------------------------------------
**|																			|
**|				octant de 6 && 2											|
**|																			|
** --------------------------------------------------------------------------
*/

static void	draw_line6_2(t_mlxline *st)
{
	t_mlx_br	br;

	br.e = ABS(st->y1 - st->y2);
	br.dy = br.e * 2;
	br.dx = (st->x2 - st->x1) * 2;
	while (st->y1 >= st->y2)
	{
//		mlx_pixel_put(st->mlx_ptr, st->win_ptr, st->x1, st->y1--, color);
		br.e -= br.dx;
		if (br.e < 0)
		{
			st->x1++;
			br.e += br.dy;
		}
	}
}

void		mlx_drawline(t_mlxline *st)
{
	if (st->x1 > st->x2 && st->y1 > st->y2)
	{
		ft_swap(&(st->x1), &(st->x2));
		ft_swap(&(st->y1), &(st->y2));
	}
	if ((st->x2 - st->x1) >= 0 && (st->y2 - st->y1) >= 0)
	{
		if ((st->x2 - st->x1) >= (st->y2 - st->y1))
			draw_line8_4(st);
		else
			draw_line7_3(st);
	}
	else
	{
		if (st->x1 > st->x2)
		{
			ft_swap(&(st->x1), &(st->x2));
			ft_swap(&(st->y1), &(st->y2));
		}
		if ((st->x2 - st->x1) >= -(st->y2 - st->y1))
			draw_line5_1(st);
		else
			draw_line6_2(st);
	}
}
