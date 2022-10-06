/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 05:22:51 by kko               #+#    #+#             */
/*   Updated: 2022/10/07 06:50:22 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_info *info)
{
	int	i;

	i = 0;
	while (info->map[i])
		free(info->map[i++]);
	free(info->map);
}

void	check_square1(t_info *info, int j)
{
	int	i;

	i = 0;
	if (info->w != j)
	{
		free_map(info);
		ft_exit("Not square");
	}
}

void	check_square(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	map_size(info);
	while (info->map[i])
	{
		j = 0;
		while (info->map[i][j])
		{
			j++;
		}
		if (i >= 0)
			check_square1(info, j);
		i++;
	}
	if (i != info->h)
	{
		free_map(info);
		ft_exit("Not square");
	}
}
