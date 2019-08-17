/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:40:59 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/20 16:23:24 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# include "color.h"
# define BUFF_PRINTF 10000
# define KEEP_PF	1
# define OUT_PF	0
# define PF_HASH 		(1 << HASH)
# define PF_SPACE		(1 << SPACE)
# define PF_ZERO		(1 << ZERO)
# define PF_SIGN_NEG	(1 << SIGN_NEG)
# define PF_SIGN_POS	(1 << SIGN_POS)
# define PF_LOCAL 		(1 << LOCAL)
# define PF_POINT 		(1 << POINT)
# define PF_MAJ 		(1 << MAJ)
# define PRINT_PF		(1 << PRINT)
# define POINT_PF		(1 << POINT)
# define LENGH_L		(1 << CAST_L)
# define LENGH_L_MAJ	(1 << CAST_L_MAJ)
# define LENGH_LL		(1 << CAST_LL)
# define LENGH_H		(1 << CAST_H)
# define LENGH_HH		(1 << CAST_HH)
# define LENGH_Z		(1 << CAST_Z)
# define LENGH_J		(1 << CAST_J)
# define LEN_PSIGN(sign) (sign == P_SIGN_HEX ? 2 : PF_NO_SIGN(sign) ? 1 : 0)
# define LENGH_NO(fl)	(LENGH_J(fl) || LENGH_Z(fl) || LENGH_HH(fl) || \
LENGH_H(fl) || LENGH_L_MAJ(fl) || LENGH_L(fl) || LENGH_LL(fl) ? TRUE : FALSE)

enum	e_cast_pf
{
	HASH = 1,
	SPACE,
	ZERO,
	SIGN_NEG,
	SIGN_POS,
	LOCAL,
	POINT,
	MAJ,
	P_SIGN_NEG,
	P_SIGN_POS,
	P_SIGN_HEX,
	CAST_L,
	CAST_L_MAJ,
	CAST_LL,
	CAST_H,
	CAST_HH,
	CAST_Z,
	CAST_J,
};

enum	e_pf_float
{
	FLOAT_START,
	FLOAT_END,
	F_POS,
	F_NEG,
};

enum	e_pf
{
	PF_FREE,
	NO_FREE,
};

typedef struct	s_pf_flag
{
	uintmax_t		ul_nb;
	t_ulong			ful_nb;
	long double		fl_nb;
	int				exponent;
	int				field;
	int				preci;
	int				flag;
	int				base;
	enum e_cast_pf	lenght;
	char			*sign;
	char			conv;
}				t_pf_flag;

typedef struct	s_printf
{
	va_list		va_lst;
	va_list		va_copy;
	int			buff_count;
	int			str_count;
	int			fd;
	t_uchar		buff[BUFF_PRINTF];
	t_uchar		*str;
	t_bool		is_print;
	t_pf_flag	op;
}				t_pf;

/*
**	fonctions main de ft_printf
**	ft_printf.c
*/
int				ft_printf(const char *str, ...);
int				ft_stprintf(char ind, const char *str, ...);
int				ft_dprintf(int fd, const char *str, ...);
int				ft_sprintf(t_uchar **dest, const char *format, ...);
int				ftprintf_base(char *str, t_pf *st, size_t i, size_t j);
int				get_option(t_pf *lst, char *str, int count);
void			convert_buff(t_pf *st, void *tmp, size_t len);
void			put_buff(t_pf *st, void *tmp, size_t len, enum e_pf mod);
void			put_prefix(t_pf *st, int len, int nb, t_bool point);
void			ftprintf_error(t_pf *lst, char *str, size_t index);
int				ulen_base(uintmax_t nb, size_t base);
void			put_itoa(t_pf *st, intmax_t n);
void			st_putdouble(t_pf *st);
void			conv_int(t_pf *st);
void			conv_other(t_pf *st);
void			conv_char(t_pf *st);
void			conv_string(t_pf *st);
int				conv_tabstring(t_pf *st);
void			conv_double(t_pf *st);
void			mod_double(t_pf *st);

#endif
