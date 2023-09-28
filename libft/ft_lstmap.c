/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 08:03:21 by agomes-g          #+#    #+#             */
/*   Updated: 2023/05/10 08:03:23 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nvl;
	t_list	*nv;

	nvl = NULL;
	while (lst)
	{
		nv = ft_lstnew((*f)(lst->content));
		lst = lst->next;
		ft_lstadd_back(&nvl, nv);
	}
	ft_lstclear(&lst, del);
	return (nvl);
}
