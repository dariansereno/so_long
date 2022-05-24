/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:31:31 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/20 13:58:51 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

int	is_valid_char_map_open(char **map)
{
	t_vector2D	it;

	it.y = 0;
	while (map[it.y])
	{
		it.x = 0;
		while (map[it.y][it.x])
		{
			if (map[it.y][it.x] != 'P' && map[it.y][it.x] != 'C'
				&& map[it.y][it.x] != 'E' && map[it.y][it.x] != '0' && map[it.y]
				[it.x] != 'G' && (map[it.y][it.x] < 'a' || map[it.y][it.x]
					> 'z') && (map[it.y][it.x] < '1' || map[it.y][it.x] > '7' ))
				return (0);
			it.x++;
		}
		it.y++;
	}
	return (1);
}

int	is_valid_size_map_open(char **map, t_vector2D *size)
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
			return (0);
		it.y++;
	}
	(*size).x = size_line;
	(*size).y = it.y;
	if (size->x < 4 || size->y < 4 || size->x != size->y)
		return (0);
	return (1);
}

int	open_select_map_editor_maps(t_vars *vars)
{
	char		*buf;
	int			fd;
	char		*save;

	buf = ft_strjoin("./user_maps/",
			vars->user_maps[vars->map_select], &vars->alloc);
	fd = open(buf, O_RDONLY);
	if (fd == -1)
		return (0);
	save = read_file(fd, &vars->alloc);
	if (!save)
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_string_put(vars->mlx, vars->win, 10 * 64 / 2 - 120, 300,
			create_trgb(0, 255, 0, 0), "Invalid map.");
		return (0);
	}
	vars->menu.map = ft_split(save, '\n', &vars->alloc);
	close(fd);
	return (1);
}

int	check_map_and_reinitialise_value_editor_maps(t_vars *vars, t_vector2D size)
{
	if (!is_valid_char_map_open(vars->menu.map)
		|| !is_valid_size_map_open(vars->menu.map, &size))
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_string_put(vars->mlx, vars->win, 10 * 64 / 2 - 120, 300,
			create_trgb(0, 255, 0, 0), "Invalid map.");
		return (0);
	}
	vars->new_win = 1;
	vars->ed_pos.x = 0;
	vars->ed_pos.y = 0;
	vars->editor.name[0] = 0;
	vars->editor.index = 0;
	vars->new_mini_win = 1;
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
	vars->menu.size_map = size.x;
	vars->new_editor_win = 1;
	vars->mode = EDITOR;
	return (1);
}

int	editor_maps_key(int k, t_vars *vars)
{
	t_vector2D	size;

	size = (t_vector2D){0, 0};
	if (k == ESC)
	{
		mlx_clear_window(vars->mlx, vars->win);
		vars->mode = EDITOR_MENU;
	}
	if (k == ARROW_UP && vars->map_select > 0)
		vars->map_select--;
	if (k == ARROW_DOWN && vars->map_select < vars->nb_maps - 1)
		vars->map_select++;
	if (k == ENTER)
	{
		if (!open_select_map_editor_maps(vars))
			return (0);
		if (!check_map_and_reinitialise_value_editor_maps(vars, size))
			return (0);
	}
	return (0);
}
