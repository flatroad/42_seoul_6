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

typedef	struct s_list
{
	t_cmd	*cmd_ad;
	t_cmd	*start;
	char	**order;
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

// save_point1
int		main(int argc, char **argv);
int		push_swap(t_stack a, t_stack b, int argc, t_list command);

void	free_all(t_stack *a, t_stack *b, t_list *command);
void	free_stack(t_stack *stk);
void	free_command(t_list *command);

int		init_list(t_list *command, int argc);
int		init_cmd(t_list *command, int max);
void	init_parse(int *argc, char ***argv);
void	init_stack(t_stack *a_stk, t_stack *b_stk);

int		pull_a_stack(t_stack *stk, int argc, char **argv);
int		error_check(char *str, t_stack *stk);
int		push(t_stack *stk, int data);

int		ft_atoi(char *str, int *data);
int		ft_atoi_n(char *str, int *data, int sign, size_t *num);
int		check_num(size_t *num, int sign);

#endif
