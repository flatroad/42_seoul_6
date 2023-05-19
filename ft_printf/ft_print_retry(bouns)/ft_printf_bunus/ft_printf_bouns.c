#include "ft_printf_bonus.h"

int	ft_printf_bouns(const char *str, ...)
{
	va_list	list;
	t_list	*token_list;
	int		stack[2];
	char	*str_ptr;
	int		count;

	va_start(list, str);
	str_ptr = str;
	token_list = tokenizer(list, stack, str_ptr);
	if (token_list == NULL)
	{
		ft_putendl_fd("pf_token fail..\n", 2);
		return (-1);
	}
	count = exec_pf(token_list);
	return (count);
}

t_list	*tokenizer(va_list list, int stack[2], char *str)
{
	int	i;
	int	flag;
	t_list	*token;
	t_list	*st_token;

	i = 0;
	flag = 0;
	while (str[i] != 0)
	{
		stack[0] = i;
		stack[1] = 0;
		token = mk_token(token, str, &i);
		if (flag == 0)
		{
			st_token = token;
			flag = 1;
		}
		if (token == NULL)
		{
			ft_lstclear(st_token, ft_lstdelone);
			return (NULL);
		}
		i++;
	}
	return (st_token);
}

t_list	*mk_token(t_list *token, char *str, int *i)
{
	t_obj		*obj;
	t_list		*new_token;

	if (str[*i] == '%')
	{
		var = mk_not_var(token, str, i);
		new_token = ft_lstnew((void *)var);
	}
	else
	{
		n_var = mk_var(token, str, i);
		new_token = ft_lstnew((void *)n_var);
	}
	if (token == NULL)
		token = new_token;
	else
	{
		token->next = new_token;
		token = token->next;
	}
	return (token);
}

t_var	*mk_var(t_list *token, char *str, int *i)
{
	int		stack[2];
	int		type;
	t_var	*var;

	stack[0] = *i;
	type = 0;
	while (str[*i] != 0)
	{
		type = type_checker(str[*i]);
		if (type == 0)
			*i++;
		else
		{
			stack[1] = *i;
			var = new_var(str, stack, type);
			if (var == NULL)
				return (NULL);
			break ;
		}
	}
	return (var);
}

t_var	*new_var(char *str, int stack[2], int type)
{
	t_var	*new_var;

	new_var = (t_var *)malloc(sizeof(t_var) * 1);
	if (new_var == NULL)
		return (NULL);
	new_var->type = type;
	new_var = new_var_checker(str, stack);
	return (new_n_var);
}

int	type_checker(int c)
{
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (2);
	else if (c == 'p')
		return (3);
	else if (c == 'd')
		return (4);
	else if (c == 'i')
		return (5);
	else if (c == 'u')
		return (6);
	else if (c == 'x')
		return (7);
	else if (c == 'X')
		return (8);
	else if (c == '%')
		return (9);
	return (0);
}

t_not_var	*mk_n_var(t_list *token, char *str, int *i)
{
	t_not_var	*n_var;
	int	stack[2];

	stack[0] = *i;
	while (str[*i] != '%')
		*i++;
	stack[1] = *i;
	n_var = new_n_var(str, stack);
	if (n_var == NULL)
		return (NULL);
}

t_not_var	*new_n_var(char *str, int stack[2])
{
	t_not_var	*new_n_var;

	new_n_var = (t_not_var *)malloc(sizeof(t_not_var) * 1);
	if (new_n_var == NULL)
		return (NULL);
	new_n_var->type = 0;
	new_n_var->str = ft_substr(str, stack[0], stack[1]);
	if (new_n_var == NULL)
	{
		free(new_n_var);
		return (NULL);
	}
	new_n_var->len = ft_strlen(new_n_var->str);
	return (new_n_var);
}
