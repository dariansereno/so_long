/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 09:35:44 by darian            #+#    #+#             */
/*   Updated: 2022/05/21 14:24:48 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

int	is_valid_wall_map(char **map, t_vector2D size, t_vars *vars, int *err)
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
			if (map[it.y][it.x] == 'G')
				vars->is_guards = 1;
			it.x++;
		}
		it.y++;
	}
	return (1);
}

int	parse_map(char **map, int *p, int *c, int *e)
{
	t_vector2D	it;

	it = (t_vector2D){0, 0};
	while (map[it.y])
	{
		it.x = 0;
		while (map[it.y][it.x])
		{
			if (map[it.y][it.x] != 'P' && map[it.y][it.x] != 'C'
				&& map[it.y][it.x] != 'E' && map[it.y][it.x] != '0'
					&& map[it.y][it.x] != 'G'
					&& (map[it.y][it.x] < 'a' || map[it.y][it.x] > 'z')
					&& (map[it.y][it.x] < '1' || map[it.y][it.x] > '7' ))
				return (-3);
			if (map[it.y][it.x] == 'P')
				*p += 1;
			if (map[it.y][it.x] == 'C')
				*c += 1;
			if (map[it.y][it.x] == 'E')
				*e += 1;
			it.x++;
		}
		it.y++;
	}
	return (0);
}

int	is_valid_char_map(char **map, int *c, int *fd)
{
	int			p;
	int			e;

	if (*fd)
		close(*fd);
	p = 0;
	e = 0;
	*c = 0;
	if (parse_map(map, &p, c, &e) < 0)
		return (-3);
	if (e < 1 || *c == 0 || p < 1)
		return (-5);
	return (p);
}

int	is_valid_size_map(char **map, t_vector2D *size, int *err)
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
		|| !is_valid_wall_map(map, *size, vars, fd))
	{
		if (p < 0)
			*fd = p;
		return (NULL);
	}
	if (p > 1)
		several_start_selecting(map, p);
	return (map);
}
