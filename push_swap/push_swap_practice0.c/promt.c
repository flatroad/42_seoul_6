#include "push_swap.h"

void pb(stack *A, stack *B)
{
	node	*C = A->top;

	A->top = A->top->next;	
	C->next = B->top;
	B->top = C;
	write(1, "pb\n", 2);
}

void pa(stack *A, stack *B)
{
	node	*C = B->top;

	B->top = B->top->next;
	C->next = A->top;
	A->top = C;
	write(1, "pa\n", 2);
}

void ra(stack *A)
{
	node	*C = A->top->next;
	node	*D = A->bottom->next;
	A->top->next = D;
	A->bottom->next = C;

	node	*G;
	G = A->top;
	A->top = A->bottom;
	A->bottom = G;
	write(1, "ra\n", 2);
}

void rb(stack *B)
{
	node	*C = B->top->next;
	node	*D = B->bottom->next;
	B->top->next = D;
	B->bottom->next = C;

	node	*G;
	G = B->top;
	B->top = B->bottom;
	B->bottom = G;
	write(1, "ra\n", 2);
}