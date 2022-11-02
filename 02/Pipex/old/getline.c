/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:48:20 by kko               #+#    #+#             */
/*   Updated: 2022/10/26 19:02:29 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin_get(char *s1, char *s2)
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

char	*reset_s(char *save)
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
		save = ft_strjoin_get(save, buf);
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
