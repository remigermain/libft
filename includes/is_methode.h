/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   is_methode.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <rgermain@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 18:10:38 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/02 18:57:13 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef IS_METHODE_H
# define IS_METHODE_H

t_bool	ft_isalnum(int c);
t_bool	ft_isalpha(int c);
t_bool	ft_isascii(int c);
t_bool	ft_isblank(int c);
t_bool	ft_iscntrl(int c);
t_bool	ft_isdigit(int c);
t_bool	ft_isgraph(int c);
t_bool	ft_isprint(int c);
t_bool	ft_isspace(int c);
t_bool	ft_isxdigit(int c);
t_bool	ft_islowercase(int c);
t_bool	ft_isuppercase(int c);
t_bool	ft_isword(int c);
char	ft_tolower(int c);
char	ft_toupper(int c);

#endif
