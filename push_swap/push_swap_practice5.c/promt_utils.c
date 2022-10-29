#include "push_swap.h"

int	empty_stack(t_stack *stk)
{
	if (stk->top == NULL)
		return (TRUE);
	return (FALSE);
}

int	push_cmd(t_list *command, char *order)
{
	printf("%p\n", command->start);
	printf("%p\n", command->start->next);
	if(command->cmd_ad->top == command->max - 1)
	{
		command->cmd_ad = init_cmd(command->max);
		if(command->cmd_ad == NULL)
			return (FALSE);
	}
	command->cmd_ad->top++;
	printf("%d\n", command->cmd_ad->top);
	command->cmd_ad->cmd[command->cmd_ad->top] = order;
	printf("%s\n", command->cmd_ad->cmd[command->cmd_ad->top]);
	return (TRUE);
}
