#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <xlocale.h>
#include <stdio.h>

typedef struct node
{
	int date;
	struct node *next;
} node;

typedef struct stack
{
	node *start;
	node *top;
} stack;

void	init(stack *sth);
void	push(stack *sth, int date);
void print_stack(stack *sth);

#endif