/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:36:55 by darian            #+#    #+#             */
/*   Updated: 2022/04/01 22:41:57 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

void	guards_add(t_lst_guard **alst, t_lst_guard *new)
{
	t_lst_guard	*tmp;

	tmp = *alst;
	if (tmp == NULL)
	{
		*alst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	guards_clear(t_lst_guard **lst)
{
	t_lst_guard	*tmp;

	if (*lst)
	{
		while (*lst != NULL)
		{
			tmp = (*lst)->next;
			free(*lst);
			*lst = tmp;
		}
	}
}

t_lst_guard	*guards_new(t_guard content, int index, t_alloc *alloc)
{
	t_lst_guard	*li;

	li = ft_malloc(sizeof(*li), &alloc);
	if (!li)
		return (NULL);
	li->guard = content;
	li->index = index;
	li->next = NULL;
	return (li);
}

int	guards_size(t_lst_guard *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_lst_guard	*guards_find(t_lst_guard	*li, t_vector2D	pos)
{
	while (li)
	{
		if (li->guard.pos.x == pos.x && li->guard.pos.y == pos.y)
			return (li);
		li = li->next;
	}
	return (NULL);
}
