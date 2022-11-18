/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choinagi <choinagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:48:36 by choinagi          #+#    #+#             */
/*   Updated: 2022/11/18 13:48:39 by choinagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_check(t_a_b *info)
{
	t_node	*a;

	a = info->a_stack->top;
	while (a->next)
	{
		if (a->num > a->next->num)
			return (1);
		a = a->next;
	}
	return (0);
}

void	rr_rrr_same(t_a_b *info, int *a_step, int *b_step)
{
	while (*a_step > 0 && *b_step > 0)
	{
		rr(info, 1);
		*a_step -= 1;
		*b_step -= 1;
	}
	while (*a_step < 0 && *b_step < 0)
	{
		rrr(info, 1);
		*a_step += 1;
		*b_step += 1;
	}
}

void	a_ra_rra(t_a_b *info, int a_step)
{
	while (a_step > 0)
	{
		ra(info->a_stack, 1);
		a_step--;
	}
	while (a_step < 0)
	{
		rra(info->a_stack, 1);
		a_step++;
	}
}

void	b_rb_rrb(t_a_b *info, int b_step)
{
	while (b_step > 0)
	{
		rb(info->b_stack, 1);
		b_step --;
	}
	while (b_step < 0)
	{
		rrb(info->b_stack, 1);
		b_step++;
	}
}

void	last_sort(t_a_b *info)
{
	int	a_step;

	a_step = ret_a_step_min(info->a_stack, stack_min(info->a_stack));
	a_ra_rra(info, a_step);
}
