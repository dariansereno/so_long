/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:26:00 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/21 16:54:08 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

int	check_init(t_vars *vars)
{
	int	i;

	if (!vars->jump || !vars->slime || !vars->win || !vars->sprites
		|| !vars->player.sprite || (vars->is_guards && !vars->li_guards)
		|| !vars->mini || !vars->special || !vars->special_h
		|| !vars->wall_special || !vars->wall_special_h)
		return (0);
	i = 0;
	while (i <= 5)
	{
		if (!vars->menu.buttons[i].img)
			return (0);
		i++;
	}
	return (1);
}

int	initialise_global_6(t_vars *vars)
{
	vars->seed = random_seed(30, vars->random);
	close(vars->random);
	vars->stopping = 0;
	vars->new_frozen = 0;
	vars->frozen = 0;
	vars->frozed = 0;
	vars->pos_changed = 0;
	return (1);
}

int	initialise_global_5(t_vars *vars)
{
	vars->menu.buttons[0] = generate_image(*vars,
			"./textures/menu/play.xpm", &vars->img_alloc);
	vars->menu.buttons[1] = generate_image(*vars,
			"./textures/menu/play_s.xpm", &vars->img_alloc);
	vars->menu.buttons[2] = generate_image(*vars,
			"./textures/menu/editor.xpm", &vars->img_alloc);
	vars->menu.buttons[3] = generate_image(*vars,
			"./textures/menu/editor_s.xpm", &vars->img_alloc);
	vars->menu.buttons[4] = generate_image(*vars,
			"./textures/menu/maps.xpm", &vars->img_alloc);
	vars->menu.buttons[5] = generate_image(*vars,
			"./textures/menu/maps_s.xpm", &vars->img_alloc);
	vars->special = generate_special(vars);
	vars->special_h = generate_special_h(vars);
	vars->wall_special = generate_wall(vars);
	vars->wall_special_h = generate_wall_h(vars);
	vars->win = mlx_new_window(vars->mlx, vars->size.y * 64,
			(vars->size.x * 32) + 43, "so_long");
	if (!check_init(vars))
		return (-1);
	return (initialise_global_6(vars));
}
