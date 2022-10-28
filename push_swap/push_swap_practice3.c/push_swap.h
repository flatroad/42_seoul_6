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

typedef	struct s_utils
{
	char	**argv;
	int		argc;
} t_utils;


// typedef struct s_list
// {
// 	char	**start;
// 	char	**cmd;
// 	char	**order;
// 	int 	top;
// 	int		max;
// 	struct s_list *next;
// } t_list;

typedef	struct s_cmd
{
	char	**cmd;
	int		top;
	int		max;
	struct s_cmd *next;
} t_cmd;

typedef	struct s_list
{
	t_cmd	*cmd;
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
int		init_cmd(t_cmd *list, int max);
void	init_utils(t_utils *utilz, int argc, char **argv);
void	init_stack(t_stack *a_stk, t_stack *b_stk);
int		init_list(t_list *command, int argc);

//save_point2
int	push_swap(t_stack a_stk, t_stack b_stk, t_utils utilz, t_list command);
void	ft_free(t_list **str);

#endif
