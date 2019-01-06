/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 18:10:38 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 15:59:09 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# define UCHAR unsigned char
# define ULONG unsigned long

# define ABS(a)				(a < 0 ? -a : a)
# define MAX(a, b)			(a < b ? b : a)
# define MIN(a, b)			(a < b ? a : b)

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
UCHAR			*ft_ustrdup(unsigned char *s1);
UCHAR			*ft_strudup(char *s1);
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
int				ft_putchar(char c);
int				ft_putchar_fd(char c, int fd);
int				ft_putpchar_fd(char c, int fd);
int				ft_putwchar(wchar_t c);
int				ft_putwchar_fd(wchar_t c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_base(int n, int base);
void			ft_putnbr_fd(int n, int fd);
int				ft_putstr(char const *str);
int				ft_putnstr(char const *str, int len);
int				ft_putstr_fd(char const *s, int fd);
int				ft_putnstr_fd(char const *s, int len, int fd);
int				ft_putpstr_fd(char const *s, int fd);
int				ft_putpnstr_fd(char const *s, int len, int fd);
int				ft_putstrw(wchar_t const *str);
int				ft_putnstrw(wchar_t const *str, int len);
int				ft_putstrw_fd(wchar_t const *s, int fd);
int				ft_putnstrw_fd(wchar_t const *s, int len, int fd);
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
int				ft_islowercase(char c);
int				ft_isuppercase(char c);
int				ft_str_is_numeric(char *str);
int				ft_str_is_printable(char *str);
int				ft_str_is_uppercase(char *str);
char			*ft_strcapitalize(char *str);
char			*ft_strlowcase(char *str);
char			*ft_strupcase(char *str);
char			*ft_itoa_base(int n, int base);
int				ft_isspace(char c);
int				ft_isblank(int i);
int				ft_iscntrl(char c);
int				ft_isgraph(char c);
int				ft_isxdigit(char c);
void			ft_printtab(char **tab);
void			ft_printtab_fd(char **tab, int fd);
int				ft_maxlen_tab(char **tab, int index);
char			*ft_strncpychr(const char *str, int c);
char			*ft_strcpychr(const char *str, int c);
int				ft_intlen_base(int nb, int base);
int				ft_intlen(int nb);
char			**ft_createtab(int nb, char c);
size_t			ft_strnlen(const char *str, size_t max);
size_t			ft_ustrlen(const unsigned char *str);
size_t			ft_ustrnlen(const unsigned char *str, size_t max);
int				len_wchar_single(wchar_t c);
int				len_wchar(wchar_t *wstr);
int				nlen_wchar(wchar_t *wstr, size_t len);
void			convert_wchar(unsigned char **new, wchar_t wc, size_t *i);
size_t			len_wuchart(unsigned char *str);

#endif
