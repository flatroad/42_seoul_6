#include "../minishell.h"
#include "../libft/libft.h"

t_wc_list	*make_wildcard_list(t_wc_list *all_file_list, char *str, int *check)
{
	t_wc_list	*wc_list;
	t_wc_list	*wc_start;
	t_wc_list	*memo_list;

	memo_list = all_file_list;
	wc_start = NULL;
	while (all_file_list != NULL)
	{
		if (check_wc_list(all_file_list->str, str) == 0)
		{
			wc_start = add_wc_list(all_file_list->str, check);
			all_file_list = all_file_list->next;
			break ;
		}
		all_file_list = all_file_list->next;
	}
	if (wc_start != NULL)
		wc_start = make_wildcard_list_sub(all_file_list, str, check, wc_start);
	all_file_list = memo_list;
	return (wc_start);
}

t_wc_list	*make_wildcard_list_sub(t_wc_list *all_file_list, char *str, \
int *check, t_wc_list	*wc_start)
{
	t_wc_list	*wc_list;

	wc_list = wc_start;
	while (all_file_list != NULL)
	{
		if (check_wc_list(all_file_list->str, str) == 0)
		{
			wc_list->next = add_wc_list(all_file_list->str, check);
			if (wc_list->next == NULL)
				return (free_wc_list(wc_start));
			wc_list = wc_list->next;
		}
		all_file_list = all_file_list->next;
	}
	return (wc_start);
}

t_wc_list	*add_wc_list(char *str, int *check)
{
	t_wc_list	*new_list;

	new_list = (t_wc_list *)malloc(sizeof(t_wc_list) * 1);
	if (new_list == NULL)
		return (error_wl_card(strerror(errno), check));
	new_list->str = ft_strdup(str);
	if (new_list->str == NULL)
		return (error_wl_card(strerror(errno), check));
	new_list->next = NULL;
	return (new_list);
}
