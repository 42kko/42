/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:37:21 by kko               #+#    #+#             */
/*   Updated: 2022/10/20 18:06:22 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**ft_pipe(int ac)
{
	int	**p;
	int	i;

	p = (int **)malloc(sizeof(int *) * (ac - 4));
	if (!p)
		ft_exit("Malloc error");
	i = 0;
	while (i < ac - 4)
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

int	main(int ac, char **av, char **envp)
{
	t_lst	info;

	cnt_cmd(&info, ac);
	parse_cmd(&info, av, envp);
	info.p = ft_pipe(ac);
	info.outfile = ft_strdup(av[ac - 1]);
	exec_pipe(&info);
	system("leaks pipex");
}
