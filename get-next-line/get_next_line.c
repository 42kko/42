/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 02:15:58 by kko               #+#    #+#             */
/*   Updated: 2022/05/07 05:53:35 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reset(char *s)
{
	int		len;
	int		i;
	char	*ret;

	len = 0;
	while (s[len])
	{
		if (*s == '\n')
			break ;
		len ++;
	}
	i = len;
	while (s[i])
		i++;
	ret = (char *)malloc(i - len + 1);
	if (!ret)
		return (0);
	ret[i - len] = 0;
	while (s[len])
		s[len] = ret[i - len]; //복사함수로 i에 s개행후 문자를 넣어줌
	return (ret);
}

void	return_vul(char *s, char *ret)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (*s == '\n')
			break ;
		len ++;
		*s++;
	}
	ret = (char *)malloc(len + 1);
	if (!ret)
		return ;
	ret[len] = 0;
	while (--len > 0)
		ret[len] = s[len];
	return ;
}

void	read_buf(int fd, char *s)
{
	ssize_t	i;
	char	buf[BUFFER_SIZE + 1];

	i = read(fd, buf, BUFFER_SIZE);
	while (i > 0)
	{
		buf[i] = 0;
		*s = ft_strjoin(buf, s);
		if (ft_strchr(s, '\n') == 1)
			return ;
	}
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*ret;

	read_buf(fd, s); //개행전까지 찾음
	return_vul(s, ret); //개행 전까지의 문자열을 ret에 넣음
	s = reset(s); // ret에 넣은만큼 s를 비워줌
	return (ret);
}
