/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:47:54 by choinagi          #+#    #+#             */
/*   Updated: 2022/11/18 17:36:19 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	abs_v(int tmp)
{
	if (tmp < 0)
		return (tmp * -1);
	return (tmp);
}

static int	a_move_cnt(int num, t_stack	*a)
{
	int	a_step;
	int	a_min;
	int	a_max;

	a_min = stack_min(a);
	a_max = stack_max(a);
	if (num < a_min)
		a_step = ret_a_step_min(a, a_min);
	else if (num > a_max)
		a_step = ret_a_step_max(a, a_max);
	else
		a_step = ret_a_mid(num, a);
	return (a_step);
}

static int	min_move(int a_step, int b_step, int tmp_a, int tmp_b)
{
	a_step = abs_v(a_step);
	b_step = abs_v(b_step);
	tmp_a = abs_v(tmp_a);
	tmp_b = abs_v(tmp_b);
	if (a_step + b_step > tmp_a + tmp_b)
		return (1);
	return (0);
}

static void	min_move_a_b(t_a_b *info, int *a_step, int *b_step)
{
	t_node	*b;
	int		i;
	int		tmp_a;
	int		tmp_b;

	i = 0;
	b = info->b_stack->top;
	while (i < info->b_stack->size)
	{
		tmp_a = a_move_cnt(b->num, info->a_stack);
		if (i >= (info->b_stack->size + 1) / 2)
			tmp_b = (info->b_stack->size - i) * -1;
		else
			tmp_b = i;
		if (i == 0 || min_move(*a_step, *b_step, tmp_a, tmp_b))
		{
			*a_step = tmp_a;
			*b_step = tmp_b;
		}
		i++;
		b = b->next;
	}
}

void	main_sort(t_a_b *info)
{
	int	a_step;
	int	b_step;

	while (info->b_stack->size)
	{
		a_step = 0;
		b_step = 0;
		min_move_a_b(info, &a_step, &b_step);
		rr_rrr_same(info, &a_step, &b_step);
		a_ra_rra(info, a_step);
		b_rb_rrb(info, b_step);
		pa(info, 1);
	}	
	last_sort(info);
}
