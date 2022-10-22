// 문자열이 정상적으로 들어가는 것 확인.

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

char *a = "ad\n";

typedef struct s_stack
{
	char **str;
	int top;
	struct s_stack *next; 
} s_stack;

void init(s_stack *s)
{
	s->top = -1;
	s->str = (char **)malloc(sizeof(char *) * 2);
}

int full(s_stack *s)
{
	if(s->top == 2)
		return (TRUE);
	else
		return (FALSE);
}

s_stack *push(s_stack *s)
{
	s->top++;
	if(full(s) == TRUE)
	{
		printf("%s\n", "123");
		s_stack *ss = (s_stack *)malloc(sizeof(s_stack) * 1);
		printf("%p\n", s);
		printf("%p\n", ss);
		s->next = ss;
		s = s->next;
		init(s);
		s->top++;
		printf("%p\n", s);
		printf("%d\n", s->top);
	}
	s->str[s->top] = a;
	return (s);
}

void pr(s_stack *s)
{
	int i = 0;
	while(s->next == 0)
	{
		printf("s의 %d, %s", s->top, s->str[i]);
		if (i == 2){
			s = s->next;
			i = 0;
		}
		else
		{
			i++;
		}
	}
}

int main(){
	printf("%s", "123\n");
	s_stack *str;
	s_stack *start;
	str = (s_stack *)malloc(sizeof(s_stack) * 1);
	init(str);
	start = str;
	str = push(str);
	printf("%p\n", str);
	printf("%d\n", str->top);
	str = push(str);
	printf("%d\n", str->top);
	str = push(str);
	printf("%d\n", str->top);
	str = push(str);
	printf("%p\n", str);
	printf("%s", start->str[0]);
	printf("%s", start->str[1]);
	printf("%s", start->next->str[0]);
	printf("%s", start->next->str[1]);
}