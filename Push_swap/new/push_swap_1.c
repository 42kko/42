/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:03:10 by kko               #+#    #+#             */
/*   Updated: 2022/09/22 21:55:05 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_1.h"

void	make_a(t_deque *info)
{
	t_node	*a;
	int	i;
	int	j;

	ft_a(info);
	i = info->size_a;
	j = 1;
	while (i > j)
	{
		insert_tail_a(info, info->arr[j]);
		j++;
	}
}

void	ft_stack(t_deque *info)
{
	make_a(info);
}

void	print(t_deque *info)
{
	{
		int i = info->size_a;
		printf("a\n");
		t_node *tmp = info->top_a;
		while(i--)
		{
			printf("%d, ", tmp->val);
			tmp = tmp->next;
		}
	}
	printf("\n");
	{
		int i = info->size_b;
		printf("b\n");
		t_node *tmp = info->top_b;
		while(i--)
		{
			printf("%d, ", tmp->val);
			tmp = tmp->next;
		}
	}
}

int	main(int ac, char **av)
{
	t_deque	*info;

	info = (t_deque *)malloc(sizeof(t_deque));
	parsing(ac, av, info);
	ft_stack(info);

	print(info);
	ft_pb(info);
	print(info);


	free(info->arr);
	free(info->sorted);
	free(info);
	// system("leaks push_swap");
}