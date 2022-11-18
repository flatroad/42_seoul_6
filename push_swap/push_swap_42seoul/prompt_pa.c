/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_pa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choinagi <choinagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:48:09 by choinagi          #+#    #+#             */
/*   Updated: 2022/11/18 13:48:11 by choinagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_pa(t_a_b *info)
{
	info->a_stack->size++;
	info->b_stack->size--;
}

void	pa(t_a_b *info, int flag)
{
	t_node	*tmp;

	if (info->b_stack->size < 1)
		return ;
	tmp = info->b_stack->top;
	info->b_stack->top = tmp->next;
	if (info->b_stack->size > 1)
		tmp->next->prev = NULL;
	else
		info->b_stack->bot = NULL;
	if (info->a_stack->size > 0)
	{
		tmp->next = info->a_stack->top;
		info->a_stack->top->prev = tmp;
		info->a_stack->top = tmp;
	}
	else
	{
		tmp->next = NULL;
		info->a_stack->top = tmp;
		info->a_stack->bot = tmp;
	}
	_pa(info);
	if (flag)
		write(1, "pa\n", 3);
}
