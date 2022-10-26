/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:52:16 by kko               #+#    #+#             */
/*   Updated: 2022/10/26 17:00:25 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "./Libft/libft.h"
# define BUFFER_SIZE 1

typedef struct s_lst
{
	char	**envp;
	char	*infile;
	char	*outfile;
	char	***cmd;
	int		cnt_cmd;
	char	**path;
	int		doc;
	char	*limiter;
	int		**pipe;
}	t_lst;

int		**ft_pipe(int ac);
void	ft_infile(t_lst *info);
void	ft_child(t_lst *info, int cur);
void	ft_parent(t_lst *info, int cur);
void	exec_pipe(t_lst *info);
void	put_cmd(t_lst *info, char **av);
void	parse_cmd(t_lst *info, int ac, char **av, char **envp);
void	put_path(t_lst *info, char *arr, int cur);
void	cnt_cmd(t_lst *info, int ac);
void	ft_path(t_lst *info, int i);
char	**find_path(char **envp);
void	add_slash(char **arr);
void	ft_msg_cmd(char *msg);
void	ft_exit(char *msg);
void	split_util(t_lst *info, char *av, int cur);


char	*reset_s(char *save);
char	*get_line(char *save);
char	*read_buf(char *save, int fd);
char	*get_next_line(int fd);


#endif