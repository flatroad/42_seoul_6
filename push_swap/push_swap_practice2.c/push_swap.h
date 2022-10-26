#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <xlocale.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX_INT 2147483647
#define MIN_INT -2147483648

typedef struct s_list
{
	char **start;
	char **str;
	int top;
	struct s_list *next;
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

int		main(int argc, char **argv);
void	init(t_stack *stk);
int		push_swap(int argc, char **argv, char **order);
int 	error_check(char *str, t_stack *stk);
int 	ft_atoi(char *str, int *data);
int 	ft_atoi_n(char *str, int *data, int sign, size_t *num);
int 	check_num(size_t *num, int sign);
int		free_stk(t_stack *stk);
int		push(t_stack *stk, int data);

#endif
