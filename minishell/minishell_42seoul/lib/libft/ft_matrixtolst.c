/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixtolst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:54:28 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/02 19:37:25 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_matrixtolst(char **matrix)
{
	t_list	*lst;
	int		i;

	lst = NULL;
	i = -1;
	while (matrix[++i])
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(matrix[i])));
	return (lst);
}
