/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:30:05 by kko               #+#    #+#             */
/*   Updated: 2022/10/26 17:09:46 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_infile(t_lst *info)
{
	int	fd;

	close(info->pipe[0][0]);
	fd = open(info->infile, O_RDONLY);
	if (fd < 0)
		ft_exit("open error");
	dup2(fd, 0);
	dup2(info->pipe[0][1], 1);
	close(fd);
	close(info->pipe[0][1]);
	execve(info->cmd[0][0], info->cmd[0], info->envp);
}

void	writedoc(char *limiter, int fd)
{
	size_t	limiter_length;
	char	*line;

	limiter_length = ft_strlen(limiter);
	while (1)
	{
		ft_putstr_fd("pipex here_doc> ", 1);
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			close(fd);
			exit(1);
		}
		if (line[limiter_length] == '\n' && limiter && \
			!ft_strncmp(line, limiter, limiter_length))
		{
			close(fd);
			exit(0);
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
}

void	heredoc(t_lst *info)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_exit("fork error");
	if (pid == 0)
		writedoc(info->limiter, info->pipe[0][1]);
	else
	{
		close(info->pipe[0][0]);
		waitpid(pid, NULL, 0);
	}
}

void	ft_child(t_lst *info, int cur)
{
	int	fd;

	if (cur == 0 && info->doc == 0)
		ft_infile(info);
	else if (cur == info->cnt_cmd - 1)
	{
		close(info->pipe[cur - 1][1]);
		fd = open(info->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		dup2(info->pipe[cur - 1][0], 0);
		dup2(fd, 1);
		close(fd);
		close(info->pipe[cur - 1][0]);
		execve(info->cmd[cur][0], info->cmd[cur], info->envp);
	}
	else
	{
		dup2(info->pipe[cur - 1][0], 0);
		dup2(info->pipe[cur][1], 1);
		close(info->pipe[cur - 1][0]);
		close(info->pipe[cur][1]);
		execve(info->cmd[cur][0], info->cmd[cur], info->envp);
	}
}

void	ft_parent(t_lst *info, int cur)
{
	if (cur < info->cnt_cmd - 1)
		close(info->pipe[cur][1]);
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
