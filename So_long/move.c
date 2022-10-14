/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:27:16 by kko               #+#    #+#             */
/*   Updated: 2022/10/11 11:14:02 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_info *info)
{
	if (info->map[info->player_y - 1][info->player_x] != '1')
	{
		if (info->map[info->player_y - 1][info->player_x] == 'C')
		{
			info->map[info->player_y - 1][info->player_x] = '0';
			put_tile(info, info->player_y - 1, info->player_x);
			info->state_c++;
		}
		if (info->map[info->player_y - 1][info->player_x] == 'E' && \
		info->state_c == info->cnt_c)
			free_end(info);
		put_tile(info, info->player_y, info->player_x);
		info->map[info->player_y][info->player_x] = '0';
		info->player_y--;
		info->tmp++;
		new_pos(info);
	}
}

void	move_d(t_info *info)
{
	if (info->map[info->player_y][info->player_x + 1] != '1')
	{
		if (info->map[info->player_y][info->player_x + 1] == 'C')
		{
			info->map[info->player_y][info->player_x + 1] = '0';
			put_tile(info, info->player_y, info->player_x + 1);
			info->state_c++;
		}
		if (info->map[info->player_y][info->player_x + 1] == 'E' && \
		info->state_c == info->cnt_c)
			free_end(info);
		put_tile(info, info->player_y, info->player_x);
		info->map[info->player_y][info->player_x] = '0';
		info->player_x++;
		info->tmp++;
		new_pos(info);
	}
}

void	move_s(t_info *info)
{
	if (info->map[info->player_y + 1][info->player_x] != '1')
	{
		if (info->map[info->player_y + 1][info->player_x] == 'C')
		{
			info->map[info->player_y + 1][info->player_x] = '0';
			put_tile(info, info->player_y + 1, info->player_x);
			info->state_c++;
		}
		if (info->map[info->player_y + 1][info->player_x] == 'E' && \
		info->state_c == info->cnt_c)
			free_end(info);
		put_tile(info, info->player_y, info->player_x);
		info->map[info->player_y][info->player_x] = '0';
		info->player_y++;
		info->tmp++;
		new_pos(info);
	}
}

void	move_a(t_info *info)
{
	if (info->map[info->player_y][info->player_x - 1] != '1')
	{
		if (info->map[info->player_y][info->player_x - 1] == 'C')
		{
			info->map[info->player_y][info->player_x - 1] = '0';
			put_tile(info, info->player_y, info->player_x - 1);
			info->state_c++;
		}
		if (info->map[info->player_y][info->player_x - 1] == 'E' && \
		info->state_c == info->cnt_c)
			free_end(info);
		put_tile(info, info->player_y, info->player_x);
		info->map[info->player_y][info->player_x] = '0';
		info->player_x--;
		info->tmp++;
		new_pos(info);
	}
}

void	new_pos(t_info *info)
{
	ft_exits(info);
	info->map[info->player_y][info->player_x] = 'P';
	ft_player(info);
	info->plag = 1;
}
