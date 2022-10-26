/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:47:41 by kko               #+#    #+#             */
/*   Updated: 2022/10/26 20:47:56 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	writedoc(char *limiter, int fd)
{
	size_t	len;
	char	*line;

	len = ft_strlen(limiter);
	while (1)
	{
		ft_putstr_fd("pipex here_doc> ", 1);
		line = get_next_line(0);
		if (line[len] == '\n' && limiter && !ft_strncmp(line, limiter, len))
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
	if (pid == -1)
		ft_exit("fork");
	if (pid == 0)
		writedoc(info->limiter, info->pipe_doc[1]);
	else
	{
		close(info->pipe_doc[1]);
		waitpid(pid, NULL, 0);
	}
}

int	open_util(t_lst *info)
{
	int	fd;

	if (info->doc == 1)
		fd = open(info->outfile, O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		fd = open(info->outfile, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	return (fd);
}
