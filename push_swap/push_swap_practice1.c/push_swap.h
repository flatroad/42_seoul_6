#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <xlocale.h>

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

#endif
