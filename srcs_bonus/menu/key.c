/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:37:48 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/21 17:07:40 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

void	choose_selected_menu(t_vars *vars)
{
	if (vars->menu.selected == 0)
	{
		vars->new_game = 1;
		vars->mode = GAME;
	}
	else if (vars->menu.selected == 1)
	{
		vars->mode = EDITOR_MENU;
		mlx_clear_window(vars->mlx, vars->win);
	}
	else
	{
		vars->mode = MENU_MAPS;
		vars->user_maps = exec_ls(&vars->alloc);
		vars->user_maps = parse_maps_name(vars->user_maps, vars->alloc);
		vars->nb_maps = count_maps(vars->user_maps);
		mlx_clear_window(vars->mlx, vars->win);
	}
}

int	menu_key(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		close_win(vars);
	if (keycode == ARROW_UP && vars->menu.selected > 0)
		vars->menu.selected--;
	if (keycode == ARROW_DOWN && vars->menu.selected < 2)
		vars->menu.selected++;
	if (keycode == ENTER)
		choose_selected_menu(vars);
	vars->update = 1;
	return (0);
}

int	open_menu_maps(t_vars *vars)
{
	char		*save;
	char		*buf;
	int			fd;

	buf = ft_strjoin("./user_maps/",
			vars->user_maps[vars->select_m], &vars->alloc);
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
	vars->new_map_str = save;
	vars->real_new_map = ft_split(save, '\n', &vars->alloc);
	close(fd);
	return (1);
}

int	check_map_menu_maps(t_vars *vars)
{
	t_vector2D	size;
	int			p;
	int			useless;

	size = (t_vector2D){0, 0};
	useless = 0;
	if (!is_valid_char_map_open(vars->real_new_map)
		|| !is_valid_size_map_open(vars->real_new_map, &size)
		|| !is_valid_wall_map(vars->real_new_map, size, vars, &useless))
	{
		mlx_clear_window(vars->mlx, vars->win);
		mlx_string_put(vars->mlx, vars->win, 10 * 64 / 2 - 120, 300,
			create_trgb(0, 255, 0, 0), "Invalid map.");
		return (0);
	}
	vars->map = ft_split(vars->new_map_str, '\n', &vars->alloc);
	reinitialise_game_data(vars);
	p = is_valid_char_map(vars->map, &vars->total_items, &useless);
	if (p < 0 || !is_valid_size_map(vars->map, &vars->size, &useless)
		|| !is_valid_wall_map(vars->map, vars->size, vars, &useless))
		return (0);
	if (p > 1)
		vars->map = several_start_selecting(vars->map, p);
	complete_menu_maps(vars, size);
	return (1);
}

int	menu_maps_key(int k, t_vars *vars)
{
	if (k == ESC)
	{
		mlx_clear_window(vars->mlx, vars->win);
		vars->mode = MENU;
	}
	if (k == ARROW_UP && vars->select_m > 0)
		vars->select_m--;
	if (k == ARROW_DOWN && vars->select_m < vars->nb_maps - 1)
		vars->select_m++;
	if (k == ENTER)
	{
		if (!open_menu_maps(vars))
			return (0);
		if (!check_map_menu_maps(vars))
			return (0);
		vars->mode = GAME;
	}
	return (0);
}
