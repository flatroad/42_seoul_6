/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choinagi <choinagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:47:49 by choinagi          #+#    #+#             */
/*   Updated: 2022/11/18 13:47:52 by choinagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int val)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (tmp == NULL)
		error_handle(1);
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->num = val;
	return (tmp);
}

t_stack	*new_stack(void)
{
	t_stack	*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (tmp == NULL)
		error_handle(1);
	tmp->top = NULL;
	tmp->bot = NULL;
	tmp->size = 0;
	return (tmp);
}

t_a_b	*new_info(void)
{
	t_a_b	*tmp;

	tmp = (t_a_b *)malloc(sizeof(t_a_b));
	if (tmp == NULL)
		error_handle(1);
	tmp->a_stack = new_stack();
	tmp->b_stack = new_stack();
	return (tmp);
}
