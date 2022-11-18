/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_move_cnt_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choinagi <choinagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:47:10 by choinagi          #+#    #+#             */
/*   Updated: 2022/11/18 13:47:13 by choinagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_min(t_stack *a)
{
	t_node	*a_node;
	int		ret;

	a_node = a->top;
	ret = a_node->num;
	while (a_node)
	{
		if (ret > a_node->num)
			ret = a_node->num;
		a_node = a_node->next;
	}
	return (ret);
}

int	stack_max(t_stack	*a)
{
	t_node	*a_node;
	int		ret;

	a_node = a->top;
	ret = a_node->num;
	while (a_node)
	{
		if (ret < a_node->num)
			ret = a_node->num;
		a_node = a_node->next;
	}
	return (ret);
}

int	ret_a_step_min(t_stack	*a, int a_min)
{
	t_node	*a_node;
	int		i;

	i = 0;
	a_node = a->top;
	while (a_node)
	{
		if (a_min == a_node->num)
			break ;
		i++;
		a_node = a_node->next;
	}
	if (i >= (a->size + 1) / 2)
		i = (a->size - i) * -1;
	return (i);
}

int	ret_a_step_max(t_stack	*a, int a_min)
{
	t_node	*a_node;
	int		i;

	i = 1;
	a_node = a->top;
	while (a_node)
	{
		if (a_min == a_node->num)
			break ;
		i++;
		a_node = a_node->next;
	}
	if (i >= (a->size + 1) / 2)
		i = (a->size - i) * -1;
	return (i);
}

int	ret_a_mid(int num, t_stack	*a)
{
	t_node	*a_node;
	int		i;

	i = 1;
	a_node = a->top;
	while (a_node->next)
	{
		if (a_node->num < num && a_node->next->num > num)
			break ;
		i++;
		a_node = a_node->next;
	}
	if (i >= (a->size + 1) / 2)
		i = (a->size - i) * -1;
	return (i);
}
