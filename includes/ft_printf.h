/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:40:59 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/06 23:04:15 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include "color.h"
# include <stdarg.h>
# include <errno.h>

# define BUFF_PRINTF 128
# define BUFF_FLOAT 256

/*
** raccourcie list
*/
# define EXPONENT lst->exponent
# define HASH lst->hash
# define SPACE	lst->space
# define ZERO lst->zero
# define SIGN lst->sign
# define LOCAL lst->local
# define FIELD lst->field
# define POINT lst->point
# define PRECI lst->preci
# define MAJ lst->maj
# define PSIGN lst->psign
# define BASE lst->base
# define LENGHT lst->lenght
# define CONV lst->conv

typedef struct	s_printf
{
	va_list			va_lst;
	va_list			va_copy;
	int				buff_count;
	UCHAR			buff[BUFF_PRINTF];
	int				count;
	UCHAR			*str;
	ULONG			ul_nb;
	ULONG			ful_nb;
	long double		fl_nb;
	int				exponent;
	size_t			hash;
	size_t			space;
	size_t			zero;
	size_t			sign;
	size_t			local;
	int				field;
	size_t			point;
	int				preci;
	size_t			maj;
	size_t			psign;
	size_t			base;
	size_t			lenght;
	char			conv;
}				t_pf;

/*
**	fonctions main de ft_printf
**	ft_printf.c
*/
int				ft_printf(const char *str, ...);
int				ft_dprintf(int fd, const char *str, ...);
int				ft_sprintf(UCHAR **dest, const char *format, ...);
int				find_conv(t_pf *lst, char *str, int ret);

/*
** fonctions des differentes convertion
** conv_*.c
*/
void			conv_char(t_pf *lst);
void			conv_int(t_pf *lst);
void			conv_string(t_pf *lst);
void			conv_double(t_pf *lst);
void			conv_other(t_pf *lst);
int				conv_tabstring(t_pf *lst);
int				conv_color(t_pf *lst, char *str);

/*
** initialisation lst && fonction pour ajouter les differentes options
** lst_init.c && lst_base.c && lst_initnb.c
*/
t_pf			*lst_init(void);
int				lst_putoption(t_pf *lst, char *str, int index);
void			lst_zero(t_pf *lst);
void			lst_putdollar(t_pf *lst, int len);
void			lst_putint(t_pf *lst);
void			lst_putdouble(t_pf *lst);

/*
** fonctions len_nbr , len no_print char && convert in print, put color
**	utils.c
*/
void			ftprintf_error(t_pf *lst, char *str, size_t index);
int				ulen_base(ULONG nb, size_t base);
size_t			len_pstrn(UCHAR *str, size_t len, size_t index);

/*
**	fonctions qui put les signes( - , + , 0x )
**			 ajoute les esapces et zero des precisions/field
**				join le str entre eux && ULONG itoa avec local
**	utils_put.c
*/
void			convert_buff(t_pf *lst, void *tmp, size_t len);
void			put_buff(t_pf *lst, void *tmp, size_t len, size_t index);
void			put_itoa(t_pf *lst, ULONG n);
void			put_prefix(t_pf *lst, int len, int nb, int point);
void			put_sign(t_pf *lst);

/*
** fonction de debug de la list
**	debug.c
*/
void			debug(t_pf *lst);

#endif
