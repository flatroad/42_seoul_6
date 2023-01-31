#include "../minishell.h"
#include "../libft/libft.h"

t_wc_list	*make_token_file_list(t_token *token, t_wc_list *pwd_file_list, \
int *check, char path[])
{
	t_wc_list	*all_file_list;
	t_token		*memo;
	char		*str;

	memo = token;
	all_file_list = make_token_file_list_sub(memo, pwd_file_list, check, path);
	return (all_file_list);
}

t_wc_list	*make_token_file_list_sub(t_token *memo, t_wc_list *all_file_list, \
int *check, char path[])
{
	char	*str;

	while (memo != NULL)
	{
		if (memo->type == 13)
		{
			str = check_path(memo->content, path, check);
			if (*check == 0 && str == NULL)
			{
				memo = memo->next;
				continue ;
			}
			if (*check == 1 && str == NULL)
				return (NULL);
			all_file_list = append_list(all_file_list, str, check);
			if (all_file_list == NULL)
			{
				free(str);
				return (NULL);
			}
			free(str);
		}
		memo = memo->next;
	}
	return (all_file_list);
}

char	*check_path(char *str, char path[], int	*check)
{
	int		len;
	char	*new_str;

	len = ft_strlen(str);
	while (str[len] != '/' && len >= 0)
		len--;
	if (len < 0)
	{
		new_str = ft_strdup(str);
		if (new_str == NULL)
			return (error_wl_card_char(strerror(errno), check));
		return (new_str);
	}
	if (len == 1 || str[len - 1] == '.')
	{
		new_str = ft_strdup(&str[len + 1]);
		if (new_str == NULL)
			return (error_wl_card_char(strerror(errno), check));
	}
	else
		new_str = check_path_str(path, str, new_str, check);
	return (new_str);
}

char	*check_path_str(char path[], char *str, char *new_str, int *check)
{
	int	len;
	int	count;
	int	save;

	len = ft_strlen(path);
	save = len + 2;
	count = 0;
	if (strncmp(path, str, len) == 0)
	{
		while (str[len] != 0)
		{
			len++;
			if (str[len] == '/')
				count++;
		}
		if (count == 0 || count >= 2)
			return (NULL);
		new_str = ft_strdup(&str[save]);
		if (new_str == NULL)
			return (error_wl_card_char(strerror(errno), check));
	}
	return (NULL);
}

t_wc_list	*add_token_file_list(char *str, int *check)
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
