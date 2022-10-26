/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:46:30 by kko               #+#    #+#             */
/*   Updated: 2022/10/26 21:11:05 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_doc(t_lst *info)
{
	free(info->limiter);
	free(info->pipe_doc);
}

void	free_cmd(t_lst *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->cnt_cmd > i)
	{
		j = 0;
		while (info->cmd[i][j])
		{
			free(info->cmd[i][j]);
			j++;
		}
		free(info->cmd[i]);
		i++;
	}
	free(info->cmd);
}

void	free_pipe(t_lst *info)
{
	int	i;

	i = 0;
	while (info->cnt_cmd - 1 > i)
	{
		free(info->pipe[i]);
		i++;
	}
	free(info->pipe);
}

void	free_path(t_lst *info)
{
	int	i;

	i = 0;
	while (info->path[i])
	{
		free(info->path[i]);
		i++;
	}
	free(info->path);
}

void	free_util(t_lst *info)
{
	free(info->infile);
	free(info->outfile);
	free_path(info);
	if (info->doc == 1)
		free_doc(info);
	free_cmd(info);
	free_pipe(info);
}
