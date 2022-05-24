/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 09:35:44 by darian            #+#    #+#             */
/*   Updated: 2022/05/20 15:19:54 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	is_valid_wall_map(char **map, t_vector2D size, int *err)
{
	t_vector2D	it;

	it.y = 0;
	it.x = 0;
	while (map[it.y])
	{
		it.x = 0;
		while (map[it.y][it.x])
		{
			if (!check_size(it, size, map, err))
				return (0);
			it.x++;
		}
		it.y++;
	}
	return (1);
}

static void	check_char(char block, int *p, int *c, int *e)
{
	if (block == 'P')
		*p += 1;
	if (block == 'C')
		*c += 1;
	if (block == 'E')
		*e += 1;
}

static int	is_valid_char_map(char **map, int *c, int *fd)
{
	t_vector2D	it;
	int			p;
	int			e;

	close(*fd);
	it.y = 0;
	p = 0;
	e = 0;
	while (map[it.y])
	{
		it.x = 0;
		while (map[it.y][it.x])
		{
			if (map[it.y][it.x] != 'P' && map[it.y][it.x] != 'C'
				&& map[it.y][it.x] != 'E' && map[it.y][it.x] != '1'
					&& map[it.y][it.x] != '0')
				return (-3);
			check_char(map[it.y][it.x], &p, c, &e);
			it.x++;
		}
		it.y++;
	}
	if (e < 1 || *c == 0 || p < 1)
		return (-5);
	return (p);
}

static int	is_valid_size_map(char **map, t_vector2D *size, int *err)
{
	t_vector2D	it;
	int			size_line;

	it.y = 0;
	it.x = 0;
	size_line = 0;
	while (map[it.y])
	{
		it.x = 0;
		while (map[it.y][it.x])
			it.x++;
		if (it.y == 0)
			size_line = it.x;
		else if (it.x != size_line)
		{
			*err = -6;
			return (0);
		}
		it.y++;
	}
	(*size).x = size_line;
	(*size).y = it.y;
	return (1);
}

char	**read_map(int *fd, t_vector2D *size, int *items, t_vars	*vars)
{
	char	*buf;
	char	**map;
	int		p;

	if (*fd < 1)
		return (NULL);
	buf = read_file(*fd, &vars->alloc);
	if (!buf)
		return (NULL);
	map = ft_split(buf, '\n', &vars->alloc);
	if (!map)
		return (NULL);
	p = is_valid_char_map(map, items, fd);
	if (p < 0 || !is_valid_size_map(map, size, fd)
		|| !is_valid_wall_map(map, *size, fd))
	{
		if (p < 0)
			*fd = p;
		return (NULL);
	}
	if (p > 1)
		several_start_selecting(map, p, vars);
	return (map);
}
