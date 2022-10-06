/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:26:42 by kko               #+#    #+#             */
/*   Updated: 2022/10/07 05:03:18 by kko              ###   ########.fr       */
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
		ft_exit("fd value error");
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

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_exit("fd value error");
	ret = read(fd, tmp, 10000);
	if (ret < 0)
		ft_exit("read file");
	close(fd);
	return (ret);
}