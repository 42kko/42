/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:28:00 by kko               #+#    #+#             */
/*   Updated: 2022/04/06 21:19:09 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;
	size_t	size;

	i = 0;
	if (!s)
	{
		write(fd, "\n", 1);
		return ;
	}
	size = ft_strlen(s);
	while (i < size)
	{
		write(fd, s + i, 1);
		i++;
	}
	write(fd, "\n", 1);
}
