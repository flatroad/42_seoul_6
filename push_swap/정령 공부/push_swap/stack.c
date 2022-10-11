#include "push_swap.h"
#include <stdio.h>

void init(stack sth)
{
	sth.date = 0;
	sth.link = NULL;
}

void PUSH(stack sth, int num)
{
	stack newnode = (stack)malloc(sizeof(stack));
	newnode->date = num;
	newnode->link = sth;
	sth = newnode;
}

void printstack(stack *sth)
{
	stack *temp = sth;
	while (temp){
		printf("%d", temp->date);
		temp = temp->link;
	}
	printf("\n");
}
