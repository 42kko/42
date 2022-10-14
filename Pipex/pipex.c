/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:24:04 by kko               #+#    #+#             */
/*   Updated: 2022/10/14 20:05:55 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	int		i;
	char	*ret;

	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			ret = ft_strdup(envp[i] + 5);
			return (ret);
		}
		i++;
	}
	return (0);
}

void	ft_path(t_lst *info, char *av)
{
	int	i;

	i = 0;
	i = access(av, F_OK);
	if (i != 0)
		exit(0);
	info->plag = 1;
}

void	parse_cmd(t_lst *info, char **av, char **envp)
{
	char	*tmp;

	info->infile = open(av[1], O_RDONLY);
	info->cmd1 = ft_split(av[2], ' ');
	if (ft_strchr(av[2], '/') != 0)
		ft_path(info, av[2]);
	info->cmd2 = ft_split(av[3], ' ');
	if (ft_strchr(av[3], '/') != 0)
		ft_path(info, av[3]);
	tmp = find_path(envp);
	if (tmp == 0)
		exit(0);
	info->path = ft_split(tmp, ':');
	free(tmp);
}

void	check_cmd(t_lst *info)
{
	char	*a;
	int	stat;

	stat = 0;
	a = ft_strjoin(info->path[1], "/");
	if (access(ft_strjoin(a, info->cmd1[0]), F_OK) == 0)
	{
		info->cmd1_path = ft_strjoin(a, info->cmd1[0]);
		stat++;
	}
	if (access(ft_strjoin(a, info->cmd2[0]), F_OK) == 0)
	{
		info->cmd2_path = ft_strjoin(a, info->cmd2[0]);
		stat++;
	}
	a = ft_strjoin(info->path[2], "/");
	if (access(ft_strjoin(a, info->cmd1[0]), F_OK) == 0)
	{
		info->cmd1_path = ft_strjoin(a, info->cmd1[0]);
		stat++;
	}
	if (access(ft_strjoin(a, info->cmd2[0]), F_OK) == 0)
	{
		info->cmd2_path = ft_strjoin(a, info->cmd2[0]);
		stat++;
	}
	if (stat != 2)
		exit(0);
}

int	main(int ac, char **av, char **envp)
{
	t_lst info;

	if (ac != 5)
		return 0;
	info.plag = 0;
	parse_cmd(&info, av, envp);
	if (info.plag == 0)
		check_cmd(&info);
	int fd[2];
	pipe(fd);
	int pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		dup2(info.infile, 0);
		close(fd[1]);
		close(info.infile);
		execve(info.cmd1_path, info.cmd1, envp);
	}
	close(fd[1]);
	dup2(fd[0], 0);
	info.outfile = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	dup2(info.outfile, 1);
	close(fd[0]);
	close(info.outfile);
	waitpid(pid, NULL, WNOHANG);
	execve(info.cmd2_path, info.cmd2, envp);
}