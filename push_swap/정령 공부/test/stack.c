#include "push_swap.h"

void	init(stack *sth)
{
	sth->top = NULL;
	sth->start = sth;
}

void	push(stack *sth, int date)
{
	node	*temp = (node *)malloc(sizeof(node));
	temp->date = date;
	temp->next = sth->top;
	sth->top = temp;
}

void print_stack(stack *sth)
{
	for (node *p = sth->top; p!=NULL; p = p->next)
	{
		printf("%d ", p->date);
	}
	printf("end \n");
}