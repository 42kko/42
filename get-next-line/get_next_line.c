/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:35:50 by kko               #+#    #+#             */
/*   Updated: 2022/05/09 22:17:57 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reset_s(char *save)
{
	char	*ret;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while(save[i] && save[i] != '\n')
		i++;
	ret = (char *)malloc(sizeof(char) + ft_strlen(save) - i + 1);
	ret[ft_strlen(save) - i] = 0;
	while(save[++i])
	{
		ret[j] = save[i];
		j++;
	}
	free(save);
	return(ret);
}

char	*get_line(char *save)
{
	size_t	i;
	char	*ret;

	i = 0;
	while(save[i] && save[i] != '\n')
		i++;
	ret = (char *)malloc(sizeof(char) * i + 1);
	ret[i] = 0;
	i = 0;
	while (ret[i])
	{
		ret[i] = save[i];
		i++;
	}
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
	while(i > 0)
	{
		buf[i] = 0;
		save = ft_strjoin(save, buf);
		if (ft_strchr(buf, '\n'))
			break;
		i = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*ret;

	save = read_buf(save, fd);
	ret = get_line(save);
	save = reset_s(save);
	return(ret);
}