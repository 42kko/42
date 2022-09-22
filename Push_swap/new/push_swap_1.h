/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_1.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:03:07 by kko               #+#    #+#             */
/*   Updated: 2022/09/22 21:47:27 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#define SWAP(x, y, tmp) (tmp = x, x = y, y = tmp)

typedef struct s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_degue
{
	t_node	*top_a;
	t_node	*bottom_a;
	t_node	*top_b;
	t_node	*bottom_b;
	int		size_a;
	int		size_b;
	int		*arr;
	int		*sorted;
}	t_deque;

void	err(int i);
void	ft_putnum(int **ret, int *j, char *av);
int		*make_arr(int ac, char **av, int size);
void	parsing(int ac, char **av, t_deque *info);
int		ft_isspace(char c);
void	ft_check_minus(char *str);
int		ft_check_array(char *str);
int		figures(int ac, char **av);
int		ft_wordc(const char *s, char c);
void	quick(int *arr, int L, int R);
void	err_overlap(int *arr, int size);
void	ft_check(int ac, char **av);
void	ft_a(t_deque *info);
void	ft_sa(t_deque *info);
void	insert_tail_a(t_deque *info, int i);
void	insert_head_a(t_deque *info, int i);
void	insert_head_b(t_deque *info, int i);
void	ft_pb(t_deque *info);
void	ft_b(t_deque *info);
void	ft_ra(t_deque *info);
void	ft_rra(t_deque *info);
void	ft_sb(t_deque *info);
void	ft_pa(t_deque *info);
void	ft_ra(t_deque *info);
void	ft_rra(t_deque *info);


#endif