/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utile2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:59:58 by kko               #+#    #+#             */
/*   Updated: 2022/09/22 21:47:45 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_1.h"

void	ft_sb(t_deque *info)
{

	if (info->size_b < 2)
		err(5);

	int	tmp;

	SWAP(info->top_b->val, info->top_b->next->val, tmp);
}

void	ft_pa(t_deque *info)
{

	if (info->size_b < 2)
		err(5);

	t_node	*tmp;

	if (info->size_a == 0)
		ft_a(info);
	else
		insert_head_a(info, info->top_b->val);
	tmp = info->top_b->next;
	free(info->top_b);
	info->top_b = tmp;
	(info->size_b)--;
	(info->size_a)++;
}

void	ft_rb(t_deque *info)
{

	if (info->size_b < 2)
		err(5);

	t_node	*tmp;
	t_node	*tmp1;

	tmp = info->top_b;
	tmp1 = info->top_b->next;
	info->top_b->next->prev = 0;
	info->top_b = tmp1;
	info->bottom_b->next = tmp;
	tmp->next = 0;
	tmp->prev = info->bottom_b;
	info->bottom_b = tmp;
}

void	ft_rrb(t_deque *info)
{

	if (info->size_b < 2)
		err(5);

	t_node	*tmp;
	t_node	*tmp1;

	tmp = info->bottom_b;
	tmp1 = info->bottom_b->prev;
	tmp1->next = 0;
	tmp->next = info->top_b;
	tmp->prev = 0;
	info->top_b = tmp;
	info->bottom_b = tmp1;
}