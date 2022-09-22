/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utile1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:47:46 by kko               #+#    #+#             */
/*   Updated: 2022/09/22 20:29:22 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_1.h"

void	ft_putnum(int **ret, int *j, char *av)
{
	int		i;
	int		k;
	int		c;
	char	**split;

	i = *j;
	c = 0;
	k = ft_wordc(av, ' ');
	split = ft_split(av, ' ');
	while (k > 0)
	{
		ret[0][i] = atoi(split[c]);
		i++;
		k--;
		c++;
	}
	*j = i;
}

int	*make_arr(int ac, char **av, int size)
{
	int	*ret;
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	ret = (int *)malloc(sizeof(int) * (size + 1));
	while (i < ac)
	{
		k = 0;
		if (ft_check_array(av[i]) == 0)
			ret[j++] = ft_atoi(av[i]);
		else if (ft_check_array(av[i]) == 1)
			ft_putnum (&ret, &j, av[i]);
		i++;
	}
	ret[j++] = 0;
	return (ret);
}

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

void	ft_sort(int *i, int size, t_deque *info)
{
	int	*tmp;

	tmp = i;
	quick(tmp, 0, size - 1);
	err_overlap(tmp, size);
	info->sorted = tmp;
}

void	parsing(int ac, char **av, t_deque *info)
{
	int	*arr;
	int	size;
	int	*sorted;

	size = figures(ac, av);
	if (size <= 1)
		err(1);
	ft_check(ac, av);
	info->size_a = size;
	info->size_b = 0;
	arr = make_arr(ac, av, size);
	info->arr = arr;
	sorted = make_arr(ac, av, size);
	ft_sort(sorted, size, info);
}