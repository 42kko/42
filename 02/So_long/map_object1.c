/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_object1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:23:28 by kko               #+#    #+#             */
/*   Updated: 2022/11/01 12:42:23 by kko              ###   ########.fr       */
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

void	ft_exits(t_info *info)
{
	int	i;

	i = 0;
	while (info->exit_cnt > i)
	{
		info->map[info->exits_x[i]][info->exits_y[i]] = 'E';
		put_exits(info, info->exits_x[i], info->exits_y[i]);
		i++;
	}
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
