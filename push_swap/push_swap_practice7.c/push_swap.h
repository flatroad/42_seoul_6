#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <xlocale.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define INCR 3
#define DECR 2
#define MAX_INT 2147483647
#define MIN_INT -2147483648

typedef struct s_point
{
	int a_b;
	int a_t;
	int b_b;
	int b_t;
} t_point;

typedef struct s_node
{
	int data;
	int group;
	int	shape;
	struct s_node *prev;
	struct s_node *next;
} t_node;

typedef struct s_stack
{
	t_node *top;
	t_node *bottom;
	int		idx;
} t_stack;

// 함수.
// main.c
int		main(int argc, char **argv);
// init_box.c
void	init_parse(int *argc, char ***argv);
void	init_stack(t_stack *a_stk, t_stack *b_stk);
// pull_a_stack.c
int		pull_a_stack(t_stack *stk, int argc, char **argv);
int		error_check(char *str, t_stack *stk);
int		push(t_stack *stk, int data);
int		check_same(t_node *node);
// int	check_handle.c
int	check_handle(int argc);
int	rec(int argc, int sup);
// pull_a_stack_utils.c
int		ft_atoi(char *str, int *data);
int		ft_atoi_n(char *str, int *data, int sign, size_t *num);
int		check_num(size_t *num, int sign);
// free_handle.c
void	free_all(t_stack *a, t_stack *b);
void	free_stack(t_stack *stk);
// push_swap.c
int		push_swap(t_stack *a, t_stack *b, int argc);

// promt.c
void	sa(t_stack *a_stk);
void	sb(t_stack *b_stk);
void	ss(t_stack *a_stk, t_stack *b_stk);
void	pa(t_stack *a_stk, t_stack *b_stk);
void	pb(t_stack *a_stk, t_stack *b_stk);
void	ra(t_stack *a_stk);
void	rb(t_stack *b_stk);
void	rr(t_stack *a_stk, t_stack *b_stk);
void	rra(t_stack *a_stk);
void	rrb(t_stack *b_stk);
void	rrr(t_stack *a_stk, t_stack *b_stk);
// promt_utils.c
int		empty_stack(t_stack *stk);

#endif
