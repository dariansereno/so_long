/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:10:12 by dasereno          #+#    #+#             */
/*   Updated: 2022/03/29 14:25:03 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *),
	t_alloc *alloc)
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(f(lst->content), alloc);
	if (!new)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = ft_lstnew(f(lst->content), alloc);
		if (!tmp)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
