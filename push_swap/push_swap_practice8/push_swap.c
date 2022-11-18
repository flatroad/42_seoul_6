/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choinagi <choinagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:48:41 by choinagi          #+#    #+#             */
/*   Updated: 2022/11/18 13:48:43 by choinagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_a_b *info)
{
	t_node	*a;

	a = info->a_stack->top;
	if (a->num > a->next->num)
		sa(info->a_stack, 1);
}

void	sort_three(t_a_b *info)
{
	int	top;
	int	bot;
	int	mid;

	top = info->a_stack->top->num;
	mid = info->a_stack->top->next->num;
	bot = info->a_stack->bot->num;
	if (top > mid && mid > bot)
	{
		sa(info->a_stack, 1);
		rra(info->a_stack, 1);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(info->a_stack, 1);
	else if (mid > top && top > bot)
		rra(info->a_stack, 1);
	else if (mid > top && top < bot && mid > bot)
	{
		sa(info->a_stack, 1);
		ra(info->a_stack, 1);
	}
	else if (bot > top && top > mid)
		sa(info->a_stack, 1);
}

static void	sort_pivot(t_a_b *info, int *arr)
{
	t_stack	*a;
	int		p;
	int		p2;
	int		i;

	a = info->a_stack;
	i = a->size;
	p = arr[i / 3];
	p2 = arr[i / 3 * 2];
	while (i)
	{
		if (a->top->num < p)
		{
			pb(info, 1);
			rb(info->b_stack, 1);
		}
		else if (a->top->num < p2)
			pb(info, 1);
		else
			ra(info->a_stack, 1);
		i--;
	}
}

static void	sort_bignumber(t_a_b *info, int *arr)
{
	t_stack	*a;

	a = info->a_stack;
	sort_pivot(info, arr);
	while (a->size > 3)
		pb(info, 1);
	if (a->size == 2)
		sort_two(info);
	else if (a->size == 3)
		sort_three(info);
	main_sort(info);
}

void	push_swap(t_a_b *info, int *arr)
{	
	if (info->a_stack->size == 2)
		sort_two(info);
	else if (info->a_stack->size == 3)
		sort_three(info);
	else if (sort_check(info))
		sort_bignumber(info, arr);
}
