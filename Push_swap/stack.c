/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:47:35 by kko               #+#    #+#             */
/*   Updated: 2022/09/20 10:09:57 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

t_deque	*top_bot(t_node *head)
{
	t_deque	*tail;

	tail = (t_deque *)malloc(sizeof(t_deque));
	tail->top = head;
	if (head->next == 0)
		tail->bottom = head;
	else
	{
		while (head->next != 0)
			head = head->next;
		tail -> bottom = head;
	}
	return (tail);
}

t_node	*make_stack(t_node *head, int ac, char **av)
{
	int	*i;
	int	j;
	int	size;

	err(ac, av);
	i = parsing(ac, av, &size);
	j = 0;
	ft_sort(i, size);
	while (size-- > 0)
	{
		insert(&head, i[j]);
		j++;
	}
	free (i);
	return (head);
}
