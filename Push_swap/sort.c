/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 04:57:43 by kko               #+#    #+#             */
/*   Updated: 2022/09/21 21:27:52 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	quick(int *arr, int L, int R)
{
	int left;
	int right;
	int pivot;
	int tmp;

	left = L;
	right = R;
	pivot = arr[(L + R) / 2];
	while(left <= right)
	{
		while(arr[left] < pivot)
			left++;
		while(arr[right] > pivot)
			right--;
		if (left <= right)
		{
			SWAP(arr[left], arr[right], tmp);
			left++;
			right--;
		}
	}
	if(L < right)
		quick(arr, L, right);
	if(left < R)
		quick(arr, left, R);
}

void	case_num3(int *i, t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	if (tmp->val == i[1] && tmp->next->val == i[0])
		ft_sa(tmp);
	else if (tmp->val == i[2] && tmp->next->val == i[1])
	{
		ft_sa(tmp);
		ft_rra(&tmp);
	}
	else if (tmp->val == i[2] && tmp->next->val == i[0])
		ft_ra(&tmp);
	else if (tmp->val == i[2] && tmp->next->val == i[0])
		{
			ft_sa(tmp);
			ft_ra(&tmp);
		}
	else if (tmp->val == i[1] && tmp->next->val == i[2])
		ft_rra(&tmp);
	*head = tmp;
}

void	ft_sort(int *i, int size, t_node **head)
{
	quick(i, 0, size - 1);
	err_overlap(i, size);
	if (size == 3)
		case_num3(i, head);
}
