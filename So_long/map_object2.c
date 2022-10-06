/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_object2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:30:07 by kko               #+#    #+#             */
/*   Updated: 2022/10/07 05:15:47 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collect(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	info->cnt_c = 0;
	info->state_c = 0;
	while (i < info->h)
	{
		j = 0;
		while (j < info->w)
		{
			if (info->map[i][j] == 'C')
			{
				put_collect(info, i, j);
				info->cnt_c++;
			}
			j++;
		}
		i++;
	}
}

void	ft_player(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->h)
	{
		j = 0;
		while (j < info->w)
		{
			if (info->map[i][j] == 'E')
			{
				info->player_x = j;
				info->player_y = i;
				put_player(info, i, j);
			}
			j++;
		}
		i++;
	}
}
