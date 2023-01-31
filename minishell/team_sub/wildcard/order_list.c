#include "../minishell.h"
#include "../libft/libft.h"

t_wc_list	*order_list(t_wc_list *pwd_file_list)
{
	t_wc_list	*list;
	t_wc_list	*memo;
	t_wc_list	*before_memo;

	list = set_fisrt(pwd_file_list);
	memo = list;
	while (memo != NULL)
	{
		before_memo = memo;
		memo = memo->next;
		if (memo == NULL)
			break ;
		memo = set_other(memo);
		before_memo->next = memo;
	}
	return (list);
}

t_wc_list	*set_fisrt(t_wc_list *list)
{
	t_wc_list	*memo;
	t_wc_list	*before;
	t_wc_list	*first;
	int			len;

	first = list;
	memo = list;
	before = NULL;
	while (first->next != NULL)
	{
		len = ft_strlen(memo->str);
		if (strncmp(memo->str, first->next->str, len) > 0)
		{
			memo = first->next;
			before = first;
		}
		first = first->next;
	}
	if (before == NULL)
		return (list);
	before->next = before->next->next;
	memo->next = list;
	list = memo;
	return (list);
}

t_wc_list	*set_other(t_wc_list *list)
{
	t_wc_list	*memo;
	t_wc_list	*before;
	t_wc_list	*first;
	int			len;

	first = list;
	memo = list;
	before = NULL;
	while (first->next != NULL)
	{
		len = ft_strlen(memo->str);
		if (strncmp(memo->str, first->next->str, len) > 0)
		{
			memo = first->next;
			before = first;
		}
		first = first->next;
	}
	if (before == NULL)
		return (list);
	before->next = before->next->next;
	memo->next = list;
	list = memo;
	return (list);
}
