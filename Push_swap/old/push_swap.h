/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:58:58 by kko               #+#    #+#             */
/*   Updated: 2022/09/22 19:01:10 by kko              ###   ########.fr       */
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
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_deque;

t_node	*make_stack(t_node *head, int ac, char **av, t_node *b);
int		ft_isspace(char c);
int		ft_check_array(char *str);
void	err(int ac, char **av);
int		figures_1(char *av);
int		figures(int ac, char **av);
void	ft_putnum(int **ret, int *j, char *av);
int		*parsing(int ac, char **av, int *size);
void	insert(t_node **head, int i);
void	insert_p(t_node **head, int i);
t_deque	*top_bot(t_node *head);
void	print_a(t_node *head);
void	print_b(t_node *head);
void	ft_sa(t_node *head);
t_node	*ft_pb(t_node **head, t_node *b);
void	ft_ra(t_node **head);
void	ft_rra(t_node **head);
int		main(int ac, char **av);
void	quick(int *arr, int L, int R);
void	ft_sort(int *i, int k, t_node **head, t_node **b);
void	ft_check_minus(char *str);
int		ft_wordc(const char *s, char c);
void	err_overlap(int *arr, int size);
void	case_num3(int *i, t_node **head);
void	ft_lstclear(t_node **lst);
void	insert_t(t_node **head, int i);
void	case_num5(int *i, t_node **head, t_node **b);


#endif