/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choinagi <choinagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:47:22 by choinagi          #+#    #+#             */
/*   Updated: 2022/11/18 13:49:14 by choinagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./get_next_line/get_next_line.h"

void	checker(t_a_b *info)
{
	char	*prompt;

	prompt = get_next_line(0);
	while (prompt)
	{
		do_prompt(info, prompt);
		free(prompt);
		prompt = NULL;
		prompt = get_next_line(0);
	}
	if (info->b_stack->size == 0 && sort_check(info) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	do_prompt(t_a_b *info, char *prompt)
{
	if (ft_strncmp(prompt, "pa\n", 10) == 0)
		pa(info, 0);
	else if (ft_strncmp(prompt, "pb\n", 10) == 0)
		pb(info, 0);
	else if (ft_strncmp(prompt, "ra\n", 10) == 0)
		ra(info->a_stack, 0);
	else if (ft_strncmp(prompt, "rb\n", 10) == 0)
		rb(info->b_stack, 0);
	else if (ft_strncmp(prompt, "rr\n", 10) == 0)
		rr(info, 0);
	else if (ft_strncmp(prompt, "rra\n", 10) == 0)
		rra(info->a_stack, 0);
	else
		do_prompt2(info, prompt);
}

void	do_prompt2(t_a_b *info, char *prompt)
{
	if (ft_strncmp(prompt, "rrb\n", 10) == 0)
		rrb(info->b_stack, 0);
	else if (ft_strncmp(prompt, "rrr\n", 10) == 0)
		rrr(info, 0);
	else if (ft_strncmp(prompt, "sa\n", 10) == 0)
		sa(info->a_stack, 0);
	else if (ft_strncmp(prompt, "sb\n", 10) == 0)
		sb(info->b_stack, 0);
	else if (ft_strncmp(prompt, "ss\n", 10) == 0)
		ss(info, 0);
	else
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

int	main(int ac, char *av[])
{
	t_a_b	*info;
	int		*arr;

	if (ac < 2)
		return (0);
	info = new_info();
	data_parsing(info, ac, av);
	arr = data_arr(info);
	free(arr);
	checker(info);
	free_info(&info);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n)
	{
		if (s1[len] != s2[len])
			return ((unsigned char)s1[len] - (unsigned char)s2[len]);
		if (s1[len] == 0 && s2[len] == 0)
			return (0);
		len++;
	}
	return (0);
}
