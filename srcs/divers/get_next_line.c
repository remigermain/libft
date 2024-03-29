/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <rgermain@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 12:51:10 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/02 18:06:57 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_find_fd(t_list **list, int fd)
{
	t_list	*list_temp;

	list_temp = *list;
	while (list_temp && list_temp->content_size != (size_t)fd)
		list_temp = list_temp->next;
	if (list_temp == NULL)
	{
		if (!(list_temp = ft_lstnew(NULL, 0)))
			return (NULL);
		list_temp->content_size = (size_t)fd;
		ft_lstadd(list, list_temp);
	}
	return (list_temp);
}

static int		ft_read_fd(int fd, t_list *list)
{
	int		ret;
	char	*buff;
	char	*temp;

	ret = 0;
	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	if ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (!list->content)
			list->content = ft_strdup(buff);
		else
		{
			if (!(temp = ft_strjoin(list->content, buff)))
			{
				ft_strdel(&buff);
				return (-1);
			}
			ft_memdel(&list->content);
			list->content = temp;
		}
	}
	free(buff);
	return (ret);
}

static int		free_lst(t_list *list)
{
	t_list *tmp;

	tmp = list->next;
	free(list);
	list = tmp;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*p_list = NULL;
	t_list			*list;
	char			*temp;
	int				ret;

	ret = 1;
	if (fd < 0 || line == NULL || (read(fd, NULL, 0) < 0))
		return (-1);
	if (!(list = ft_find_fd(&p_list, fd)))
		return (-1);
	while (((!list->content || (ft_strchr(list->content, '\n') == NULL))
			&& ret > 0))
		ret = ft_read_fd(fd, list);
	if (ret == -1)
		return (-1);
	*line = ft_strcpychr(list->content, '\n');
	if (*line == NULL || (ret < BUFF_SIZE && ft_strlen(list->content) == 0))
		return (free_lst(list));
	temp = ft_strncpychr(list->content, '\n');
	ft_memdel(&list->content);
	list->content = temp;
	return (1);
}
