/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_rr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choinagi <choinagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:48:22 by choinagi          #+#    #+#             */
/*   Updated: 2022/11/18 13:48:24 by choinagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, int flag)
{
	t_node	*tmp;

	if (a->size < 2)
		return ;
	tmp = a->bot;
	a->bot = tmp->prev;
	a->bot->next = NULL;
	tmp->next = a->top;
	tmp->prev = NULL;
	a->top->prev = tmp;
	a->top = tmp;
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, int flag)
{
	t_node	*tmp;

	if (b->size < 2)
		return ;
	tmp = b->bot;
	b->bot = tmp->prev;
	b->bot->next = NULL;
	tmp->next = b->top;
	tmp->prev = NULL;
	b->top->prev = tmp;
	b->top = tmp;
	if (flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_a_b	*info, int flag)
{
	if (info->a_stack->size < 2 || info->b_stack->size < 2)
		return ;
	rra(info->a_stack, 0);
	rrb(info->b_stack, 0);
	if (flag)
		write(1, "rrr\n", 4);
}
