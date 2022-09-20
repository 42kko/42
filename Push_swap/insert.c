/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:45:12 by kko               #+#    #+#             */
/*   Updated: 2022/09/20 03:42:37 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert(t_node **head, int i)
{
	t_node	*new;
	t_node	*tail;

	new = (t_node *)malloc(sizeof(t_node));
	new->val = i;
	if (*head == 0)
	{
		new->next = 0;
		new->prev = 0;
		*head = new;
	}
	else
	{
		tail = *head;
		while (tail->next != 0)
			tail = tail->next;
		tail->next = new;
		new->prev = tail;
		new->next = 0;
	}
}

void	insert_p(t_node **head, int i)
{
	t_node	*new;
	t_node	*top;

	new = (t_node *)malloc(sizeof(t_node));
	new->val = i;
	if (*head == 0)
	{
		new->next = 0;
		new->prev = 0;
		*head = new;
	}
	else
	{
		top = *head;
		new->next = top;
		top->prev = new;
		*head = new;
	}
}
