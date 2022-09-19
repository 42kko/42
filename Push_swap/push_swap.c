/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:38:16 by kko               #+#    #+#             */
/*   Updated: 2022/09/20 02:37:04 by kko              ###   ########.fr       */
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

int	ft_check_array(char *str)
{
	int	i;
	int	space;
	int	plag;

	i = 0;
	space = 0;
	plag = 0;
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && plag == 1)
			return (-1);
		else if (str[i] == '+' || str[i] == '-')
			plag = 1;
		else if ((!ft_isdigit(str[i]) && !ft_isspace(str[i])))
			return (-1);
		else if (ft_isspace(str[i]))
			space = 1;
		else if (ft_isdigit(str[i]) && space == 1)
			return (1);
		i++;
	}
	return (0);
}

void	err(int ac, char **av)
{
	int	i;
	int	state;

	i = 1;
	state = 0;
	while (i < ac)
	{
		state = ft_check_array(av[i]);
		if (state == -1)
		{
			ft_putstr_fd("error-1\n", 2);
			exit(0);
		}
		else if (ac == 2)
		{
			ft_putstr_fd("error-2\n", 1);
			exit (0);
		}
		i++;
	}
	return ;
}

int	figures_1(char *av)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (ft_isascii(av[i]) == 1)
	{
		if (ft_isspace(av[i]))
			ret++;
		i++;
	}
	return (++ret);
}

int	figures(int ac, char **av)
{
	int	i;
	int	ret;
	int	state;

	i = 0;
	ret = 0;
	state = 0;
	while (i < ac)
	{
		state = ft_check_array(av[i]);
		if (state == 0)
			ret++;
		else if (state == 1)
		{
			ret += figures_1(av[i]);
		}
		i++;
	}
	return (ret);
}

void	ft_putnum(int **ret, int *j, char *av)
{
	int		i;
	int		k;
	int		c;
	char	**split;

	i = *j;
	c = 0;
	k = figures_1(av);
	split = ft_split(av, ' ');
	while (k > 0)
	{
		ret[0][i] = atoi(split[c]);
		k--;
		c++;
		i++;
	}
	*j = i;
}

int	*parsing(int ac, char **av)
{
	int	*ret;
	int	i;
	int	j;
	int	k;

	i = figures(ac, av);
	ret = (int *)malloc(sizeof(i));
	i = 0;
	j = 0;
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

void	insert(t_node **head, int i)
{
	t_node	*new;
	t_node	*tail;

	new = (t_node *)malloc(sizeof(t_node));
	new->val = i;
	if (*head == 0)
	{
		new->next = 0;
		new->prev = 0;
		*head = new;
	}
	else
	{
		tail = *head;
		while (tail->next != 0)
			tail = tail->next;
		tail->next = new;
		new->prev = tail;
		new->next = 0;
	}
}

void	insert_p(t_node **head, int i)
{
	t_node	*new;
	t_node	*top;

	new = (t_node *)malloc(sizeof(t_node));
	new->val = i;
	if (*head == 0)
	{
		new->next = 0;
		new->prev = 0;
		*head = new;
	}
	else
	{
		top = *head;
		new->next = top;
		top->prev = new;
		*head = new;
	}
}

t_push	*top_bot(t_node *head)
{
	t_push	*tail;

	tail = (t_push *)malloc(sizeof(t_push));
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

t_node	*make_stack(t_node *head, int ac, char **av)
{
	int	*i;
	int	j;
	int	k;

	err(ac, av);
	i = parsing(ac, av);
	j = 0;
	k = figures(ac, av);
	while (k-- > 0)
	{
		insert(&head, i[j]);
		j++;
	}
	free (i);
	return (head);
}

void	ft_sa(t_node *head)
{
	int	i;

	i = head->val;
	head->val = head->next->val;
	head->next->val = i;
}

t_node	*ft_pb(t_node **head, t_node *b)
{
	t_node	*tmp;

	tmp = *head;
	insert_p(&b, tmp->val);
	*head = tmp->next;
	free(tmp);
	return (b);
}

void	ft_ra(t_node **head)
{
	t_node	*tmp;

	tmp = *head;
	insert(&tmp, tmp->val);
	*head = tmp->next;
	free(tmp);
}

void	ft_rra(t_node **head)
{
	t_push	*bot;
	t_node	*new;
	t_node	*tmp;

	tmp = *head;
	bot = (t_push *)malloc(sizeof(t_push));
	bot = top_bot(tmp);
	new = (t_node *)malloc(sizeof(t_node));
	new->val = bot->bottom->val;
	tmp->prev = new;
	new->next = tmp;
	*head = new;
	free(bot);
	while (tmp->next != 0)
		tmp = tmp->next;
	tmp->prev->next = 0;
	free(tmp);
}

int	main(int ac, char **av)
{
	t_node	*head;
	t_node	*b;
	t_push	*c;

	head = 0;
	b = 0;
	head = make_stack(head, ac, av);
	{
		c = top_bot(head);
		printf("%d top \n", c->top->val);
		printf("%d bottom \n", c->bottom->val);
	}
	print_a(head);
	print_b(b);

	// {
	// 	printf("sa\n");
	// 	ft_sa(head);
	// 	print_a(head);
	// 	print_b(b);
	// }
	// printf("\n");
	// {
	// 	printf("pb pb pb\n");
	// 	b = ft_pb(&head, b);
	// 	b = ft_pb(&head, b);
	// 	b = ft_pb(&head, b);
	// 	print_a(head);
	// 	print_b(b);
	// }
	// printf("\n");
	// {
	// 	printf("rr\n");
	// 	ft_ra(&head);
	// 	ft_ra(&b);
	// 	print_a(head);
	// 	print_b(b);
	// }
	// printf("\n");
	// {
	// 	printf("rrr\n");
	// 	ft_rra(&head);
	// 	ft_rra(&b);
	// 	print_a(head);
	// 	print_b(b);
	// }
	// printf("\n");
	// {
	// 	printf("sa\n");
	// 	ft_sa(head);
	// 	print_a(head);
	// 	print_b(b);
	// }
	// printf("\n");
	// {
	// 	printf("pa pa pa\n");
	// 	head = ft_pb(&b, head);
	// 	head = ft_pb(&b, head);
	// 	head = ft_pb(&b, head);
	// 	print_a(head);
	// 	print_b(b);
	// }
	// return 0;
}