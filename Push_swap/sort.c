/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 04:57:43 by kko               #+#    #+#             */
/*   Updated: 2022/09/20 10:22:28 by kko              ###   ########.fr       */
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

void	ft_sort(int *i, int size)
{
	quick(i, 0, size - 1);
	err_overlap(i, size);
}
