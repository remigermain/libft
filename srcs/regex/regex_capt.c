/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgermain <rgermain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:48:43 by rgermain          #+#    #+#             */
/*   Updated: 2019/10/11 19:23:29 by rgermain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void        ft_regex_free(t_regex *st)
{
    t_reg_list *tmp;
    t_reg_list *list;

    list = st->capt;
    while (list)
    {
        tmp = list;
        list = list->next;
        ft_memdel((void **)&(tmp->str));
        if (tmp->token)
            ft_memdel((void **)&(tmp->token));
        ft_memdel((void **)&tmp);
    }
}

static void regex_put_arg_list(t_regex *st, t_reg_list *list)
{
    t_reg_list **head;

    head = &(st->capt);
    while (*head)
    {
        if ((*head)->start == list->start && (*head)->end == list->end)
        {
            ft_memdel((void **)list);
            return;
        }
        if ((*head)->start >= list->start)
            break;
        head = &(*head)->next;
    }
    list->next = *head;
    *head = list;
    list->pos = st->nb_capt++;
}

void        regex_put_arg(t_regex *st, const char *s1, int len, char *token)
{
    t_reg_list *list;

    if (!(list = (t_reg_list *)ft_memalloc(sizeof(t_reg_list))) ||
        (!(list->str = ft_strsub(s1, 0, len))))
    {
        st->error = ERROR_REGEX;
        if (list)
            ft_memdel((void **)&list);
        return;
    }
    list->token = token;
    list->start = st->len_s1 - ft_strlen(s1);
    list->end = list->start + len;
    list->level = st->level;
    regex_put_arg_list(st, list);
}