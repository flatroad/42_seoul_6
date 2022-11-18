/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:40:17 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/29 02:19:18 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	command;
	t_stack	a_stk;
	t_stack	b_stk;

	if (argc == 1)
		return (0);
	if (init_list(&command, argc) == FALSE)
		return (1);
	init_parse(&argc, &argv);
	init_stack(&a_stk, &b_stk);
	if (pull_a_stack(&a_stk, argc, argv) == FALSE || \
	push_swap(a_stk, b_stk, argc, command) == FALSE)
	{
		free_all(&a_stk, &b_stk, &command);
		write(2, "ERROR\n", 6);
		return (1);
	}
	free_all(&a_stk, &b_stk, &command);
	system("leaks push_swap");
	return (0);
}

int	push_swap(t_stack a, t_stack b, int argc, t_list command)
{
	if (a.top == 0 || b.bottom != 0 || argc == 0 || command.max == 0)
		return (FALSE);
	return (TRUE);
}
