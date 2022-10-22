#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10
#define TRUE 1
#define FALSE 0

typedef struct stack{
	int buf[STACK_SIZE];
	int top;
} stack;


void	init_stack(stack *s)
{
	s->top = -1;
}

int		stack_full(stack *s)
{
	if ((s->top) + 1 == STACK_SIZE)
		return (TRUE);
	else
		return (FALSE);
}

int		stack_empty(stack *s)
{
	if (s->top == -1)
		return (TRUE);
	else
		return (FALSE);
}

void	stack_push(stack *s, int data)
{
	if(stack_full(s) == TRUE)
	{
		printf("stack is full!\n");
		return ;
	}
	else
	{
		s->top++;
		s->buf[s->top] = data;
	}
}

void	stack_peek(stack *s)
{
	if (stack_empty(s) == TRUE)
		printf("stack is empty!\n");
	else
		printf("stack top buf : %d\n", s->buf[s->top]);
}

void	stack_all_peek(stack *s)
{
	if (stack_empty(s) == TRUE)
		printf("stack is empty!\n");
	else
	{
		for (int i = 0; i <= s->top; i++)
			printf("stack[%d] : %d\n", i, s->buf[i]);
	}
}

int stack_pop(stack *s)
{
	int memo;

	memo = 0;
	if (stack_empty(s) == TRUE)
	{
		printf("stack is empty!\n");
		return (memo);
	}
	memo = s->buf[s->top];
	s->top--;
	return (memo);
}

typedef struct str{
	char *s[2];
	int top;
	struct str *next;
} str;

void init_str(str *s)
{
	printf("%s\n", "1241241");
	s->top = -1;
}

int		str_full(str *s)
{
	if ((s->top) + 1 == 2)
		return (TRUE);
	else
		return (FALSE);
}

int		str_empty(str *s)
{
	if (s->top == -1)
		return (TRUE);
	else
		return (FALSE);
}

void	str_push(str *s, char *data)
{
	printf("%s\n", "11");
	if(str_full(s) == TRUE)
	{
		printf("%s\n", "까지");
		printf("%p\n", s);
		s = s->next;
		printf("%p\n", s);
		init_str(s);
		printf("%s\n", "까지");
		str_push(s, data);
	}
	else
	{
		printf("%s\n", "여기까지");
		s->top++;
		s->s[s->top] = data;
	}
}

void	str_all_peek(str *s)
{
	int i = 0;
	if (str_empty(s) == TRUE)
		printf("str is empty!\n");
	else
	{
		while(s->next == 0)
		{
			printf("%s", s->s[i]);
			i++;
			if (i <= s->top)
				s = s->next;
			i = 0;
		}
	}
}

int main(){
	stack*	obj;
	str	ss;
	str	start;
	obj = (stack *)malloc(sizeof(stack) * 1);
	start = ss;
	init_stack(obj);
	init_str(&ss);
	for (int i = 1; i <=11; i++)
	{
		printf("%d\n", 123);
		str_push(&ss, "aa");
		stack_push(obj, i);
	}
	ss = start;
	stack_all_peek(obj);
	stack_peek(obj);
	while(stack_empty(obj) != TRUE)
	{
		printf("stack의 값은 : %d\n", stack_pop(obj));
	}
	printf("\n");
	printf("긑");
	return (0);
}
