/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 15:33:33 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 21:05:54 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_one_char(char *str, int a, int c)
{
	int 	len;
	int 	b;
	int		d;
	char	*new;

	b = 0;
	d = 0;
	len = ft_strlen(str);
	if (!(new = ft_strnew(len - 1)))
		return ("(null)");
	while (len > 0)
	{
		if (b == (a - 1))
		{
			new[b + d] = (char)c;
			d = - 1;
			b += 2;
			len--;
		}
		else
		{
			new[b + d] = str[b];
			b++;
			len--;
		}
		
	}
	return (new);
}

char	*ft_signed_string(char *str, int a, va_list list)
{
	char		*temp;
	char		*str2;
	char		*new;

	new = va_arg(list, char *);
	if (new == NULL)
		new = "(null)";
	temp = ft_strjoin(ft_strsub(str, 0, (a - 1)), new);
	str2 = ft_strjoin(temp, ft_strsub(str, (a + 1), ft_strlen(str) - (a + 1)));
	free(temp);
	return (str2);
}

char	*ft_unsigned_int(char *str, int a, va_list list)
{
	char		*temp;
	char		*str2;;
	char		*new;
	long			nb;
	int 		maj;

	nb = va_arg(list, long);
	if (nb == -2147483648)
		nb = 2147483648;
	else if (nb < 0)
		nb = ((4294967295 + nb) + 1);
	if (str[a] == 'x')
		maj = 0;
	else
		maj = 1;
	new = ft_itoa_base(nb, 10, maj);
	temp = ft_strjoin(ft_strsub(str, 0, (a - 1)), new);
	str2 = ft_strjoin(temp, ft_strsub(str, (a + 1), ft_strlen(str) - (a + 1)));
	free(temp);
	return (str2);
}

char	*ft_signed_int(char *str, int a, va_list list, int base)
{
	char		*temp;
	char		*str2;;
	long			nb;
	int 		maj;

	nb = (long)va_arg(list, int);
	if (str[a] == 'x')
		maj = 0;
	else
		maj = 1;
	temp = ft_strjoin(ft_strsub(str, 0, (a - 1)), ft_itoa_base(nb, base, maj));
	str2 = ft_strjoin(temp, ft_strsub(str, (a + 1), ft_strlen(str) - (a + 1)));
	free(temp);
	return (str2);
}
char	*ft_double_params(char *str, int a)
{
	char		*str2;;
	
	str2 = ft_add_one_char(str, a, 37);
	return (str2);
}


char	*ft_signed_char(char *str, int a, va_list list)
{
	char		*str2;
	int			c;

	c = va_arg(list, int);
	str2 = ft_add_one_char(str, a, c);
	return (str2);
}

char	*ft_adress(char *str, int a, va_list list)
{
	char		*temp;
	char		*temp2;
	char		*str2;;
	long			nb;

	nb = va_arg(list, long);
	temp = ft_strjoin("0x", ft_itoa_base(nb, 16, 0));
	temp2 = ft_strjoin(ft_strsub(str, 0, (a - 1)), temp);
	free(temp);
	str2 = ft_strjoin(temp2, ft_strsub(str, (a + 1), ft_strlen(str) - (a + 1)));
	free(temp2);
	return (str2);
}

char	*find_params(char *str, int a, va_list list)
{

	if (str[a] == 'd' || str[a] == 'i' || str[a] == 'I')   // signed intt
		str = ft_signed_int(str, a, list, 10);
	else if (str[a] == 'o' || str[a] == 'O')
		str = ft_signed_int(str, a, list, 8);
	else if (str[a] == 'x' || str[a] == 'X')
		str = ft_unsigned_int(str, a, list);
	
	else if (str[a] == 'u' || str[a] == 'U' || str[a] == 'D')
		str = ft_unsigned_int(str, a, list);
	else if (str[a] == 'c' || str[a] == 'C')
		str = ft_signed_char(str, a, list);	
	else if (str[a] == 's' || str[a] == 'S')
		str = ft_signed_string(str, a, list); 

	/*
	else if (str[a] == 'f')				//double
	else if (str[a] == ('e' || 'E'))		//double
	else if (str[a] == ('g' || 'G'))		//double*/

	else if (str[a] == 'p')				
		str = ft_adress(str, a, list);

/*
	else if (str[a] == 'n')			//len of printf print*/
	else if (str[a] == '%')
		str = ft_double_params(str, a);	
	return (str);
}

int		ft_printf(const char *str, ...)
{
	va_list		list;
	char		*new;
	int 		a;
	
	a = 0;
	va_start(list, str);
	new = (char *)str;
	while (new[a] != '\0')
	{
		if (new[a] == '%')
			new = find_params(new, (a + 1), list);
		a++;
	}
	ft_putstr(new);
	return (ft_strlen(new));
}
