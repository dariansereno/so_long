/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_wins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:24:32 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/21 15:27:14 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

void	launch_new_menu_win(t_vars *vars)
{
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->menu.win)
		mlx_destroy_window(vars->mlx, vars->menu.win);
	vars->win = mlx_new_window(vars->mlx, 10 * 64,
			(10 * 32) + 43, "so_long menu");
	vars->menu.win = NULL;
	vars->lock = 0;
	vars->ed_pos = (t_vector2D){0, 0};
	vars->editor.index = 0;
	vars->editor.name[0] = 0;
	vars->map_select = 0;
	vars->menu.selected = 0;
	vars->menu.size_map = 0;
	vars->new_menu = 0;
}

void	launch_new_game_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = mlx_new_window(vars->mlx, vars->size.y * 64,
			(vars->size.x * 32) + 43, "so_long");
	vars->new_game = 0;
}

void	launch_new_mini_win(t_vars *vars)
{
	vars->mini_win = mlx_new_window(vars->mlx, 30 * 4,
			40 * 10, "so_long blocks");
	vars->new_mini_win = 0;
	mini_editor_menu(vars);
}

void	launch_new_editor_win(t_vars *vars)
{
	vars->menu.win = mlx_new_window(vars->mlx, vars->menu.size_map * 64,
			(vars->menu.size_map * 32) + 43 + 50, "so_long editor");
	vars->new_editor_win = 0;
}

void	check_end(t_vars *vars)
{
	if (vars->stopping)
	{
		mlx_loop_end(vars->mlx);
		free_game(vars);
		exit(0);
	}
}
