#include "push_swap.h"

void init(stack *s, node *c)
{
	s->top = c;
	s->bottom = c;
}

void push(stack *s, int date)
{
	node *next = (node *)malloc(sizeof(node));
	next->date = date;
	next->next = s->top;
	s->top = next;
}

void init(stack *s, node *c)
{
	s->top = c;
	s->bottom = c;
}

void push(stack *s, int date)
{
	node *next = (node *)malloc(sizeof(node));
	next->date = date;
	next->next = s->top;
	s->top = next;
}

void devive(stack *A, stack *B, int argc)
{
	int i;

	i = argc / 2;
	while(i--)
	{
		pa(A, B);
	}
}
