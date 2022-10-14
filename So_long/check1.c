/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:22:51 by kko               #+#    #+#             */
/*   Updated: 2022/10/14 20:32:02 by kko              ###   ########.fr       */
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
			ft_exit1("Map is not surrounded by walls");
		}
		i++;
	}
	i = 0;
	while (i < info->w)
	{
		if (info->map[0][i] != '1' || info->map[info->h - 1][i] != '1')
		{
			free_map(info);
			ft_exit1("Map is not surrounded by walls");
		}
		i++;
	}
}

void	count_othes(t_info *info, int *p, int *c, int *e)
{
	int	i;
	int	j;

	i = 0;
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			if (info->map[i][j] == 'E')
			{
				info->exits_x = i;
				info->exits_y = j;
				*e = *e + 1;
			}
			else if (info->map[i][j] == 'P')
				*p = *p + 1;
			else if (info->map[i][j] == 'C')
				*c = *c + 1;
			else if (info->map[i][j] != '1')
				info->map[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	check_othes1(t_info *info, int p, int c, int e)
{
	if (p == 0)
	{
		free_map(info);
		ft_exit1("Need a player");
	}
	else if (p > 1)
	{
		free_map(info);
		ft_exit1("Many player");
	}
	else if (c == 0)
	{
		free_map(info);
		ft_exit1("Need a collection");
	}
	else if (e == 0)
	{
		free_map(info);
		ft_exit1("Need a exit");
	}
	else if (e > 1)
	{
		free_map(info);
		ft_exit1("Many exit");
	}
}

void	check_othes(t_info *info)
{
	int	p;
	int	c;
	int	e;

	p = 0;
	c = 0;
	e = 0;
	count_othes(info, &p, &c, &e);
	info->cnt_c = c;
	check_othes1(info, p, c, e);
}

void	check_map(t_info *info)
{
	check_square(info);
	check_wall(info);
	check_othes(info);
}
