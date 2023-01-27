#include "minishell.h"
#include "./libft/libft.h"

char	**wildcard(char *str)
{
	char	path[1024];
	char	**file_name_list;
	char	**wild_card_list;
	
	if (getcwd(path, 1024) == NULL) 
		return (error_wl_card(strerror(errno)));
	file_name_list = make_file_list(path);
	if (file_name_list == NULL)
		return (NULL);
	wild_card_list = make_wildcard_list(file_name_list, str);
	if (wild_card_list == NULL)
		return (NULL);
	return (wild_card_list);
}

char	**make_wildcard_list(char **file_list, char *str)
{
	char	**check_list;
	char	**wild_list;

	check_list = make_check_list(str);
	
	wild_list = fide_wild_card(file_list, front_s, back_s);
}

char	**make_check_list(char *str)
{
	char	**str;

	
}

char	**fide_wild_card(char **file_list, char	*front_s, char *back_s)
{
	char	**save_str;
	int		i;

	i = 0;
	while (file_list[i] != NULL)
	{
		save_str = make_wlcd_list(save_str, file_list[i], front_s, back_s);

	}
}

char	**make_wlcd_list(char **arr, char *str, char *f_s, char *b_s)
{
	char	**sv_arr;


}

char	**make_file_list(char *path)
{
	DIR				*dir_ptr;
	char			**save_str;

	dir_ptr = NULL;
	if((dir_ptr = opendir(path)) == NULL) 
        return(error_wl_card(strerror(errno)));
	save_str = readdir_all(dir_ptr);
	closedir(dir_ptr);
	if (save_str == NULL)
		return (NULL);
	return (save_str);
}


char	**readdir_all(DIR *dir_ptr)
{
	struct dirent	*file;
	char			**save_file_name;
	int				i;

	file = readdir(dir_ptr);
	i = 2;
	while (file != NULL)
	{
		save_file_name = make_name_arr(file->d_name, save_file_name, i);
		if (save_file_name == NULL)
			return (free_save_file(save_file_name));
		i++;
	}
	return (save_file_name);
}

char	**free_save_file(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**make_name_arr(char *str, char **arr, int len)
{
	char	**new_arr;
	int		i;

	new_arr = (char **)malloc(sizeof(char *) * len);
	if (new_arr == NULL)
		return (error_wl_card(strerror(errno)));
	i = 0;
	if (arr != NULL)
	{
		while(i < len - 1)
		{
			new_arr[i] = arr[i];
			i++;
		}
	}
	free(arr);
	new_arr[i] = ft_strdup(str);
	if (new_arr[i] == NULL)
		return (error_wl_card(strerror(errno)));
	new_arr[len] = NULL;
	return (new_arr);
}

char	**error_wl_card(char *str)
{
	ft_putstr_fd("Error, ", 2);
	ft_putendl_fd(str, 2);
	return (NULL);
}