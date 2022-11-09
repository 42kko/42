/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kko <kko@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:21:22 by kko               #+#    #+#             */
/*   Updated: 2022/11/09 22:02:17 by kko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_tree
{
	int	data;
	struct s_tree *left;
	struct s_tree *right;
} tree;

void	preorder (tree *node)
{
	if (node == 0)
		return ;
	printf ("%d, ", node->data);
	preorder(node->left);
	preorder(node->right);
}

int	main()
{
	int cnt_node = 13; //총 노드수
	tree *node;

	node = (tree *)malloc(sizeof(tree) * (cnt_node + 1));
	int i = 0;
	while (i++ < cnt_node) //노드를 초기화시켜줌
	{
		node[i].data = i;
		node[i].left = 0;
		node[i].right = 0;
	}
	i = 2;
	while (i++ < cnt_node) //노드를 연결해줌
	{
		if (i % 2 == 0)
			node[i / 2].left = &node[i];
		else
			node[i / 2].right = &node[i];
	}
	// 노드탐색
	preorder(&node[0]);
	print
}
