/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:28:04 by kko               #+#    #+#             */
/*   Updated: 2022/10/20 18:26:47 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_path(t_lst *info, int i)
{
	char	*s;

	s = info->cmd[i][0];
	i = access(s, X_OK);
	if (i != 0)
	{
		ft_msg_cmd(s);
	}
}

void	cnt_cmd(t_lst *info, int ac)
{
	if (ac <= 4)
		ft_exit("Need more argument");
	info->cnt_cmd = ac - 3;
	info->cmd = (char ***)malloc(sizeof(char **) * info->cnt_cmd);
	if (!info->cmd)
		ft_exit("Malloc error");
}

void	put_path(t_lst *info, char *arr, int cur)
{
	int		i;
	char	*tmp;
	char	*tmp1;

	tmp1 = arr;
	i = 0;
	while (info->path[i])
	{
		tmp = ft_strjoin(info->path[i], arr);
		if (access(tmp, F_OK) == 0)
		{
			info->cmd[cur][0] = tmp;
			free(tmp1);
			return ;
		}
		free(tmp);
		i++;
	}
	ft_msg_cmd(arr);
}

void	put_cmd(t_lst *info, char **av)
{
	int	i;

	i = 0;
	while (i < info->cnt_cmd)
	{
		info->cmd[i] = ft_split(av[i + 2], ' ');
		if (ft_strchr(info->cmd[i][0], '/') != 0)
			ft_path(info, i);
		else
		{
			put_path(info, info->cmd[i][0], i);
		}
		i++;
	}
}

void	parse_cmd(t_lst *info, char **av, char **envp)
{
	info->infile = ft_strdup(av[1]);
	if (open(info->infile, O_RDONLY) < 0)
	{
		ft_putstr_fd(info->infile, 2);
		ft_exit(": no such file or directory");
	}
	info->path = find_path(envp);
	info->envp = envp;
	put_cmd(info, av);
}
