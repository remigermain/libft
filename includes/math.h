/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 18:10:38 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/31 18:26:52 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H
# define ABS(a)				(a < 0 ? -a : a)
# define MAX(a, b)			(a < b ? b : a)
# define MIN(a, b)			(a < b ? a : b)
# define HEX_16 16
# define DEC 10
# define OCTAL 8
# define BIN 2
# define IS_CHAR(nb)         (nb > CHAR_MAX || nb < CHAR_MIN ? FALSE : TRUE)
# define IS_UCHAR(nb)         (nb > UCHAR_MAX || nb < 0 ? FALSE : TRUE)
# define IS_SHRT(nb)         (nb > SHRT_MAX || nb < SHRT_MIN ? FALSE : TRUE)
# define IS_USHRT(nb)         (nb > USHRT_MAX || nb < 0 ? FALSE : TRUE)
# define IS_INT(nb)         (nb > INT_MAX || nb < INT_MIN ? FALSE : TRUE)
# define IS_UINT(nb)         (nb > UINT_MAX || nb < 0 ? FALSE : TRUE)
# define IS_LONG(nb)         (nb > LONG_MAX || nb < LONG_MIN ? FALSE : TRUE)
# define IS_ULONG(nb)         (nb > ULONG_MAX || nb < 0 ? FALSE : TRUE)

int	ft_find_next_prime(int nb);
int ft_intlen_base(int nb, int base);
int ft_intlen(int n);
int ft_is_prime(int nb);
int ft_iterative_factorial(int nb);
int ft_iterative_power(int nb, int power);
int ft_recursive_factorial(int nb);
int ft_recursive_power(int nb, int power);
int ft_sqrt(int nb);

#endif
