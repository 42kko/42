/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:22:07 by kko               #+#    #+#             */
/*   Updated: 2022/10/21 13:17:45 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_msg(t_info *info, int i, int j)
{
	printf("%c: Invalid parameter in map\n", info->map[i][j]);
	info->map[i][j] = '0';
}

void	ft_nl(char *a, int size)
{
	int	i;

	i = 0;
	if (a[size - 1] == '\n')
	{
		printf("Wrong newline\n");
		exit(1);
	}
	while (a[i] && i < size && size != 1)
	{
		if (a[i] == '\n')
		{
			if (a[i + 1] == '\n' || i == 0)
			{
				printf("Wrong newline\n");
				exit(1);
			}
		}
		i++;
	}
	if (i == 0)
	{
		printf("Invliad map");
		exit(1);
	}
}
