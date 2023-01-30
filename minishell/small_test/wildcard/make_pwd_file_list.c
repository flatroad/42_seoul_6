#include "../minishell.h"
#include "../libft/libft.h"

t_wc_list	*make_pwd_file_list(char *path, int *check)
{
	DIR				*dir_ptr;
	t_wc_list		*file_list;

	dir_ptr = NULL;
	dir_ptr = opendir(path);
	if (dir_ptr == NULL)
		return (error_wl_card(strerror(errno), check));
	file_list = readdir_all(dir_ptr, check);
	closedir(dir_ptr);
	if (file_list == NULL)
		return (NULL);
	return (file_list);
}

t_wc_list	*readdir_all(DIR *dir_ptr, int *check)
{
	struct dirent	*file;
	t_wc_list		*start_ptr;
	t_wc_list		*memo;

	file = set_file(file, dir_ptr);
	if (file == NULL)
		return (NULL);
	start_ptr = make_file_list(file->d_name, memo, check);
	if (start_ptr == NULL)
		return (NULL);
	file = readdir(dir_ptr);
	memo = start_ptr;
	while (file != NULL)
	{
		memo->next = make_file_list(file->d_name, memo, check);
		if (memo->next == NULL)
			return (free_wc_list(start_ptr));
		memo = memo->next;
		file = readdir(dir_ptr);
	}
	return (start_ptr);
}

struct dirent	*set_file(struct dirent *file, DIR *dir_ptr)
{
	file = readdir(dir_ptr);
	while (1)
	{
		if (ft_strncmp(file->d_name, ".", 3) == 0)
			file = readdir(dir_ptr);
		if (ft_strncmp(file->d_name, "..", 4) == 0)
			file = readdir(dir_ptr);
		else
			break ;
	}
	return (file);
}

t_wc_list	*make_file_list(char *str, t_wc_list *memo, int *check)
{
	memo = (t_wc_list *)malloc(sizeof(t_wc_list) * 1);
	if (memo == NULL)
		return (error_wl_card(strerror(errno), check));
	memo->str = ft_strdup(str);
	if (memo->str == NULL)
		return (error_wl_card(strerror(errno), check));
	memo->next = NULL;
	return (memo);
}
