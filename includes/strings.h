/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 18:10:38 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/23 19:31:28 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef STRINGS_H
# define STRINGS_H
# include "limit.h"

t_bool  ft_base_string(char letter, int base);
double  ft_atof_base(const char *str, int base);
double  ft_atof(const char *str);
long	ft_atol_base(const char *str, int base);
long    ft_atol(const char *str);
int	    ft_atoi_base(const char *str, int base);
int	    ft_atoi(const char *str);
void	ft_itoabase_buffer(char *buff, int nb2, int base);
char	*ft_itoa_base(int nb, int base);
void	ft_itoa_buffer(char *buff, int nb);
void	ft_itoabuffer(char *buff, int nb);
char	*ft_itoa(int n);
int		ft_spantype(char *str, t_bool (*func)(int));
int		ft_spanchar(char *flag, char *str);
int		ft_spancharspace(char *flag, char *str);
char	*ft_strcapitalize(char *str);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);
void	ft_strclr(char *str);
int	    ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strcpychr(const char *s, int c);
void	ft_strdel(char **as);
char	*ft_strdup(const char *s1);
int		ft_strequ(char const *s1, char const *s2);
int	    ft_str_is_alpha(char *str);
int	    ft_str_is_lowercase(char *str);
t_bool	ft_str_is_numeric(char *str);
t_bool	ft_str_is_printable(char *str);
t_bool	ft_str_is_uppercase(char *str);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strlowcase(char *str);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strncpychr(const char *s, int c);
int	    ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strnew(size_t size);
size_t	ft_strnlen(const char *s, size_t max);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char    *ft_strpbrk(const char *s1, const char *s2);
char	*ft_strrev(char *str);
char	**ft_strsplit(const char *str, char c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char    *ft_strtok(char *s1, const char *delim);
char	*ft_strtrim(char const *s);
char	*ft_strupcase(char *str);
size_t  ft_strxfrm(char *dest, const char *src, size_t n);
void	ft_tabdel(char ***ap);

#endif
