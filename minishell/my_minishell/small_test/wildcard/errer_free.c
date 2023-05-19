#include "../minishell.h"
#include "../libft/libft.h"

t_wc_list	*free_wc_list(t_wc_list *list)
{
	t_wc_list	*memo;

	while (list != NULL)
	{
		memo = list;
		if (list->str != NULL)
			free(list->str);
		list = list->next;
		free(memo);
	}
	return (NULL);
}

t_wc_list	*error_wl_card(char *str, int *check)
{
	*check = 1;
	ft_putstr_fd("Error, ", 2);
	ft_putendl_fd(str, 2);
	return (NULL);
}

char	*error_wl_card_char(char *str, int *check)
{
	*check = 1;
	ft_putstr_fd("Error, ", 2);
	ft_putendl_fd(str, 2);
	return (NULL);
}
