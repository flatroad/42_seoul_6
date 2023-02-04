/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:17:55 by sounchoi          #+#    #+#             */
/*   Updated: 2022/03/30 21:17:56 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_memo;

	if (del == 0)
		return ;
	lst_memo = 0;
	while (*lst != 0)
	{
		del((**lst).content);
		lst_memo = (**lst).next;
		free(*lst);
		*lst = lst_memo;
	}
}
