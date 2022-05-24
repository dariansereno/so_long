/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:49:20 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/21 17:07:44 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

int	menu(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->menu.buttons[1].img,
		((vars->size.x * 64) / 2) - 64, 100);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->menu.buttons[2].img,
		((vars->size.x * 64) / 2) - 64, 200);
	return (0);
}

void	reinitialise_game_data(t_vars *vars)
{
	vars->li_guards = generate_guard_list(vars->map, vars->alloc);
	vars->moves = 0;
	vars->items = 0;
	vars->total_items = 0;
	vars->finish = 0;
	vars->stopped = 0;
	vars->ending = 0;
	vars->p_pos = (t_vector2D){0, 0};
	vars->last_pos = (t_vector2D){0, 0};
	vars->new_game = 1;
}

void	complete_menu_maps(t_vars *vars, t_vector2D size)
{
	vars->save = double_str_dup(vars->map, size, &vars->alloc);
	vars->last_pos = search_char(vars->map, 'P');
	vars->p_pos = vars->last_pos;
}
