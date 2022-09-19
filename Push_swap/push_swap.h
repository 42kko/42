/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:58:58 by kko               #+#    #+#             */
/*   Updated: 2022/09/20 02:37:01 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

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
}	t_push;

int	ft_isspace(char c);
int	ft_check_array(char *str);
void	err(int ac, char **av);
int	figures_1(char *av);
int	figures(int ac, char **av);
void	ft_putnum(int **ret, int *j, char *av);
int	*parsing(int ac, char **av);
void	insert(t_node **head, int i);
void	insert_p(t_node **head, int i);
t_push	*top_bot(t_node *head);
void	print_a(t_node *head);
void	print_b(t_node *head);
t_node	*make_stack(t_node *head, int ac, char **av);
void	ft_sa(t_node *head);
t_node	*ft_pb(t_node **head, t_node *b);
void	ft_ra(t_node **head);
void	ft_rra(t_node **head);
int	main(int ac, char **av);

#endif