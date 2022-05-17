/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:35:50 by kko               #+#    #+#             */
/*   Updated: 2022/05/17 22:34:52 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*reset_s(char *save, t_list *lst_buf)
{
	char	*ret;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(lst_buf->buf);
		free(lst_buf);
		return (0);
	}
	ret = (char *)malloc(sizeof(char) + ft_strlen(save) - i + 1);
	if (!ret)
		return (0);
	i++;
	while (save[i])
		ret[j++] = save[i++];
	ret[j] = 0;
	free(save);
	return (ret);
}

char	*get_line(char *save)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!save[i])
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	ret = (char *)malloc(sizeof(char) * i + 2);
	if (!ret)
		return (0);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		ret[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		ret[i] = '\n';
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*read_buf(int fd)
{
	char	*buf;
	char	*save;
	ssize_t	i;

	save = 0;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	i = read(fd, buf, BUFFER_SIZE);
	while (i > 0)
	{
		buf[i] = 0;
		save = ft_strjoin(save, buf);
		if (ft_strchr(save, '\n'))
			break ;
		i = read(fd, buf, BUFFER_SIZE);
	}
	if (i <= 0)
	{
		free(buf);
		return (0);
	}
	free(buf);
	return (save);
}

t_list	*find_fd(t_list *lst_buf, int fd)
{
	t_list	*new;

	lst_buf = lst_buf->next;
	while (lst_buf)
	{
		if (lst_buf->fd == fd)
			return (lst_buf);
		else if (lst_buf->next == 0)
			{
				new = new_lst(fd);
				lst_buf->next = new;
				return(new);
			}
		lst_buf = lst_buf->next;
	}
	return (lst_buf);
}

t_list	*new_lst(int fd)
{
	t_list	*lst_buf;

	lst_buf = (t_list *)malloc(sizeof(t_list));
	if (!lst_buf)
		return (0);
	lst_buf->fd = fd;
	lst_buf->next = 0;
	lst_buf->buf = read_buf(fd);
	if (!lst_buf->buf)
	{
		free(lst_buf);
		return (0);
	}
	return (lst_buf);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (lst == 0)
	{
		lst = (t_list *)malloc(sizeof(t_list));
		if (!lst)
			return (0);
		lst->next = 0;
	}
	return (ret);
}
