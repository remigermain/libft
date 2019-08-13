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

static void usage_flag_text(char fl)
{
    char    *text;
    int     i;
    int     j;

    i = 0;
    text = init_usage(NULL);
    ft_printf("\t-%c", fl);
    while(text && text[i])
    {
        if(text[i] == fl)
        {
            j = ft_spancharspace(text + i + 2, "|");
            ft_printf("\t%.*s\n", j, text + i + 2);
            break ;
        }
        i += ft_spancharspace(text + i + 2, "|") + 3;
    }
    ft_printf("\n");
}

static int  usage_option(char *flag)
{
    t_finfo it;

    ft_bzero(&it, sizeof(t_finfo));
    parse_typeoption(&it, flag);
    if (it.isset & OP_MAX)
        ft_printf(" min: %d ", it.min);
    if (it.isset & OP_MIN)
        ft_printf(" max: %d ", it.max);
    if (it.isset & OP_PATTERN)
        ft_printf(" pattern: %s ", it.str);
    ft_printf(">\n");
    return (span_option(flag));
}

static int  usage_type(char *flag)
{
    int i;
    int j;

    i = 0;
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
            i += usage_option(flag + i + j) + j;
			i += ft_spantype(flag + i, ft_isspace);
		}
	}
    ft_printf("\n");
	return (i + (flag[i] == '}' ? 1 : 0));
}

char   *init_usage(char *str)
{
    static char *text = NULL;

    if (!text)
        text = str;
    return (text);
}

void        print_usage(t_flag *st)
{
    int     i;

    i = 0;
    ft_printf("%s usage\n\n\t[ FLAGS ]\n", st->argv[0]);
    while (st->flag[i] && st->flag[i] != '|')
		usage_flag_text(st->flag[i++]);
    ft_printf("\n\t[ FLAGS With ARGV ]\n\n");
	while (st->flag[++i])
	{
		if (i > 0 && st->flag[i - 1] == '|')
        {
            usage_flag_text(st->flag[i++]);
            i += usage_type(st->flag + i);
        }
        else
		    i += span_alloption(st->flag + i);
	}
    ft_printf("\n");
    exit(0);
}