#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	count;

	count = 0;
	while (lst != 0)
	{
		lst = lst -> next;
		count++;
	}
	return (count);
}
