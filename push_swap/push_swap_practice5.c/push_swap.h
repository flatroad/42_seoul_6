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

typedef	struct s_cmd
{
	char	**cmd;
	int		top;
	int		max;
	struct s_cmd *next;
} t_cmd;

typedef struct s_order
{
	char	*sa;
	char	*sb;
	char	*ss;
	char	*pa;
	char	*pb;
	char	*ra;
	char	*rb;
	char	*rr;
	char	*rra;
	char	*rrb;
	char	*rrr;
} t_order;

typedef	struct s_list
{
	t_cmd	*cmd_ad;
	t_cmd	*start;
	t_order	*order;
	int		max;
} t_list;

typedef struct s_node
{
	int data;
	int check;
	struct s_node *prev;
	struct s_node *next;
} t_node;

typedef struct s_stack
{
	t_node *top;
	t_node *bottom;
	int		idx;
} t_stack;

//main.c
int	main(int argc, char **argv);

//init
int		init_list(t_list *command, int argc, t_order *order);
void	init_order(t_order *order);
int		init_cmd(t_list *command, int max);
void	init_parse(int *argc, char ***argv);
void	init_stack(t_stack *a_stk, t_stack *b_stk);

//pull_a_stack
int	pull_a_stack(t_stack *stk, int argc, char **argv);
int	error_check(char *str, t_stack *stk);
int	push(t_stack *stk, int data);

int	ft_atoi(char *str, int *data);
int	ft_atoi_n(char *str, int *data, int sign, size_t *num);
int	check_num(size_t *num, int sign);

// promt
int	sa(t_stack *a_stk, t_list *command);
int	sb(t_stack *b_stk, t_list *command);
int	ss(t_stack *a_stk, t_stack *b_stk, t_list *command);
int	pa(t_stack *a_stk, t_stack *b_stk, t_list *command);
int	pb(t_stack *a_stk, t_stack *b_stk, t_list *command);
int	ra(t_stack *a_stk, t_list *command);
int	rb(t_stack *b_stk, t_list *command);
int	rr(t_stack *a_stk, t_stack *b_stk, t_list *command);
int	rra(t_stack *a_stk, t_list *command);
int	rrb(t_stack *b_stk, t_list *command);
int	rrr(t_stack *a_stk, t_stack *b_stk, t_list *command);

int	empty_stack(t_stack *stk);
int	push_cmd(t_list *command, char *order);

// free
void	free_all(t_stack *a, t_stack *b, t_list *command);
void	free_stack(t_stack *stk);
void	free_command(t_list *command);

//push_swap
int		push_swap(t_stack *a, t_stack *b, int argc, t_list *command);
void	brute(t_stack *a, t_stack *b, int argc, t_list *command);
void	brute_cas1(t_stack *stk, t_list *command, int i);
void	brute_cas2(t_stack *stk, t_list *command, int i);
int		fide_stk(t_node *stk, int i);

#endif
