/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_a_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 01:34:47 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/29 08:11:06 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pull_a_stack(t_stack *stk, int argc, char **argv)
{
	while (stk->idx < argc)
	{
		if (error_check(argv[argc - (stk->idx + 1)], stk) == FALSE)
			return (FALSE);
		stk->idx = stk->idx + 1;
	}
	return (TRUE);
}

int	error_check(char *str, t_stack *stk)
{
	int	data;

	data = 0;
	if (ft_atoi(str, &data) == FALSE)
		return (FALSE);
	if (push(stk, data) == FALSE)
		return (FALSE);
	if (check_same(stk->top) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	push(t_stack *stk, int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node) * 1);
	if (node == NULL)
		return (FALSE);
	node->data = data;
	node->check = stk->idx;
	if (stk->idx == 0)
	{
		node->next = stk->top;
		node->prev = stk->bottom;
		stk->top = node;
		stk->bottom = node;
	}
	else
	{
		stk->top->next = node;
		node->prev = stk->top;
		node->next = NULL;
		stk->top = node;
	}
	return (TRUE);
}

int	check_same(t_node *node)
{
	int	memo;

	memo = node->data;
	node = node->prev;
	while(node != NULL)
	{
		if (memo == node->data)
			return (FALSE);
		node = node->prev;
	}
	return (TRUE);
}
