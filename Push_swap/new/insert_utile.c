/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_utile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 19:58:02 by kko               #+#    #+#             */
/*   Updated: 2022/09/22 21:54:39 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_1.h"

void	ft_a(t_deque *info)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->val = info->arr[0];
	new->prev = 0;
	new->next = 0;
	info->top_a = new;
	info->bottom_a = new;
}

void	ft_b(t_deque *info)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->val = info->arr[0];
	new->prev = 0;
	new->next = 0;
	info->top_b = new;
	info->bottom_b = new;
}

void	insert_tail_a(t_deque *info, int i)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->val = i;
	new->next = 0;
	info->bottom_a->next = new;
	new->prev = info->bottom_a;
	info->bottom_a = new;
}

void	insert_head_b(t_deque *info, int i)
{
	t_node	*new;
	new = (t_node *)malloc(sizeof(t_node));
	new->val = i;
	info->top_b->prev = new;
	new->next = info->top_b;
	new->prev = 0;
	info->top_b = new;
}

void	insert_head_a(t_deque *info, int i)
{
	t_node	*new;
	new = (t_node *)malloc(sizeof(t_node));
	new->val = i;
	info->top_a->prev = new;
	new->next = info->top_a;
	new->prev = 0;
	info->top_a = new;
}