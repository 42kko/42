/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:56:17 by kko               #+#    #+#             */
/*   Updated: 2022/09/28 21:40:39 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cal_op1(t_deque *info, int *ra, int *rb, int *rrb)
{
	info->tmp = 0;
	info->where = 0;
	info->min = INT_MAX;
	info->rra1 = 0;
	*ra = 0;
	*rb = 0;
	*rrb = 0;
}

void	cal_op2(t_deque *info, int *ra, int *rb, int *rrb)
{
	if (info->where > (info->size_a) / 2)
	{
		info->where = (info->size_a) - (info->where);
		info->rra1 = info->where;
		*ra = 0;
	}
	if (info->idx > (info->size_b) / 2)
	{
		info->idx = info->size_b - info->idx;
		*rrb = info->idx;
		*rb = 0;
	}
	if (info->cnt > (info->where + info->idx))
	{
		info->cnt = (info->where) + (info->idx);
		info->ra = *ra;
		info->rb = *rb;
		info->rra = info->rra1;
		info->rrb = *rrb;
	}
}

void	calculate_op(int val, int idx, t_deque *info)
{
	int		ra;
	int		rb;
	int		rrb;
	t_node	*p_node;

	cal_op1(info, &ra, &rb, &rrb);
	rb = idx;
	info->idx = idx;
	p_node = info->top_a;
	while (p_node)
	{
		if (p_node->val > val && p_node->val < info->min)
		{
			info->min = p_node->val;
			info->where = info->tmp;
		}
		(info->tmp)++;
		p_node = p_node->next;
	}
	ra = info->where;
	cal_op2(info, &ra, &rb, &rrb);
}

void	find_min_op(t_deque *info)
{
	t_node	*p_node;
	int		idx;

	idx = 0;
	p_node = info->top_b;
	info->cnt = INT_MAX;
	while (idx < info->size_b)
	{
		calculate_op(p_node->val, idx, info);
		p_node = p_node->next;
		idx++;
	}
}

void	exec_op(t_deque *info)
{
	while (info->rb != 0)
	{
		ft_rb(info);
		(info->rb)--;
	}
	while (info->rrb != 0)
	{
		ft_rrb(info);
		(info->rrb)--;
	}
	while (info->ra != 0)
	{
		ft_ra(info);
		(info->ra)--;
	}
	while (info->rra != 0)
	{
		ft_rra(info);
		(info->rra)--;
	}
	ft_pa(info);
}
