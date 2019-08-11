/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse_argv.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/20 16:19:09 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/20 16:26:06 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char   *text_usage(char *str)
{
    static char *text = NULL;

    if (!text)
        text = str;
    return (text);
}

void    print_text_flag(char fl)
{
    char    *text;
    int     i;
    int     j;

    text = text_usage(NULL);
    i = 0;
    ft_printf("\t-%c", fl);
    if (text)
    {
        while(text[i])
        {
            if(text[i] == fl)
            {
                i += 2;
                j = ft_spancharspace(text + i, "|");
                ft_printf("\t%.*s\n", j, text + i);
                break ;
            }
            else
                i += 2;
            i += ft_spancharspace(text + i, "|") + 1;
        }
    }
    ft_printf("\n");
}

int parse_usageoption2(t_flag *st, char *flag)
{
    t_finfo it;
    int     i;

    i = 0;
    ft_bzero(&it, sizeof(t_finfo));
    i = parse_typeoption(st, &it, flag);
    if (it.isset & 0x1)
        ft_printf(" min: %d ", it.min);
    if (it.isset >> 1 & 0x1)
        ft_printf(" max: %d ", it.max);
    if (it.isset >> 2 & 0x1)
        ft_printf(" pattern: %s ", it.str);
    ft_printf(">\n");
    return (ft_spanoption(flag));
}

int parse_usageoption(t_flag *st, char *flag)
{
    int i;
    int j;

    i = 0;
    j = -1;
	if (flag[i] == '{' && (++i))
	{
		while (flag[i] && flag[i] != '}' && flag[i] != ';')
		{
			if (flag[i] == ',')
				i++;
            ft_printf("\t\t");
			i += ft_spantype(flag + i, ft_isspace);
	        j = ft_spancharspace(flag + i, ",}{");
            if (!ft_strncmp(flag + i, "int", 3))
                ft_printf("< number ");
		    else if (!ft_strncmp(flag + i, "char*", 5))
                ft_printf("< string ");
		    else if (!ft_strncmp(flag + i, "char", 4))
                ft_printf("< character ");
            i += parse_usageoption2(st, flag + i + j) + j;
			i += ft_spantype(flag + i, ft_isspace);
		}
	}
	if (flag[i] == '}')
		i++;
    ft_printf("\n");
	return (i);
}

void       print_usage(t_flag *st)
{
    char    *text;
    int     i;
    int     j;

    text = text_usage(NULL);
    i = 0;
    ft_printf("%s usage\n\n\t[ FLAGS ]\n", st->argv[0]);
    while (st->flag[i] && st->flag[i] != '|')
		print_text_flag(st->flag[i++]);
    ft_printf("\n\t[ FLAGS With ARGV ]\n\n");
	while (st->flag[++i])
	{
		if (i > 0 && st->flag[i - 1] == '|')
        {
            print_text_flag(st->flag[i++]);
            i += parse_usageoption(st, st->flag + i);
        }
        else
		    i += span_alloption(st, st->flag + i);
	}
    ft_printf("\n");
}