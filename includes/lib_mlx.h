/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lib_mlx.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 11:38:09 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 12:41:01 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIB_MLX_H
# define LIB_MLX_H
# include "libft.h"
# include "mlx_keycode.h"

typedef struct	s_mlxline
{
	int x1;
	int y1;
	int x2;
	int y2;
	size_t color;
	size_t	width;
	size_t	height;
	int		*data;
}				t_mlxline;

typedef struct	s_mlxbr
{
	int	dx;
	int dy;
	int e;
}				t_mlx_br;

typedef struct	s_mlxkey
{
	char	key[280][1];
	char	print;
}				t_mlxkey;

typedef struct	s_mlxmotion
{
	int x;
	int y;
	char	print;
}				t_mlxmotion;

typedef struct	s_mlxmouse
{
	t_mlxmotion	motion;
	char		key[3][1];
	char		print;
}				t_mlxmouse;

void			mlx_drawline(t_mlxline *st);
int				mlx_getkey(int key, void *s);
int				mlx_getmouse(int key, int x, int y, void *s);
int				mlx_getmotion(int x, int y, void *s);
#endif
