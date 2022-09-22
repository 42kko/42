/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utile1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:48:38 by kko               #+#    #+#             */
/*   Updated: 2022/09/22 21:42:16 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_1.h"

void	err(int i)
{
	if (i == 1)
		ft_putstr_fd("인자가 한개\n", 1);
	else if (i == 2)
		ft_putstr_fd("중복된 인자\n", 1);
	else if (i == 3)
		ft_putstr_fd("문자열 들어옴\n", 1);
	else if (i == 4)
		ft_putstr_fd("a에 남은스택이 1개\n", 1);
	exit (0);
}

void	err_overlap(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (size-- > 1)
	{
		j = i + 1;
		if (arr[i] == arr[j])
			err(2);
		i++;
	}
}

void	ft_check(int ac, char **av)
{
	int	i;
	int	state;

	i = 1;
	state = 0;
	while (i < ac)
	{
		state = ft_check_array(av[i]);
		if (state == -1)
			err(3);
		i++;
	}
}