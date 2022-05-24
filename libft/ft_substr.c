/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:41:12 by dasereno          #+#    #+#             */
/*   Updated: 2022/03/29 14:23:31 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_len(char const *s, size_t len, unsigned int start)
{
	if (len > (ft_strlen(s) - (size_t)start))
		return (ft_strlen(s) - (size_t)start);
	if (ft_strlen(s) < len)
		return (ft_strlen(s));
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len,
	t_alloc *alloc)
{
	char	*new;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s) || len == 0)
	{
		new = ft_malloc(sizeof(char) * 1, &alloc);
		if (!new)
			return (NULL);
		new[0] = 0;
		return (new);
	}
	new = ft_malloc(sizeof(char) * (check_len(s, len, start) + 1), &alloc);
	if (!new)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = 0;
	return (new);
}
