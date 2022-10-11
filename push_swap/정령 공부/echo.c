#include <stdio.h>
#include <stdlib.h>

void	pb(int *stack_A, )

void	push_swap(int stack, int n)
{



}

void	device_stack (int *stack_A, int *stack_B,int top[])
{

}

int main(int argc, char *argv[])
{
	int top[2] = {argc - 1 , 0};
	int	*stack_A = malloc(sizeof(int) * argc);
	if (stack_A == NULL)
		return (0);
	int	*stack_B = malloc(sizeof(int) * argc);
	if (stack_B == NULL)
		return (0);
	if (push_nbr_check(argc, argv, stack_A) == -1)
	{
		free(stack_A);
		free(stack_B);
		stack_A = 0;
		stack_B = 0;
		return ("error");
	}
	devive_stack(stack_A, stack_B, top);

	if (push_swap(stack_A, stack_B, top, argc) == 0)
		
	
}
