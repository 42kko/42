/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:14:01 by kko               #+#    #+#             */
/*   Updated: 2022/02/21 11:47:26 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_abs(int a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

int	right(int *col, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		if (col[i] == col[idx] || idx - i == ft_abs(col[idx] - col[i]))
			return (0);
		i++;
	}
	return (1);
}

void	wr(int *col)
{
	int		i;
	char	j;

	i = 0;
	while (i < 10)
	{
		j = '0' + col[i];
		write(1, &j, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	loop(int *col, int *count, int idx)
{
	col[idx] = 0;
	while (col[idx] < 10)
	{
		if (right(col, idx))
		{
			if (idx == 9)
			{
				wr(col);
				*count += 1;
			}
			else
				loop(col, count, idx + 1);
		}
		col[idx]++;
	}	
}

int	ft_ten_queens_puzzle(void)
{
	int	col[10];
	int	count;

	count = 0;
	loop(col, &count, 0);
	return (count);
}
