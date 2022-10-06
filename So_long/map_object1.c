/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_object1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:23:28 by kko               #+#    #+#             */
/*   Updated: 2022/10/07 05:15:35 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_tile(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->h)
	{
		j = 0;
		while (j < info->w)
		{
			if (info->map[i][j] == '0')
				put_tile(info, i, j);
			j++;
		}
		i++;
	}
}

void	ft_tile1(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->h)
	{
		j = 0;
		while (j < info->w)
		{
			put_tile(info, i, j);
			j++;
		}
		i++;
	}
}

void	get_exits(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	info->state_exits = 0;
	while (i < info->h)
	{
		j = 0;
		while (j < info->w)
		{
			if (info->map[i][j] == 'P')
			{
				info->exits_x = i;
				info->exits_y = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_exits(t_info *info)
{
	info->map[info->exits_x][info->exits_y] = 'P';
	put_exits(info, info->exits_x, info->exits_y);
}

void	ft_wall(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->h)
	{
		j = 0;
		while (j < info->w)
		{
			if (info->map[i][j] == '1')
				put_wall(info, i, j);
			j++;
		}
		i++;
	}
}
