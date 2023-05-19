/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redi_here.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:37:21 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/05 03:03:10 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_final(int type, char **args, int *i)
{
	char	c;

	c = 0;
	if (args && args[*i + 1])
		c = args[*i + 1][0];
	if (type == 3 && args[*i][0] != args[*i + 1][0])
	{
		if (c == '>')
			return (-1);
	}
	if (type == 4 && args[*i][0] != args[*i + 1][0])
	{
		if (c == '<')
			return (-1);
	}
	return (type);
}

int	check_redi_here(char **args, int *i)
{
	int	len;
	int	type;

	len = 2;
	type = 0;
	if (args[*i + 1][0] && args[*i][0] == '<' && args[*i + 1][0] == '<')
		type = 1;
	else if (args[*i + 1][0] && args[*i][0] == '>' && args[*i + 1][0] == '>')
		type = 2;
	else
	{
		len = 1;
		if (args[*i][0] == '<')
			type = 3;
		else if (args[*i][0] == '>')
			type = 4;
	}
	type = check_final(type, args, i);
	*i += len;
	if (type > 0)
		return (type);
	return (-1);
}

int	check_rdhd_syntax(char **a)
{
	int		i;
	char	c;
	int		check;

	i = 0;
	c = 0;
	check = 0;
	while (a && a[i])
	{	
		c = a[i][0];
		if (a[i + 1] && (c == '<' | c == '>'))
		{
			check = check_redi_here(a, &i);
			if ((a[i] && a[i][0] == c) && (a[i][0] == '<' || a[i][0] == '>'))
					check = -1;
			if (check == -1)
			{
				syntax_error_rdhd(check);
				return (check);
			}
		}
		else
			i++;
	}
	return (check);
}

void	syntax_error_rdhd(int check)
{
	if (check == -1)
		ft_perror(RDERR, NULL, 258);
	return ;
}
