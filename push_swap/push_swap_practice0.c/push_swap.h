#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <xlocale.h>

typedef struct node{
	int date;
	struct node *next;
} node;

typedef struct stack{
	node *top;
	node *bottom;
} stack;

#endif