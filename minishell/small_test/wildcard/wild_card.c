#include "../minishell.h"
#include "../libft/libft.h"

t_wc_list	*wildcard(char *str, t_token *token)
{
	char		path[1024];
	t_wc_list	*pwd_file_list;
	t_wc_list	*all_file_list;
	t_wc_list	*wildcard_list;
	int			check;

	check = 0;
	if (getcwd(path, 1024) == NULL)
		return (error_wl_card(strerror(errno), &check));
	pwd_file_list = make_pwd_file_list(path, &check);
	if (pwd_file_list == NULL && check == 1)
		return (NULL);
	pwd_file_list = order_list(pwd_file_list);
	all_file_list = make_token_file_list(token, pwd_file_list, &check, path);
	if (all_file_list == NULL && check == 1)
		return (NULL);
	wildcard_list = make_wildcard_list(all_file_list, str, &check);
	if (wildcard_list == NULL && check == 1)
		return (NULL);
	if (wildcard_list == NULL && check == 0)
		wildcard_list = add_wc_list(str, &check);
	return (wildcard_list);
}
