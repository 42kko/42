/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:22:51 by kko               #+#    #+#             */
/*   Updated: 2022/10/08 22:24:57 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_wall(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->h)
	{
		if (info->map[i][0] != '1' || info->map[i][info->w - 1] != '1')
		{
			free_map(info);
			ft_exit("Map is not surrounded by walls");
		}
		i++;
	}
	i = 0;
	while (i < info->w)
	{
		if (info->map[0][i] != '1' || info->map[info->h - 1][i] != '1')
		{
			free_map(info);
			ft_exit("Map is not surrounded by walls");
		}
		i++;
	}
}

void	count_othes(t_info *info, int *e, int *c, int *p)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'P')
			{
				info->exits_x = i;
				info->exits_y = j;
				*p = *p + 1;
			}
			else if (info->map[i][j] == 'E')
				*e = *e + 1;
			else if (info->map[i][j] == 'C')
				*c = *c + 1;
			j++;
		}
		i++;
	}
}

void	check_othes1(t_info *info, int e, int c, int p)
{
	if (e == 0)
	{
		free_map(info);
		ft_exit("Need a player");
	}
	else if (e > 1)
	{
		free_map(info);
		ft_exit("Many player");
	}
	else if (c == 0)
	{
		free_map(info);
		ft_exit("Need a collection");
	}
	else if (p == 0)
	{
		free_map(info);
		ft_exit("Need a exit");
	}
	else if (p > 1)
	{
		free_map(info);
		ft_exit("Many exit");
	}
}

void	check_othes(t_info *info)
{
	int	e;
	int	c;
	int	p;

	e = 0;
	c = 0;
	p = 0;
	count_othes(info, &e, &c, &p);
	info->cnt_c = c;
	check_othes1(info, e, c, p);
}

void	swap_E(t_info *info)
{
	
}

void	check_map(t_info *info)
{
	swap_E(info);
	check_square(info);
	check_wall(info);
	check_othes(info);
}
