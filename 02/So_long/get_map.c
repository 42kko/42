/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:26:42 by kko               #+#    #+#             */
/*   Updated: 2022/10/26 21:31:23 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*open_map(char *map)
{
	int		fd;
	int		i;
	int		size;
	char	*a;

	size = ft_size(map);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_exit1("Wrong fd value");
	a = (char *)malloc(sizeof(char) * (size + 1));
	if (a == 0)
		ft_exit("malloc fail");
	i = read(fd, a, size);
	if (i < 0)
	{
		free(a);
		ft_exit("read file");
	}
	a[size] = 0;
	close(fd);
	ft_nl(a, size);
	return (a);
}

void	map_size(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while ((*info).map[i])
	{
		j = 0;
		while ((*info).map[i][j])
			j++;
		i++;
	}
	(*info).h = i;
	(*info).w = j;
}

int	ft_size(char *map)
{
	char	tmp[10000];
	int		ret;
	int		fd;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_exit1("open");
	while (1)
	{
		ret = read(fd, tmp, 10000);
		i += ret;
		if (ret == 0)
			break ;
		else if (ret < 0)
			ft_exit("read file");
	}
	close(fd);
	if (i == 0)
		ft_exit1("Empty map");
	return (i);
}
