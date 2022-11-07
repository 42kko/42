/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:30:05 by kko               #+#    #+#             */
/*   Updated: 2022/11/07 12:07:35 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_getfile(t_lst *info)
{
	int	fd;

	if (info->doc == 0)
	{
		close(info->pipe[0][PIPE_R]);
		fd = open(info->infile, O_RDONLY);
		if (fd < 0)
			ft_exit("open error");
		dup2(fd, STDIN);
		dup2(info->pipe[0][PIPE_W], STDOUT);
		close(fd);
		close(info->pipe[0][PIPE_W]);
		execve(info->cmd[0][0], info->cmd[0], info->envp);
	}
	if (info->doc == 1)
	{
		close(info->pipe[0][PIPE_R]);
		dup2(info->pipe_doc[PIPE_R], STDIN);
		dup2(info->pipe[0][PIPE_W], STDOUT);
		close(info->pipe[0][PIPE_W]);
		close(info->pipe_doc[PIPE_R]);
		execve(info->cmd[0][0], info->cmd[0], info->envp);
	}
}

void	ft_child(t_lst *info, int cur)
{
	int	fd;

	if (cur == 0)
		ft_getfile(info);
	else if (cur == info->cnt_cmd - 1)
	{
		fd = open_util(info);
		dup2(info->pipe[cur - 1][PIPE_R], STDIN);
		dup2(fd, STDOUT);
		close(fd);
		close(info->pipe[cur - 1][PIPE_R]); //원래
		execve(info->cmd[cur][0], info->cmd[cur], info->envp);
	}
	else
	{
		close(info->pipe[cur][PIPE_R]);
		dup2(info->pipe[cur - 1][PIPE_R], STDIN);
		dup2(info->pipe[cur][PIPE_W], STDOUT);
		close(info->pipe[cur][PIPE_W]);
		close(info->pipe[cur - 1][PIPE_R]);
		execve(info->cmd[cur][0], info->cmd[cur], info->envp);
	}
	free_util(info);
	exit(1);
}

void	ft_parent(t_lst *info, int cur)
{
	if (info->cnt_cmd > cur + 1)
	{
		close(info->pipe[cur][PIPE_W]);
	}
	if (info->cnt_cmd > cur + 2)
	{
		if (pipe(info->pipe[cur + 1]) < 0)
			ft_exit("pipe error");
	}
	if (cur > 1 && info->cnt_cmd > cur)
		close(info->pipe[cur - 2][PIPE_R]);
}

void	exec_pipe(t_lst *info)
{
	pid_t	pid;
	int		i;
	int		tmp;
	int		status;

	i = 0;
	if (info->doc == 1)
		heredoc(info);
	pipe(info->pipe[0]);
	while (i < info->cnt_cmd)
	{
		pid = fork();
		if (pid < 0)
			ft_exit("fork error");
		else if (pid == 0)
			ft_child(info, i);
		else
		{
			ft_parent(info, i);
		}
		i++;
	}
	tmp = info->cnt_cmd;
	close(info->pipe[i - 2][PIPE_R]);
	while (tmp-- > 0)
		waitpid(-1, &status, 0);
}
