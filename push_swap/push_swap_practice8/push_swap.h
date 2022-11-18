/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choinagi <choinagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:48:45 by choinagi          #+#    #+#             */
/*   Updated: 2022/11/18 13:48:47 by choinagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./get_next_line/get_next_line.h"

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				num;
}				t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
}				t_stack;

typedef struct s_a_b
{
	t_stack	*a_stack;
	t_stack	*b_stack;
}				t_a_b;

//parsing_utils
long long	ft_atoll(const char *str);
size_t		ft_strlen(const char *s);
void		data_parsing(t_a_b *info, int ac, char **av);
char		**ft_split(char const *s, char c);
int			*data_arr(t_a_b *info);
int			isspace_check(char *s);
void		ft_free_split(char **str);
void		error_handle(int val);

// struct_utils
t_a_b		*new_info(void);
t_stack		*new_stack(void);
t_node		*new_node(int val);
void		free_stack(t_stack *s);
void		free_info(t_a_b **info);
void		free_arr(int *arr);

// promfts
void		sa(t_stack *a, int flag);
void		sb(t_stack *b, int flag);
void		ss(t_a_b *info, int flag);
void		pa(t_a_b *info, int flag);
void		pb(t_a_b *info, int flag);
void		ra(t_stack *a, int flag);
void		rb(t_stack *b, int flag);
void		rr(t_a_b *info, int flag);
void		rra(t_stack *a, int flag);
void		rrb(t_stack *b, int flag);
void		rrr(t_a_b *info, int flag);

//move_cnt_utils
int			stack_min(t_stack *s);
int			stack_max(t_stack	*s);
int			ret_a_step_min(t_stack *a, int a_min);
int			ret_a_mid(int num, t_stack *a);
int			ret_a_step_max(t_stack *a, int a_min);

//push_swap & sort functions
int			sort_check(t_a_b *info);
void		bubble_sort(int *arr, int size);
void		sort_two(t_a_b *info);
void		sort_three(t_a_b *info);
void		main_sort(t_a_b *info);
void		rr_rrr_same(t_a_b *info, int *a_step, int *b_step);
void		a_ra_rra(t_a_b *info, int a_step);
void		b_rb_rrb(t_a_b *info, int b_step);
void		last_sort(t_a_b *info);
void		push_swap(t_a_b *info, int *arr);

//checker.c
void		checker(t_a_b *info);
void		do_prompt(t_a_b *info, char *prompt);
void		do_prompt2(t_a_b *info, char *prompt);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
