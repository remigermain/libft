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
#if defined(__APPLE__)
# define INTMAX_T intmax_t
#else
# define INTMAX_T long long
#endif

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

enum	e_pf
{
	PF_FREE,
	NO_FREE,
};

# define PF_HASH(fl) (fl & (1 << HASH) ? TRUE : FALSE)
# define PF_SPACE(fl) (fl & (1 << SPACE) ? TRUE : FALSE)
# define PF_ZERO(fl) (fl & (1 << ZERO) ? TRUE : FALSE)
# define PF_SIGN_NEG(fl) (fl & (1 << SIGN_NEG) ? TRUE : FALSE)
# define PF_SIGN_POS(fl) (fl & (1 << SIGN_POS) ? TRUE : FALSE)
# define PF_LOCAL(fl) (fl & (1 << LOCAL) ? TRUE : FALSE)
# define PF_POINT(fl) (fl & (1 << POINT) ? TRUE : FALSE)
# define PF_MAJ(fl) (fl & (1 << MAJ) ? TRUE : FALSE)
# define PRINT_PF(fl)	(fl & (1 << PRINT) ? TRUE : FALSE)
# define POINT_PF(fl)	(fl & (1 << POINT) ? TRUE : FALSE)
# define PF_STRING(conv) (conv == 's' || conv == 'S' || conv == 'r' || \
											conv == 'm' ? TRUE : FALSE)
# define LEN_PSIGN(sign) (sign == P_SIGN_HEX ? 2 : PF_NO_SIGN(sign) ? 1 : 0)
# define BASE_16(conv) (conv == 'x' || conv == 'X' || conv == 'p' || \
							conv == 'a' || conv == 'A' ? TRUE : FALSE)
# define BASE_8(conv) (conv == 'o' || conv == 'O' ? TRUE : FALSE)
# define BASE_2(conv) (conv == 'b' || conv == 'B' || conv == 'r' || \
											conv == 'm' ? TRUE : FALSE)
# define LENGH_L(fl)	(fl & (1 << CAST_L) ? TRUE : FALSE)
# define LENGH_L_MAJ(fl)	(fl & (1 << CAST_L_MAJ) ? TRUE : FALSE)
# define LENGH_LL(fl)	(fl & (1 << CAST_LL) ? TRUE : FALSE)
# define LENGH_H(fl)	(fl & (1 << CAST_H) ? TRUE : FALSE)
# define LENGH_HH(fl)	(fl & (1 << CAST_HH) ? TRUE : FALSE)
# define LENGH_Z(fl)	(fl & (1 << CAST_Z) ? TRUE : FALSE)
# define LENGH_J(fl)	(fl & (1 << CAST_J) ? TRUE : FALSE)
# define LENGH_NO(fl)	(LENGH_J(fl) || LENGH_Z(fl) || LENGH_HH(fl) || \
LENGH_H(fl) || LENGH_L_MAJ(fl) || LENGH_L(fl) || LENGH_LL(fl) ? TRUE : FALSE)

typedef struct	s_pf_flag
{
	t_ulong			ul_nb;
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
int				ulen_base(t_ulong nb, size_t base);
void			put_itoa(t_pf *lst, t_ulong n);
void			st_putdouble(t_pf *st);
void			conv_int(t_pf *st);
void			conv_other(t_pf *st);
void			conv_char(t_pf *st);
void			conv_string(t_pf *st);
int				conv_tabstring(t_pf *st);
void			conv_double(t_pf *lst, t_ulong *nb, int i);

#endif
