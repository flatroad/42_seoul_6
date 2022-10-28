#include "push_swap.h"

int	empty_stack(t_stack *stk)
{
	if (stk->top == NULL)
		return (TRUE);
	return (FALSE);
}

int	push_cmd(t_list *command, char *order)
{
	if(command->cmd_ad->top == command->max - 1)
	{
		if(init_cmd(command, command->max) == FALSE)
			return (FALSE);
	}
	command->cmd_ad->top++;
	if (order == NULL)
		return (0);
	printf("%p\n", command->start->next);
	command->cmd_ad->cmd[command->cmd_ad->top] = order;
	printf("%p\n", command->start->next);
	command->start->next = 0;
	return (TRUE);
}
