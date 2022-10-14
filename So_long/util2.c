/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:22:07 by kko               #+#    #+#             */
/*   Updated: 2022/10/11 11:35:23 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	size;

	i = 0;
	if (!s)
		return ;
	size = ft_strlen(s);
	while (i < size)
	{
		write(fd, s + i, 1);
		i++;
	}
}

int	ft_close(t_info *info)
{
	free_end(info);
	exit(0);
}
