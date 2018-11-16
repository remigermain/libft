/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 18:10:38 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 09:21:51 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line.h"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

char			*ft_itoa(int n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strtrim(char const *s);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *hstack, const char *need, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			**ft_strsplit(const char*s, char c);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t size);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memalloc(size_t size);
void			ft_bzero(void *s, size_t n);
void			ft_memdel(void **ap);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_base(int n, int base);
void			ft_putnbr_fd(int n, int fd);
int				ft_putstr(char const *str);
int				ft_putstr_fd(char const *s, int fd);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_atoi(const char *str);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
t_list			*ft_lstmap(t_list *lst, t_list*(*f)(t_list *elem));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
t_list			*ft_lstnew(void const *content, size_t content_size);

void			ft_sort_integer_table(int *tab, int size);
void			ft_swap(int *a, int *b);
int				ft_is_prime(int nb);
int				ft_find_next_prime(int nb);
int				ft_is_prime(int nb);
int				ft_iterative_factorial(int nb);
int				ft_iterative_power(int nb, int power);
int				ft_recursive_factorial(int nb);
int				ft_recursive_power(int nb, int power);
int				ft_sqrt(int nb);
char			*ft_strrev(char *str);
int				ft_match(char *s1, char *s2);
size_t			ft_strlcpy(char *s1, const char *s2, size_t size);
int				ft_str_is_alpha(char *str);
int				ft_str_is_lowercase(char *str);
int				ft_str_is_numeric(char *str);
int				ft_str_is_printable(char *str);
int				ft_str_is_uppercase(char *str);
char			*ft_strcapitalize(char *str);
char			*ft_strlowcase(char *str);
char			*ft_strupcase(char *str);
char			*ft_itoa_base(long n, int base, int maj);
int				ft_isspace(char c);
int				ft_isblank(int i);
int				ft_iscntrl(char c);
int				ft_isgraph(char c);
int				ft_isxdigit(char c);
void			ft_printtab(char **tab);
char			*ft_strncpychr(const char *str, int c);
char			*ft_strcpychr(const char *str, int c);
int				ft_intlen_base(int nb, int base);
int				ft_intlen2(int nb);
int				ft_intlen2_base(int nb, int base);
int				ft_intlen(long nb);
char			**ft_createtab(int nb, char c);
int				ft_abs(int nb);
long int		ft_labs(long int nb);
void			ft_putnbr_base_long(long nb, int base);
void			ft_putnbr_base_lmaj(long nb, int base, int maj);
void			ft_putnbr_base_ulmaj(unsigned long nb, unsigned long base, int maj);
int				ft_putnstr(char const *s, int len);
int				ft_putnstr_fd(char const *s, int fd, int len);
int				ft_nbmax(int nb1, int nb2);
int				ft_nbmin(int nb1, int nb2);
void			ft_putunbr(unsigned int);
void			ft_putnbr2_fd(int nb, int fd);
void			ft_putnbr2(int nb);
void			ft_putunbr_fd(unsigned int, int fd);
void			ft_putulnbr(unsigned long int nb);
void			ft_putulnbr_base(unsigned long int nb, unsigned long int base);
void			ft_putulnbr_fd(unsigned long int nb, int fd);
int 			ft_ullen(unsigned long int nb);
int 			ft_ullen_base(unsigned long int nb, unsigned long int base);
int 			ft_llen_base(long int nb, int base);
int	 			ft_llen(long int nb);
void			ft_putlnbr(long int nb);
void			ft_putlnbr_fd(long int nb, int fd);
int				ft_uintlen(unsigned int nb);
int				ft_uintlen_base(unsigned int nb, unsigned int base);

#endif
