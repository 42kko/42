/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:22:07 by kko               #+#    #+#             */
/*   Updated: 2022/10/14 20:30:21 by kko              ###   ########.fr       */
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

void	check_ac(int ac)
{
	if (ac == 2)
		return ;
	else if (ac == 1)
		ft_exit1("Need map file");
	else if (ac > 2)
		ft_exit1("Many argc");
}

void	check_av(char *av)
{
	int	i;

	i = ft_strlen(av);
	if (av[i - 4] != '.')
		ft_exit1("Extension error");
	if (av[i - 3] != 'b')
		ft_exit1("Extension error");
	if (av[i - 2] != 'e')
		ft_exit1("Extension error");
	if (av[i - 1] != 'r')
		ft_exit1("Extension error");
}
