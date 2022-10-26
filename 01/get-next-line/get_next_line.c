/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:35:50 by kko               #+#    #+#             */
/*   Updated: 2022/10/26 16:50:47 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# define BUFFER_SIZE 1

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	size1;
	size_t	size2;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (0);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!ret)
		return (0);
	ft_memcpy(ret, s1, size1);
	ft_memcpy(ret + size1, s2, size2);
	ret[size1 + size2] = 0;
	free (s1);
	return (ret);
}

int	ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return (1);
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
	if (!save[i])  // eof일때
	{
		free(save);
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
		if (ft_strchr(save, '\n'))
			break ;
		i = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = read_buf(save, fd);
	if (!save)
		return (0);
	ret = get_line(save);
	save = reset_s(save);
	return (ret);
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	char *s;

	fd = open("test.txt", O_RDONLY);
	s = get_next_line(fd);
	printf("%s", s);
	// s = get_next_line(fd);
	// printf("%s", s);
	// s = get_next_line(fd);
	// printf("%s", s);
	return 0;
}