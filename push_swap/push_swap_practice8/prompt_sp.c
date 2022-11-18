/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_sp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choinagi <choinagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:48:30 by choinagi          #+#    #+#             */
/*   Updated: 2022/11/18 13:48:33 by choinagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int flag)
{
	int	tmp;

	if (a->size < 2)
		return ;
	tmp = a->top->num;
	a->top->num = a->top->next->num;
	a->top->next->num = tmp;
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int flag)
{
	int	tmp;

	if (b->size < 2)
		return ;
	tmp = b->top->num;
	b->top->num = b->top->next->num;
	b->top->next->num = tmp;
	if (flag)
		write(1, "sb\n", 3);
}

void	ss(t_a_b *info, int flag)
{
	if (info->a_stack->size < 2 || info->b_stack->size < 2)
		return ;
	sa(info->a_stack, 0);
	sb(info->b_stack, 0);
	if (flag)
		write(1, "ss\n", 3);
}
