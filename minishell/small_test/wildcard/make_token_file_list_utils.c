#include "../minishell.h"
#include "../libft/libft.h"

t_wc_list	*append_list(t_wc_list *pwd_file_list, char *str, int *check)
{
	t_wc_list	*memo;

	memo = pwd_file_list;
	pwd_file_list = append_list_sub(pwd_file_list, str, check);
	pwd_file_list = append_list_sub2(pwd_file_list, str, check);
	return (pwd_file_list);
}

t_wc_list	*append_list_sub(t_wc_list *pwd_file_list, char *str, int *check)
{
	t_wc_list	*save;
	int			cas;

	save = NULL;
	cas = check_aski(pwd_file_list->str, str);
	if (cas == 1)
	{
		save = add_token_file_list(str, check);
		if (save == NULL)
		{
			free_wc_list(pwd_file_list);
			return (NULL);
		}
		save->next = pwd_file_list;
		pwd_file_list = save;
	}
	return (pwd_file_list);
}

t_wc_list	*append_list_sub2(t_wc_list *pwd_file_list, char *str, int *check)
{
	t_wc_list	*before_memo;
	t_wc_list	*save;
	t_wc_list	*memo;
	int			cas;

	memo = pwd_file_list;
	while (memo != NULL)
	{
		cas = check_aski(memo->str, str);
		if (cas == 2)
			break ;
		if (cas == 1)
		{
			save = add_token_file_list(str, check);
			if (save == NULL)
				return (free_wc_list(pwd_file_list));
			before_memo->next = save;
			before_memo->next->next = memo;
			break ;
		}
		before_memo = memo;
		memo = memo->next;
	}
	return (pwd_file_list);
}

int	check_aski(char *s1, char *s2)
{
	int	len_s1;
	int	len_s2;
	int	max_len;
	int	ans;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	max_len = len_s1;
	if (len_s1 < len_s2)
		max_len = len_s2;
	ans = ft_strncmp_wildcard(s1, s2, max_len);
	if (ans > 0)
		return (1);
	if (ans == 0)
		return (2);
	return (0);
}

int	ft_strncmp_wildcard(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n)
	{
		if (ft_tolower(s1[len]) != ft_tolower(s2[len]))
			return ((unsigned char)s1[len] - (unsigned char)s2[len]);
		if (s1[len] == 0 && s2[len] == 0)
			return (0);
		len++;
	}
	return (0);
}
