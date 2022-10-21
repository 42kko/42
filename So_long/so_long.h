/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:23:44 by kko               #+#    #+#             */
/*   Updated: 2022/10/21 11:45:57 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>
# include <stdlib.h>

# define INT_MAX 2147483647
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_info
{
	char	**map;
	int		h;
	int		w;
	void	*tile;
	void	*wall;
	void	*collect;
	void	*player;
	int		player_x;
	int		player_y;
	void	*exits;
	int		img_h;
	int		img_w;
	void	*ptr;
	void	*win;
	int		cnt_c;
	int		state_exits;
	int		state_c;
	void	*param;
	int		tmp;
	int		exits_x;
	int		exits_y;
	int		plag;
}	t_info;

char	**ft_split(const char *s, char c);
size_t	ft_strlen(const char *s);
int		key_press(int keycode, t_info *info);
void	ft_exit(char *msg);
void	ft_exit1(char *msg);
void	ft_map(t_info *info);
void	draw_map(t_info *info);
char	*open_map(char *map);
void	map_size(t_info *info);
int		ft_size(char *map);
void	ft_tile(t_info *info);
void	ft_tile1(t_info *info);
void	get_exits(t_info *info);
void	ft_exits(t_info *info);
void	ft_collect(t_info *info);
void	ft_wall(t_info *info);
void	ft_player(t_info *info);
void	put_tile(t_info *info, int i, int j);
void	put_wall(t_info *info, int i, int j);
void	put_collect(t_info *info, int i, int j);
void	put_player(t_info *info, int i, int j);
void	put_exits(t_info *info, int i, int j);
void	move_w(t_info *info);
void	move_d(t_info *info);
void	move_s(t_info *info);
void	move_a(t_info *info);
void	new_pos(t_info *info);
void	free_all(t_info *info);
void	free_end(t_info *info);
void	check_map(t_info *info);
void	check_square(t_info *info);
void	check_square1(t_info *info, int j);
void	check_wall(t_info *info);
void	free_map(t_info *info);
void	count_othes(t_info *info, int *e, int *c, int *p);
void	check_othes1(t_info *info, int e, int c, int p);
void	check_othes(t_info *info);
int		ft_close(t_info *info);
void	ft_putstr_fd(char *s, int fd);
void	check_ac(int ac);
void	check_av(char *av);
void	ft_msg(t_info *info, int i, int j);
void	ft_nl(char *a, int size);

#endif