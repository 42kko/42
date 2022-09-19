/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:30:53 by kko               #+#    #+#             */
/*   Updated: 2022/09/01 17:00:32 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	heapify(int *arr, int size)
{
	int	i;
	int	child;
	int	root;
	int	tmp;

	i = 1;
	while (i < size)
	{
		child = i;
		while (child != 0)
		{
			root = (child - 1) / 2;
			if (arr[root] < arr[child])
			{
				tmp = arr[root];
				arr[root] = arr[child];
				arr[child] = tmp;
			}
			child = root;
		}
		i++;
	}
}

void	heap(int *arr, int *size)
{
	int tmp;

	tmp = arr[0];
	arr[0] = arr[*size - 1];
	arr[*size - 1] = tmp;
	--(*size);
}

int	main()
{
	int	size = 10;
	int	arr[10] = {5, 6, 10, 4, 3, 8, 7, 1, 2, 9};
	
	for(int i = 0; i < 10; i++)
	{
		heapify(arr, size);
		heap(arr, &size);
	}
	for(int i=0;i<10;++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}