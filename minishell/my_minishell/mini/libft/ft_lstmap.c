/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:18:22 by sounchoi          #+#    #+#             */
/*   Updated: 2022/03/30 21:18:24 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_born;
	t_list	*lst_born_ft;

	if (lst == 0 || f == 0 || del == 0)
		return (0);
	lst_born_ft = ft_lstnew((*f)(lst->content));
	if (lst_born_ft == 0)
		return (0);
	lst_born = lst_born_ft;
	lst = lst->next;
	while (lst != 0)
	{
		lst_born->next = ft_lstnew((*f)(lst->content));
		if (lst_born->next == 0)
		{
			ft_lstclear(&lst, del);
			return (0);
		}
		lst_born = lst_born->next;
		lst = lst->next;
	}
	return (lst_born_ft);
}
