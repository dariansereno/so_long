/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:54:18 by dasereno          #+#    #+#             */
/*   Updated: 2022/03/29 14:20:17 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size, t_alloc *alloc)
{
	char	*new;

	new = ft_malloc(size * count, &alloc);
	if (!new)
		return (NULL);
	ft_bzero(new, count * size);
	return (new);
}
