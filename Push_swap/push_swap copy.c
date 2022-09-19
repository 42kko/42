/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:38:16 by kko               #+#    #+#             */
/*   Updated: 2022/09/20 02:09:23 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)  //libft
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


static void	ft_putchar(const char *s, size_t i, size_t j, char *ret) //libft
{
	size_t	a;

	a = 0;
	while (a < j)
	{
		ret[a] = s[i + a];
		a++;
	}
	ret[a] = 0;
}

static int	ft_input(const char *s, char c, char **ret, int *val)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i + j] != c && s[i + j])
			j++;
		if (j != 0)
			ret[*val] = (char *)malloc(sizeof(char) * j + 1);
		if (!ret[*val] && j != 0)
		{
			(*val)--;
			return (0);
		}
		if (j != 0)
			ft_putchar (s, i, j, ret[*val]);
		(*val)++;
		i = i + j;
	}
	return (1);
}

static size_t	wordc(const char *s, char c)
{
	size_t	size;
	size_t	i;
	size_t	ret;

	size = ft_strlen(s);
	i = 0;
	ret = 0;
	while (s[i])
	{
		if ((s[i] != c && i == 0) || (s[i] != c && s[i - 1] == c))
			ret++;
		i++;
	}
	if (i == 0)
		return (0);
	return (ret);
}

static void	memfree(char **ret, int val)
{
	while (val >= 0)
	{
		free(ret[val]);
		val--;
	}
	free(ret);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	int		result;
	int		val;
	size_t	word;

	if (!s)
		return (0);
	word = wordc(s, c);
	ret = (char **)malloc(sizeof(char *) * (word + 1));
	if (!ret)
		return (0);
	ret[word] = 0;
	val = 0;
	result = ft_input(s, c, ret, &val);
	if (result == 0)
	{
		memfree(ret, val);
		return (0);
	}
	return (ret);
}

int	ft_isascii(int c)
{
	if (c >= 1 && c <= 127)
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_isspace(char c) //ilbft
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	size;

	i = 0;
	if (!s)
		return ;
	size = ft_strlen(s);
	while (i < size)
	{
		write(fd, s + i, 1);
		i++;
	}
}

size_t	match_nub(const char *nptr, int sign)
{
	size_t	ret;

	ret = 0;
	while ('0' <= *nptr && *nptr <= '9')
	{
		ret = (ret * 10) + (*nptr - '0');
		if (ret > 9223372036854775807 && sign == 1)
			return (-1);
		if (ret > 9223372036854775807 && sign == -1)
			return (0);
		nptr++;
	}
	return (ret);
}

void	ft_exit(void)
{
	printf("error\n");
	exit(0);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	size_t	j;
	int		sign;

	i = 0;
	sign = 1;
	j = 0;
	while ((9 <= *nptr && 13 >= *nptr) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(nptr[j]))
		j++;
	if (j >= 20 && sign == 1)
		ft_exit();
	else if (j >= 20 && sign == -1)
		ft_exit();
	i = match_nub(nptr, sign);
	return (i * sign);
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

typedef struct s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_degue
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_push;

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