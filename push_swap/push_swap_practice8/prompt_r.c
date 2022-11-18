/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choinagi <choinagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:48:18 by choinagi          #+#    #+#             */
/*   Updated: 2022/11/18 13:48:20 by choinagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, int flag)
{
	t_node	*tmp;

	if (a->size < 2)
		return ;
	tmp = a->top;
	a->top = tmp->next;
	a->top->prev = NULL;
	tmp->next = NULL;
	tmp->prev = a->bot;
	a->bot->next = tmp;
	a->bot = tmp;
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_stack *b, int flag)
{
	t_node	*tmp;

	if (b->size < 2)
		return ;
	tmp = b->top;
	b->top = tmp->next;
	b->top->prev = NULL;
	tmp->next = NULL;
	tmp->prev = b->bot;
	b->bot->next = tmp;
	b->bot = tmp;
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_a_b *info, int flag)
{
	if (info->a_stack->size < 2 && info->b_stack->size < 2)
		return ;
	ra(info->a_stack, 0);
	rb(info->b_stack, 0);
	if (flag)
		write(1, "rr\n", 3);
}
