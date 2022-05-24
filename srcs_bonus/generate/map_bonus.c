/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:25:23 by darian            #+#    #+#             */
/*   Updated: 2022/05/20 14:31:44 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

char	**free_before_map(int i, char **map)
{
	int	j;

	j = 0;
	while (j < i)
		free(map[j++]);
	free(map);
	return (NULL);
}

static char	**resize_y_body(t_vector2D *size, char **new,
	char **map, t_alloc *alloc)
{
	int	i;

	i = 0;
	while (i < size->y)
	{
		new[i] = ft_strdup(map[i], alloc);
		if (!new[i])
			return (NULL);
		i++;
	}
	while (i < size->x)
	{
		new[i] = ft_str_add("\0", size->x, '1', alloc);
		if (!new[i])
			return (NULL);
		i++;
	}
	new[i] = NULL;
	return (new);
}

static char	**resize_y(t_vector2D *size, char **map, t_alloc *alloc)
{
	char	**new;

	new = ft_malloc(sizeof(char *) * (size->x + 1), &alloc);
	if (!new)
		return (NULL);
	if (!resize_y_body(size, new, map, alloc))
		return (NULL);
	size->y = size->x;
	return (new);
}

static char	**resize_x(t_vector2D *size, char **map, t_alloc *alloc)
{
	char	**new;
	int		i;

	i = 0;
	new = ft_malloc(sizeof(char *) * (size->y + 1), &alloc);
	if (!new)
		return (NULL);
	while (map[i])
	{
		new[i] = ft_str_add(map[i], size->y - size->x, '1', alloc);
		if (!new[i])
			return (NULL);
		i++;
	}
	new[i] = NULL;
	size->x = size->y;
	return (new);
}

char	**resize_map(char **map, t_vector2D *size, t_alloc *alloc)
{
	if (size->x == size->y)
		return (map);
	if (size->x < size->y)
		return (resize_x(size, map, alloc));
	else
		return (resize_y(size, map, alloc));
}
