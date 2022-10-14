/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:23:30 by kko               #+#    #+#             */
/*   Updated: 2022/10/14 20:26:29 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_info *info)
{
	info->plag = 0;
	if (keycode == KEY_W)
		move_w(info);
	else if (keycode == KEY_S)
		move_s(info);
	else if (keycode == KEY_A)
		move_a(info);
	else if (keycode == KEY_D)
		move_d(info);
	else if (keycode == KEY_ESC)
	{
		free_all(info);
		exit(0);
	}
	else
		return (0);
	if (info->plag == 1)
		printf("move : %d\n", info->tmp);
	return (0);
}

void	ft_map(t_info *info)
{
	ft_tile1(info);
	ft_wall(info);
	ft_collect(info);
	ft_player(info);
	get_exits(info);
	ft_exits(info);
}

void	draw_map(t_info *info)
{
	map_size(info);
	info->ptr = mlx_init();
	info->win = mlx_new_window(info->ptr, 64 * (*info).w, \
	64 * (*info).h, "kko");
	if (info->win == 0)
	{
		free_all(info);
		ft_exit("window not found");
	}
	ft_map(info);
	info->tmp = 0;
	mlx_key_hook(info->win, key_press, info);
	mlx_hook(info->win, 17, 0, &ft_close, info);
	mlx_loop(info->ptr);
}

int	main(int ac, char **av)
{
	t_info	info;
	char	*a;

	check_ac(ac);
	check_av(av[1]);
	a = open_map(av[1]);
	info.map = ft_split(a, '\n');
	check_map(&info);
	free(a);
	draw_map(&info);
	return (0);
}
