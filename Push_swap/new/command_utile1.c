/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:59:58 by kko               #+#    #+#             */
/*   Updated: 2022/09/22 21:42:57 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_1.h"

void	ft_sa(t_deque *info)
{

	if (info->size_a < 2)
		err(4);

	int	tmp;

	SWAP(info->top_a->val, info->top_a->next->val, tmp);
}

void	ft_pb(t_deque *info)
{

	if (info->size_a < 2)
		err(4);

	t_node	*tmp;

	if (info->size_b == 0)
		ft_b(info);
	else
		insert_head_b(info, info->top_a->val);
	tmp = info->top_a->next;
	free(info->top_a);
	info->top_a = tmp;
	(info->size_a)--;
	(info->size_b)++;
}

void	ft_ra(t_deque *info)
{

	if (info->size_a < 2)
		err(4);

	t_node	*tmp;
	t_node	*tmp1;

	tmp = info->top_a;
	tmp1 = info->top_a->next;
	info->top_a->next->prev = 0;
	info->top_a = tmp1;
	info->bottom_a->next = tmp;
	tmp->next = 0;
	tmp->prev = info->bottom_a;
	info->bottom_a = tmp;
}

void	ft_rra(t_deque *info)
{

	if (info->size_a < 2)
		err(4);

	t_node	*tmp;
	t_node	*tmp1;

	tmp = info->bottom_a;
	tmp1 = info->bottom_a->prev;
	tmp1->next = 0;
	tmp->next = info->top_a;
	tmp->prev = 0;
	info->top_a = tmp;
	info->bottom_a = tmp1;
}