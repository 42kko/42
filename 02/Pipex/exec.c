/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:30:05 by kko               #+#    #+#             */
/*   Updated: 2022/10/20 16:37:54 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_infile(t_lst *info)
{
	int	fd;

	close(info->p[0][0]);
	fd = open(info->infile, O_RDONLY);
	if (fd < 0)
		ft_exit("open error");
	dup2(fd, 0);
	dup2(info->p[0][1], 1);
	close(fd);
	close(info->p[0][1]);
	execve(info->cmd[0][0], info->cmd[0], info->envp);
}

void	ft_child(t_lst *info, int cur)
{
	int	fd;

	if (cur == 0)
		ft_infile(info);
	else if (cur == info->cnt_cmd - 1)
	{
		close(info->p[cur - 1][1]);
		fd = open(info->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		dup2(info->p[cur - 1][0], 0);
		dup2(fd, 1);
		close(fd);
		close(info->p[cur - 1][0]);
		execve(info->cmd[cur][0], info->cmd[cur], info->envp);
	}
	else
	{
		dup2(info->p[cur - 1][0], 0);
		dup2(info->p[cur][1], 1);
		close(info->p[cur - 1][0]);
		close(info->p[cur][1]);
		execve(info->cmd[cur][0], info->cmd[cur], info->envp);
	}
}

void	ft_parent(t_lst *info, int cur)
{
	if (cur < info->cnt_cmd - 1)
		close(info->p[cur][1]);
}

void	exec_pipe(t_lst *info)
{
	pid_t	pid;
	int		i;

	i = 0;
	while (i < info->cnt_cmd)
	{
		pid = fork();
		if (pid < 0)
			ft_exit("fork error");
		else if (pid == 0)
			ft_child(info, i);
		else
			ft_parent(info, i);
		i++;
	}
	waitpid(pid, NULL, WNOHANG);
}
