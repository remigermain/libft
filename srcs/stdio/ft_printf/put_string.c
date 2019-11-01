/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   malloc_string.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/04 16:39:10 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/10 14:29:21 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_buff(t_pf *st, void *tmp, size_t len)
{
	if (st->buff_count)
		write(st->fd, st->buff, st->buff_count);
	if (len)
		write(st->fd, tmp, len);
	st->buff_count = 0;
}

void	convert_buff(t_pf *st, void *tmp, size_t len)
{
	unsigned char	*new;
	size_t			len_malloc;

	len_malloc = st->str_count + st->buff_count + len + 1;
	if (!(new = (unsigned char*)ft_memalloc(sizeof(char) * len_malloc)))
		ftprintf_error(st, "comvert_buff", 1);
	new[st->str_count + st->buff_count + len] = '\0';
	ft_memcpy(new, st->str, st->str_count);
	ft_memcpy(new + st->str_count, st->buff, st->buff_count);
	if (len > 0)
		ft_memcpy(new + st->str_count + st->buff_count, tmp, len);
	if (st->str != NULL)
		ft_memdel((void**)&(st->str));
	st->str = new;
	st->str_count += st->buff_count + len;
	st->buff_count = 0;
}

void	put_buff(t_pf *st, void *tmp, size_t len, enum e_pf mod)
{
	if (len == 0)
		return ;
	if (((st->buff_count + len) >= BUFF_PRINTF))
	{
		if (st->is_print)
			print_buff(st, tmp, len);
		else
			convert_buff(st, tmp, len);
	}
	else
	{
		ft_memcpy(st->buff + st->buff_count, tmp, len);
		st->buff_count += len;
	}
	if (mod & PF_FREE)
		ft_memdel((void**)&tmp);
}

void	put_itoa(t_pf *st, intmax_t n)
{
	unsigned char	tmp[27];
	int				len;
	int				mlen;

	len = ulen_base(n, st->op.base);
	if (st->op.flag & PF_LOCAL && len > 3)
		len += ((len / 3) - (len % 3 == 0 ? 1 : 0));
	mlen = len--;
	while (len >= 0)
	{
		if (st->op.flag & PF_LOCAL && ((mlen - len) % 4 == 0))
			tmp[len--] = ',';
		if ((n % st->op.base) < 10)
			tmp[len--] = (n % st->op.base) + 48;
		else
			tmp[len--] = (n % st->op.base) +
				(st->op.flag & PF_MAJ ? 55 : 87);
		n = n / st->op.base;
	}
	put_buff(st, tmp, mlen, 0);
}

void	put_prefix(t_pf *st, int len, int nb, t_bool point)
{
	size_t	llen;
	t_uchar	*tmp;

	llen = (nb - len);
	if (len >= nb)
		return ;
	if ((llen + st->buff_count) >= BUFF_PRINTF)
	{
		if (!(tmp = (t_uchar*)ft_memalloc(llen + 1)))
			ftprintf_error(st, "put_prefix", 1);
		ft_memset(tmp, (point ? '0' : ' '), llen);
		put_buff(st, tmp, llen, 1);
	}
	else
	{
		ft_memset(st->buff + st->buff_count, (point ? '0' : ' '), llen);
		st->buff_count += llen;
	}
}
