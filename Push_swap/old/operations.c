/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:43:04 by kko               #+#    #+#             */
/*   Updated: 2022/09/21 21:43:52 by kko              ###   ########.fr       */
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
	t_node	*tmp;
	t_node	*tmp1;

	tmp = *head;
	tmp1 = *head;
	while (tmp1->next != 0)
		tmp1 = tmp1->next;
	insert_t(&tmp, tmp1->val);
	tmp1->prev->next = 0;
	free(tmp1);
	*head = tmp;
}
