/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 18:10:38 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/28 20:57:46 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef DIVERS_H
# define DIVERS_H

size_t	convert_wchar(unsigned char *new, wchar_t wc);
char	**ft_createtab(int len, char c);
void	ft_inttab_del(int **ap, int size);
int		ft_match(char *s1, char *s2);
void	ft_sort_integer_table(int *tab, int size);
void	ft_swap(int *a, int *b);
int		ft_maxlen_tab(char **tab, int index);
int		len_wchar(wchar_t *str);
int		len_wchar_single(wchar_t c);
int		nlen_wchar(wchar_t *str, size_t len);
t_time  timestamp(time_t time);
int     ft_getchar(void);

#endif
