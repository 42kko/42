/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:43:04 by kko               #+#    #+#             */
/*   Updated: 2022/09/20 04:55:21 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_sa(t_node *head)
{
	int	i;

	i = head->val;
	head->val = head->next->val;
	head->next->val = i;
}

t_node	*ft_pb(t_node **head, t_node *b)
{
	t_node	*tmp;

	tmp = *head;
	insert_p(&b, tmp->val);
	*head = tmp->next;
	free(tmp);
	return (b);
}

void	ft_ra(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	insert(&tmp, tmp->val);
	*head = tmp->next;
	free(tmp);
}

void	ft_rra(t_node **head)
{
	t_deque	*bot;
	t_node	*new;
	t_node	*tmp;

	tmp = *head;
	bot = (t_deque *)malloc(sizeof(t_deque));
	bot = top_bot(tmp);
	new = (t_node *)malloc(sizeof(t_node));
	new->val = bot->bottom->val;
	tmp->prev = new;
	new->next = tmp;
	*head = new;
	free(bot);
	while (tmp->next != 0)
		tmp = tmp->next;
	tmp->prev->next = 0;
	free(tmp);
}
