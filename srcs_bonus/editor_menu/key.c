/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:30:35 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/20 15:05:16 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

int	count_maps(char **maps)
{
	int	i;

	i = 0;
	while (maps[i])
		i++;
	return (i);
}

void	confirm_size(t_vars *vars)
{
	vars->menu.map = create_editor_map_base(vars->menu.size_map, vars->alloc);
	vars->mode = EDITOR;
	vars->new_win = 1;
	vars->ed_pos.x = 0;
	vars->ed_pos.y = 0;
	vars->editor.name[0] = 0;
	vars->editor.index = 0;
	vars->new_mini_win = 1;
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
	vars->new_editor_win = 1;
}

void	editor_menu_key(int k, t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	if (k == ESC)
		vars->mode = MENU;
	if (k == ARROW_UP)
	{
		vars->user_maps = exec_ls(&vars->alloc);
		vars->user_maps = parse_maps_name(vars->user_maps, vars->alloc);
		vars->mode = EDITOR_MAPS;
		vars->nb_maps = count_maps(vars->user_maps);
	}
	if (k >= ZERO && k <= NINE && vars->menu.size_map * 10 <= 40)
		vars->menu.size_map = vars->menu.size_map * 10 + (k - 48);
	if (k == RETURN)
		vars->menu.size_map = vars->menu.size_map / 10;
	if (k == ENTER && vars->menu.size_map >= 4 && vars->menu.size_map <= 40)
		confirm_size(vars);
}
