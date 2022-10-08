/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:28:27 by kko               #+#    #+#             */
/*   Updated: 2022/10/07 06:58:42 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tile(t_info *info, int i, int j)
{
	info->wall = mlx_xpm_file_to_image(\
	info->ptr, "./img/tile.xpm", \
	&(info->img_w), &(info->img_h));
	if (info->wall == NULL)
	{
		free_all(info);
		ft_exit("Tile img not found");
	}
	mlx_put_image_to_window(info->ptr, info->win, info->wall, 64 * j, 64 * i);
}

void	put_wall(t_info *info, int i, int j)
{
	info->tile = mlx_xpm_file_to_image(info->ptr, \
	"./img/wall.xpm", &(info->img_w), &(info->img_w));
	if (info->tile == NULL)
	{
		free_all(info);
		ft_exit("Wall img not found");
	}
	mlx_put_image_to_window(info->ptr, info->win, info->tile, 64 * j, 64 * i);
}

void	put_collect(t_info *info, int i, int j)
{
	info->collect = mlx_xpm_file_to_image(info->ptr, \
	"./img/collect.xpm", &(info->img_w), &(info->img_h));
	if (info->collect == NULL)
	{
		free_all(info);
		ft_exit("Collect img not found");
	}
	mlx_put_image_to_window(info->ptr, info->win, \
	info->collect, 64 * j, 64 * i);
}

void	put_player(t_info *info, int i, int j)
{
	info->player = mlx_xpm_file_to_image(info->ptr, \
	"./img/player.xpm", &(info->img_w), &(info->img_h));
	if (info->player == NULL)
	{
		free_all(info);
		ft_exit("Player img not found");
	}
	mlx_put_image_to_window(info->ptr, info->win, info->player, 64 * j, 64 * i);
}

void	put_exits(t_info *info, int i, int j)
{
	info->exits = mlx_xpm_file_to_image(info->ptr, \
	"./img/exit.xpm", &(info->img_w), &(info->img_w));
	if (info->exits == NULL)
	{
		free_all(info);
		ft_exit("Exit not found");
	}
	mlx_put_image_to_window(info->ptr, info->win, info->exits, 64 * j, 64 * i);
}
