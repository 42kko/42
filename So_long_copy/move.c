/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:27:16 by kko               #+#    #+#             */
/*   Updated: 2022/10/07 05:00:00 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_info *info)
{
	if (info->map[info->player_y - 1][info->player_x] == '1')
		info->player_y = info->player_y;
	else if (info->map[info->player_y - 1][info->player_x] != '1')
	{
		if (info->map[info->player_y - 1][info->player_x] == 'C')
			info->state_c++;
		if (info->map[info->player_y - 1][info->player_x] == 'P' && \
		info->state_c == info->cnt_c)
			free_end(info);
		info->map[info->player_y][info->player_x] = '0';
		info->player_y--;
		info->tmp++;
		new_pos(info);
	}
}

void	move_d(t_info *info)
{
	if (info->map[info->player_y][info->player_x + 1] == '1')
		info->player_y = info->player_y;
	else if (info->map[info->player_y][info->player_x + 1] != '1')
	{
		if (info->map[info->player_y][info->player_x + 1] == 'C')
			info->state_c++;
		if (info->map[info->player_y][info->player_x + 1] == 'P' && \
		info->state_c == info->cnt_c)
			free_end(info);
		info->map[info->player_y][info->player_x] = '0';
		info->player_x++;
		info->tmp++;
		new_pos(info);
	}
}

void	move_s(t_info *info)
{
	if (info->map[info->player_y + 1][info->player_x] == '1')
		info->player_y = info->player_y;
	else if (info->map[info->player_y + 1][info->player_x] != '1')
	{
		if (info->map[info->player_y + 1][info->player_x] == 'C')
			info->state_c++;
		if (info->map[info->player_y + 1][info->player_x] == 'P' && \
		info->state_c == info->cnt_c)
			free_end(info);
		info->map[info->player_y][info->player_x] = '0';
		info->player_y++;
		info->tmp++;
		new_pos(info);
	}
}

void	move_a(t_info *info)
{
	if (info->map[info->player_y][info->player_x - 1] == '1')
		info->player_y = info->player_y;
	else if (info->map[info->player_y][info->player_x - 1] != '1')
	{
		if (info->map[info->player_y][info->player_x - 1] == 'C')
			info->state_c++;
		if (info->map[info->player_y][info->player_x - 1] == 'P' && \
		info->state_c == info->cnt_c)
			free_end(info);
		info->map[info->player_y][info->player_x] = '0';
		info->player_x--;
		info->tmp++;
		new_pos(info);
	}
}

void	new_pos(t_info *info)
{
	ft_exits(info);
	info->map[info->player_y][info->player_x] = 'E';
	ft_tile(info);
	ft_collect(info);
	ft_player(info);
	ft_wall(info);
	info->plag = 1;
}
