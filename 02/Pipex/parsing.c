/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:28:04 by kko               #+#    #+#             */
/*   Updated: 2022/10/26 17:01:49 by kko              ###   ########.fr       */
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

void	split_util(t_lst *info, char *av, int cur)
{
	int		size;
	char	*tmp;
	char	*av_tmp;

	size = ft_strlen(av);
	av_tmp = ft_strtrim(av, " ");
	if (ft_strnstr(av_tmp, "awk", size) == 0)  // awk 없음
		info->cmd[cur] = ft_split(av_tmp, ' ');
	else // awk 있음.
	{
		if(ft_strchr(av_tmp, '\'') == 0) // 작은따옴표가 없음.
			info->cmd[cur] = ft_split(av_tmp, '\"');
		else
			info->cmd[cur] = ft_split(av_tmp, '\'');
		tmp = info->cmd[cur][0];
		info->cmd[cur][0] = ft_strtrim(tmp, " ");
		free(tmp);
	}
	free(av_tmp);
}

void	put_cmd(t_lst *info, char **av)
{
	int	i;

	i = 0;
	if (info->doc == 1)
		i = 1;
	while (i < info->cnt_cmd)
	{
		// info->cmd[i] = ft_split(av[i + 2], ' ');  //awk 일땐 스플릿기준을 바꿔야함.
		split_util(info, av[i + 2], i);
		if (ft_strchr(info->cmd[i][0], '/') != 0)
			ft_path(info, i);
		else
			put_path(info, info->cmd[i][0], i);
		i++;
	}
}

void	parse_cmd(t_lst *info, int ac, char **av, char **envp)
{
	if (av[1] && !ft_strncmp(av[1], "here_doc", 8) && av[1][8] == '\0')
	{
		info->doc = 1;
		info->limiter = strdup(av[2]);
		if (ac != 6)
			ft_exit("error: argument");
	}
	else if (open(info->infile, O_RDONLY) < 0)
	{
		ft_putstr_fd(info->infile, 2);
		ft_exit(": no such file or directory");
		info->infile = ft_strdup(av[1]);
	}
	info->path = find_path(envp);
	info->envp = envp;
	put_cmd(info, av);
}
