/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:28:48 by kko               #+#    #+#             */
/*   Updated: 2022/10/26 19:03:25 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	ft_msg_cmd(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": command not found", 2);
	ft_putstr_fd("\n", 2);
}

void	add_slash(char **arr)
{
	char	*tmp;
	char	*tmp1;
	int		i;

	i = 0;
	while (arr[i])
	{
		tmp1 = arr[i];
		tmp = ft_strjoin(arr[i], "/");
		arr[i] = tmp;
		free(tmp1);
		i++;
	}
}

char	**find_path(char **envp)
{
	int		i;
	char	*tmp;
	char	**ret;

	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			tmp = ft_strdup(envp[i] + 5);
			ret = ft_split(tmp, ':');
			add_slash(ret);
			free(tmp);
			return (ret);
		}
		i++;
	}
	return (0);
}
