/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   timestamp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/28 03:02:46 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/28 03:25:24 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_time	timestamp(long time)
{
	t_time	st;

	ft_bzero(&st, sizeof(t_time));
	st.year = time / (60 * 60 * 24 * 31 * 12);
	st.month = (time / (60 * 60 * 24 * 31)) % 12;
	st.day = (time / (60 * 60 * 24)) % 31;
	st.hour = (time / (60 * 60)) % 24;
	st.minute = (time / 60) % 60;
	st.seconde = time % 60;
	return (st);
}
