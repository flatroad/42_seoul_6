/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tran_envp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 09:45:30 by sounchoi          #+#    #+#             */
/*   Updated: 2023/02/04 10:07:45 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**tran_envp(t_envp_list	*list)
{
	char		**str;
	int			len;
	t_envp_list	*memo;
	int			i;

	memo = list;
	len = 0;
	len = check_len(list);
	i = 0;
	str = (char **)malloc(sizeof(char *) * len);
	if (str == NULL)
		return (NULL);
	while (memo != NULL)
	{
		if (memo->key == NULL || memo->value == NULL)
			memo = memo->next;
		str[i] = ft_strjoin_three(memo->key, "=", \
		memo->value);
		i++;
		memo = memo->next;
	}
	str[i] = NULL;
	return (str);
}

int	check_len(t_envp_list *s_list)
{
	int			len;
	t_envp_list	*memo;

	len = 0;
	memo = s_list;
	while (memo != NULL)
	{
		if (memo->key == NULL || memo->next == NULL)
		{
			memo = memo->next;
			continue ;
		}
		len++;
		memo = memo->next;
	}
	return (len);
}
