/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_and_key_call.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:26:06 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/21 15:47:43 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

void	global_win_handling(t_vars *vars)
{
	if (vars->new_menu == 1)
		launch_new_menu_win(vars);
	if (vars->new_game == 1)
		launch_new_game_win(vars);
	if (vars->new_mini_win == 1)
		launch_new_mini_win(vars);
	if (vars->new_editor_win == 1)
		launch_new_editor_win(vars);
}

static void	global_key_handling_2(t_vars *vars)
{
	if (vars->mode == GAME)
	{
		mlx_hook(vars->win, 17, 0, close_win, vars);
		mlx_hook(vars->win, 2, 1L << 0, key_handling, vars);
	}	
	else if (vars->mode == EDITOR_MAPS)
	{
		mlx_hook(vars->win, 17, 0, close_win, vars);
		mlx_hook(vars->win, 2, 1L << 0, editor_maps_key, vars);
	}
	else if (vars->mode == MENU_MAPS)
	{
		mlx_hook(vars->win, 17, 0, close_win, vars);
		mlx_hook(vars->win, 2, 1L << 0, menu_maps_key, vars);
	}
}

void	global_key_handling(t_vars *vars)
{
	if (vars->mode == EDITOR)
	{
		mlx_hook(vars->menu.win, 17, 0, close_win, vars);
		mlx_hook(vars->menu.win, 2, 1L << 0, editor_key, vars);
	}
	else if (vars->mode == MENU)
	{
		mlx_hook(vars->win, 17, 0, close_win, vars);
		mlx_hook(vars->win, 2, 1L << 0, menu_key, vars);
	}
	else if (vars->mode == EDITOR_MENU)
	{
		mlx_hook(vars->win, 17, 0, close_win, vars);
		mlx_hook(vars->win, 2, 1L << 0, key_handling, vars);
	}
	else
		global_key_handling_2(vars);
	check_end(vars);
}

void	global_update_handling(t_vars *vars)
{
	if (vars->mode == GAME)
		game_updating(vars);
	else if (vars->mode == MENU)
		menu_updating(vars);
	else if (vars->mode == EDITOR_MENU)
		editor_menu_updating(vars);
	else if (vars->mode == EDITOR)
		editor_updating(vars);
	else if (vars->mode == EDITOR_MAPS)
		editor_maps_updating(vars);
	else
		menu_maps_updating(vars);
}

int	updating(t_vars *vars)
{
	global_win_handling(vars);
	global_key_handling(vars);
	global_update_handling(vars);
	return (0);
}
