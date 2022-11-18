/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:48:04 by choinagi          #+#    #+#             */
/*   Updated: 2022/11/18 17:18:38 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	data_check(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static void	data_push(t_a_b *info, long long val)
{
	t_node	*tmp;

	if (val > 2147483647 || val < -2147483648)
		error_handle(1);
	tmp = new_node(val);
	if (info->a_stack->top == NULL)
	{
		info->a_stack->top = tmp;
		info->a_stack->bot = tmp;
		info->a_stack->size = 1;
	}
	else
	{
		info->a_stack->bot->next = tmp;
		tmp->prev = info->a_stack->bot;
		info->a_stack->bot = tmp;
		info->a_stack->size++;
	}
}

void	data_parsing(t_a_b *info, int ac, char **av)
{
	int		i;
	int		j;
	char	**split_val;
	int		check_i;

	i = 1;
	while (i < ac)
	{
		j = 0;
		check_i = isspace_check(av[i]);
		if (av[i][check_i] == '\0')
			error_handle(1);
		split_val = ft_split(av[i], ' ');
		while (split_val[j] != NULL)
		{
			if (data_check(split_val[j]))
				error_handle(1);
			data_push(info, ft_atoll(split_val[j]));
			j++;
		}
		ft_free_split(split_val);
		split_val = NULL;
		i++;
	}
}

static void	unique_check(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[i + 1])
			error_handle(1);
		i++;
	}
}

int	*data_arr(t_a_b *info)
{
	int		i;
	int		*tmp;
	t_node	*tmp_node;

	i = 0;
	tmp_node = info->a_stack->top;
	tmp = (int *)malloc(sizeof(int) * info->a_stack->size);
	if (tmp == NULL)
		error_handle(1);
	while (tmp_node)
	{
		tmp[i] = tmp_node->num;
		i++;
		tmp_node = tmp_node->next;
	}
	bubble_sort(tmp, i);
	unique_check(tmp, i);
	return (tmp);
}
