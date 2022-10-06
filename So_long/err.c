/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:14:14 by kko               #+#    #+#             */
/*   Updated: 2022/10/07 05:39:26 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(char *msg)
{
	printf("Error\n");
	perror(msg);
	exit(1);
}

void	free_all(t_info *info)
{
	int	i;

	i = 0;
	if (info->tile)
		mlx_destroy_image(info->ptr, info->tile);
	if (info->wall)
		mlx_destroy_image(info->ptr, info->wall);
	if (info->collect)
		mlx_destroy_image(info->ptr, info->collect);
	if (info->exits)
		mlx_destroy_image(info->ptr, info->exits);
	while (info->map[i])
		free(info->map[i++]);
	free(info->map);
	mlx_destroy_window(info->ptr, info->win);
}

void	free_end(t_info *info)
{
	free_all(info);
	printf("THX\n");
	exit(0);
}