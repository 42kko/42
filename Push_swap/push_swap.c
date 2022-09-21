/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:38:16 by kko               #+#    #+#             */
/*   Updated: 2022/09/21 21:48:47 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_node **lst)
{
	t_node	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = 0;
}


int	main(int ac, char **av)
{
	t_node	*head;
	t_node	*b;
	t_deque	*c;

	head = 0;
	b = 0;
	head = make_stack(head, ac, av);
	{
		c = top_bot(head);
		printf("%d top \n", c->top->val);
		printf("%d bottom \n", c->bottom->val);
	}
	print_a(head);
	print_b(b);
	ft_lstclear(&head);
	system("leaks push_swap");
	return (0);
}