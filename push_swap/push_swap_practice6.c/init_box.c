/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:04:29 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/29 08:56:32 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_parse(int *argc, char ***argv)
{
	*argc = *argc - 1;
	(*argv)++;
}

void	init_stack(t_stack *a_stk, t_stack *b_stk)
{
	a_stk->bottom = NULL;
	a_stk->top = NULL;
	a_stk->idx = 0;
	b_stk->bottom = NULL;
	b_stk->top = NULL;
	b_stk->idx = 0;
}
