/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:03:10 by kko               #+#    #+#             */
/*   Updated: 2022/09/28 13:19:42 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_deque *info)
{
	int	tmp;
	int	tmp1;

	tmp = info->size_a;
	tmp1 = info->size;
	while (tmp--)
	{
		if (info->size_a < 4)
			return ;
		if (info->top_a->val == info->sorted[tmp1 - 1] || \
		info->top_a->val == info->sorted[tmp1 - 2] || \
		info->top_a->val == info->sorted[tmp1 - 3])
			ft_ra(info);
		else
			ft_pb(info);
	}
}

void	sort1(t_deque *info)
{
	int	p1;
	int	p2;
	int	tmp;

	p1 = info->sorted[info->size_a / 3];
	p2 = info->sorted[info->size_a / 3 * 2];
	tmp = info->size_a;
	while (tmp--)
	{
		if (info->top_a->val >= p2)
			ft_ra(info);
		else
		{
			ft_pb(info);
			if (info->top_b->val < p1)
				ft_rb(info);
		}
		if (info->size_a < 3)
			return ;
	}
	sort2(info);
}
