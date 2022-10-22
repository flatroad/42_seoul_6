#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <xlocale.h>

#define TRUE 1
#define FALSE 0
#define MAX_INT 2147483647
#define MIN_INT -2147483648

typedef struct str_list
{
	char **start;
	char **str;
	int top;
	struct str_list *next; 
} s_list;

typedef struct a_node
{
	int data;
	int check;
	struct a_node *next;
	struct a_node *before;
} a_node;

typedef struct a_stack
{
	a_node *top;
	a_node *bottom;
	int		idx;
} a_stack;

typedef struct b_node
{
	int data;
	int check;
	struct b_node *next;
	struct b_node *before;
} b_node;

typedef struct b_stack
{
	b_node *top;
	b_node *bottom;
	int		idx;
} b_stack;



#endif