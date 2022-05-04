/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:15:03 by kko               #+#    #+#             */
/*   Updated: 2022/02/12 20:34:40 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	error_print()
{
	char* text = "error\n";
	while (*text)
	{
		write(1, text, 1);
		text++;
	}
}
void	test_arr_print(int **arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			print("%d", arr[i][j]);
		}
		print("\n");
	}
}

void	input_valid(int **array, char **argv, int cnt)
{
	int i;
	
	i = 0;
	while (i < cnt)
	{
		if (arav[1][i] < '0' || argv[1][i] > '9')
			return (0);
		else
		{
			array[(i/2)
		}
	}
}

int	ft_strlen(char *text)
{
	int i;

	i = 0;
	while (*text)
	{
		i++;
		text++;
	}
	return i;
}

int	main(int argc,char **argv)
{
	int	i;
	int	N;
	int **valid_array;

	i = 0;
	N = ((ft_strlen(argv[1])  / 2) + 1) / 4;
	valid_array = (int **) malloc(sizeof(int *) * 4);
	while (i < N)
	{
		valid_array[i] = (int *) malloc(sizeof(int) * N);
		i++;
	}
	if (input_valid(vaild_array, argv,  ft_strlen(argv[1])) == 1)
	{
		test_arr_print(valid_array, 4);
	}
	else
		error_print();
	free(valid_array);
	return(0);
}
