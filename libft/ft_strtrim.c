/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:44:13 by dasereno          #+#    #+#             */
/*   Updated: 2022/03/29 14:22:49 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	find_start_index(char const *str, char const *set)
{
	int	i;

	i = 0;
	while (is_set(str[i], set))
		i++;
	return (i);
}

static int	find_end_index(char const *str, char const *set)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i - 1 >= 0 && is_set(str[i], set))
		i--;
	return (i);
}

static char	*if_zero(char *new, t_alloc *alloc)
{
	new = ft_malloc(sizeof(char) * 1, &alloc);
	if (!new)
		return (NULL);
	new[0] = 0;
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set, t_alloc *alloc)
{
	int		start;
	int		end;
	int		i;
	char	*new;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	start = find_start_index(s1, set);
	end = find_end_index(s1, set);
	new = NULL;
	if (end - start < 0)
		return (if_zero(new, alloc));
	else
	{
		new = ft_malloc(sizeof(char) * (end - start + 2), &alloc);
		if (!new)
			return (NULL);
	}
	if (!s1)
		return (NULL);
	while (start <= end)
		new[i++] = s1[start++];
	new[i] = 0;
	return (new);
}
