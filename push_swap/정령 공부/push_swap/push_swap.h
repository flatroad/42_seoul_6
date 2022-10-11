#ifndef PUSH_SWAP_C
# define PUSH_SWAP_C

#include <unistd.h>
#include <stdlib.h>

typedef struct stack {
	int date;
	struct stack *link;
} stack;

void init(stack sth);
void PUSH(stack *sth, int num);
void printstack(stack *sth);


#endif


