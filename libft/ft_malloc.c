/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:52:50 by darian            #+#    #+#             */
/*   Updated: 2022/04/01 22:51:49 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_malloc_clear(t_alloc **lst)
{
	t_alloc	*tmp;

	if (*lst)
	{
		while (*lst != NULL)
		{
			tmp = (*lst)->next;
			if ((*lst)->ptr)
				free((*lst)->ptr);
			free(*lst);
			*lst = tmp;
		}
	}
}

void	malloc_add(t_alloc **alst, t_alloc *new)
{
	t_alloc	*tmp;

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

t_alloc	*malloc_new(void *content)
{
	t_alloc	*li;

	li = malloc(sizeof(*li));
	if (!li)
		return (NULL);
	li->ptr = content;
	li->next = NULL;
	return (li);
}

void	*ft_malloc(int size, t_alloc	**lst)
{
	void	*alloc;

	alloc = malloc(size);
	if (!alloc)
		return (NULL);
	malloc_add(lst, malloc_new(alloc));
	return (alloc);
}
