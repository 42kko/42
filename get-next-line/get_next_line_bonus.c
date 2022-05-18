/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:35:50 by kko               #+#    #+#             */
/*   Updated: 2022/05/19 03:04:28 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
// #include <stdio.h>

// # define BUFFER_SIZE 43

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!dst && !src)
// 		return (0);
// 	while (i < n)
// 	{
// 		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
// 		i++;
// 	}
// 	return (dst);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*ret;
// 	size_t	size1;
// 	size_t	size2;

// 	if (!s1)
// 	{
// 		s1 = (char *)malloc(sizeof(char) * 1);
// 		s1[0] = 0;
// 	}
// 	if (!s1 || !s2)
// 		return (0);
// 	size1 = ft_strlen(s1);
// 	size2 = ft_strlen(s2);
// 	ret = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
// 	if (!ret)
// 		return (0);
// 	ft_memcpy(ret, s1, size1);
// 	ft_memcpy(ret + size1, s2, size2);
// 	ret[size1 + size2] = 0;
// 	free (s1);
// 	return (ret);
// }

// int	new_line(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\n')
// 	{
// 		if (s[i] == 0)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

t_list	*new_list(int fd)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->fd = fd;
	lst->buf = 0;
	lst->buf = read_buf(lst->buf, fd);
	if (!lst->buf)
	{
		free(lst);
		lst = 0;
		return (0);
	}
	lst->next = 0;
	return (lst);
}

t_list	*find_fd(t_list *head, int fd)
{
	t_list	*lst;
	t_list	*tmp;

	lst = head->next;
	while(lst)
	{
		if ((int)lst->fd == fd)
		{
			lst->buf = read_buf(lst->buf, fd);
			return(lst);
		}
		tmp = lst;
		lst = lst->next;
	}
	lst = new_list(fd);
	if (!lst)
		return (0);
	tmp->next = lst;
	return (lst);
}

t_list	*all_free(t_list *head)
{
	t_list	*lst;
	t_list	*tmp;

	lst = head->next;
	while(lst)
	{
		free(lst->buf);
		lst->buf = 0;
		lst = lst->next;
	}
	lst = head->next;
	while(lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
		tmp = 0;
	}
	free(head);
	head = 0;
	return (0);
}

size_t	num_list(t_list *head, t_list *lst)
{
	size_t	i;
	t_list	*tmp;

	i = 1;
	tmp = head->next;
	while (tmp)
	{
		if (tmp->fd == lst->fd)
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

char	*read_buf(char *save, int fd)
{
	char	*buf;
	ssize_t	i;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	i = read(fd, buf, BUFFER_SIZE);
	while (i > 0)
	{
		buf[i] = 0;
		save = ft_strjoin(save, buf);
		if (new_line(save))
		{
			break ;
		}
		i = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	buf = 0;
	return (save);
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
	if (save[i] == '\n')
		i++;
	ret = (char *)malloc(sizeof(char) * i + 1);
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

char	*reset_s(char *save)
{
	char	*ret;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	if (!save[i])
	{
		free(save);
		save = 0;
		return (0);
	}
	ret = (char *)malloc(sizeof(char) + ft_strlen(save) - i + 1);
	if (!ret)
		return (0);
	while (save[i])
	{
		ret[j] = save[i];
		j++;
		i++;
	}
	ret[j] = 0;
	free(save);
	save = 0;
	return (ret);
}

void	reset_list(t_list *head, t_list *lst, size_t i)
{
	t_list	*tmp1;
	t_list	*tmp2;
	size_t	j;

	j = 0;
	tmp1 = head;
	tmp2 = head;
	while(j < (i - 1))
	{
		tmp1 = tmp1->next;
		j++;
	}
	while(j < (i + 1))
	{
		tmp2 = tmp2->next;
		j++;
	}
	tmp1->next = tmp2;
	free(lst);
	lst = 0;
	return ;
}

int	arrange(t_list *head, t_list *lst)
{
	size_t	len;
	size_t	i;
	t_list	*tmp;

	len = 0;
	tmp = head->next;
	while(tmp)
	{
		len++;
		tmp = tmp->next;
	}
	i = num_list(head, lst);
	if (len == 1)
		return (1);
	else if (lst->next == 0)
	{
		free(lst);
		lst = 0;
		while(--i > 0)
			tmp = head->next;
		tmp->next = 0;
		return (0);
	}
	reset_list(head, lst, i);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list	*lst;
	char	*ret;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (head && head->next != 0)
	{
		lst = find_fd(head, fd);
		if (!lst)
			return (0);
		if (!lst->buf)
		{
			head = all_free(head);
			lst = 0;
			return (0);
		}
	}
	else
	{
		head = (t_list *)malloc(sizeof(t_list));
		if (!head)
			return (0);
		lst = new_list(fd);
		if (!lst)
		{
			free(head);
			head = 0;
			return (0);
		}
		head->next = lst;
	}
	if (!lst)
	{
		head = all_free(head);
		return (0);
	}
	ret = get_line(lst->buf);
	lst->buf = reset_s(lst->buf);
	if (!lst->buf)
	{
		if(arrange(head, lst) == 1)
			head = all_free(head);
	}
	return(ret);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main()
// {
// 	int fd;
// 	int fd1;
// 	int fd2;
// 	char *s;

// 	fd = open("test.txt", O_RDONLY);
// 	fd1 = open("test1.txt", O_RDONLY);
// 	// fd2 = open("test2.txt", O_RDONLY);


// 	s = get_next_line(fd);
// 	printf("%s", s);

// 	s = get_next_line(fd1);
// 	printf("%s", s);

// 	// s = get_next_line(fd2);
// 	// printf("%s", s);

// 	// s = get_next_line(fd);
// 	// printf("%s", s);
	
// 	s = get_next_line(fd1);
// 	printf("%s", s);

// 	// s = get_next_line(fd2);
// 	// printf("%s", s);

// 	// s = get_next_line(fd);
// 	// printf("%s", s);

// 	// s = get_next_line(fd1);
// 	// printf("%s", s);

// 	// s = get_next_line(fd2);
// 	// printf("%s", s);

// 	return 0;
// }