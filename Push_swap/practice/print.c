/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:44:54 by kko               #+#    #+#             */
/*   Updated: 2022/09/20 03:42:03 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_a(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	printf("a\n");
	while (tmp != 0)
	{
		printf("%d", tmp->val);
		tmp = tmp->next;
		if (tmp != 0)
			printf(", ");
	}
	printf("\n");
}

void	print_b(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	printf("b\n");
	while (tmp != 0)
	{
		printf("%d", tmp->val);
		tmp = tmp->next;
		if (tmp != 0)
			printf(", ");
	}
	printf("\n");
}
