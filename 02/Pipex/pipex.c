/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:37:21 by kko               #+#    #+#             */
/*   Updated: 2022/11/01 18:18:32 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**ft_pipe(t_lst info)
{
	int	**p;
	int	i;

	p = (int **)malloc(sizeof(int *) * (info.cnt_cmd - 1));
	if (!p)
		ft_exit("Malloc error");
	i = 0;
	while (i < info.cnt_cmd - 1)
	{
		p[i] = (int *)malloc(sizeof(int) * 2);
		if (!p[i])
			ft_exit("Malloc error");
		if (pipe(p[i]) < 0)
			ft_exit("pipe");
		i++;
	}
	return (p);
}

void	parse_cmd(t_lst *info, int ac, char **av, char **envp)
{
	info->infile = ft_strdup(av[1]);
	if (av[1] && !ft_strncmp(av[1], "here_doc", 8) && av[1][8] == '\0')
	{
		info->doc = 1;
		info->limiter = strdup(av[2]);
		info->cnt_cmd -= 1;
		if (ac != 6)
			ft_exit("error: argument");
	}
	else if (open(info->infile, O_RDONLY) < 0)
	{
		ft_putstr_fd(info->infile, 2);
		ft_exit(": no such file or directory");
	}
	info->path = find_path(envp);
	info->envp = envp;
	put_cmd(info, av);
}

int	main(int ac, char **av, char **envp)
{
	t_lst	info;

	cnt_cmd(&info, ac);
	parse_cmd(&info, ac, av, envp);
	info.pipe = ft_pipe(info);
	if (info.doc == 1)
	{
		info.pipe_doc = (int *)malloc(sizeof(int) * 2);
		pipe(info.pipe_doc);
	}
	info.outfile = ft_strdup(av[ac - 1]);
	exec_pipe(&info);
	free_util(&info);
	return (0);
}
