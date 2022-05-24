/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:27:22 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/21 17:14:05 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

static void	handle_player_update_2(t_vars *vars, t_vector2D pos)
{
	if ((*vars).save[pos.y][pos.x] == 'C')
	{
		vars->items++;
		ft_printf("%d/%d items collected!\n", vars->items, vars->total_items);
		(*vars).save[pos.y][pos.x] = '0';
	}
	if ((*vars).save[pos.y][pos.x] == 'E' && vars->items
		== vars->total_items && vars->ending == 0)
	{
		vars->jump_sp = 0;
		vars->finish = 1;
		vars->ending = 1;
	}
}

static void	handle_player_update(t_vars *vars)
{
	t_vector2D	pos;

	pos = search_char(vars->map, 'P');
	if (pos.x == -1 || pos.y == -1)
		return ;
	if ((*vars).save[pos.y][pos.x] == 'f')
	{
		mlx_loop_end(vars->mlx);
		ft_putstr_fd("You lose...\n", 1);
	}
	if (vars->frozed && vars->pos_changed)
	{
		vars->frozed = 0;
	}
	if ((*vars).save[pos.y][pos.x] == 'p' && !vars->frozed)
		vars->new_frozen = 1;
	handle_player_update_2(vars, pos);
}

static void	handle_global_update(t_vars *vars)
{
	if (vars->update == 1 && vars->finish == 0)
	{
		create_map(vars);
		vars->update = 0;
	}
	if (vars->ending == 1 && vars->update_ending == 1)
	{
		create_map_win(*vars);
		vars->update_ending = 0;
	}
}

void	game_updating(t_vars *vars)
{
	get_clock(&vars->cl_slime);
	get_clock(&vars->cl_guards);
	get_clock(&vars->cl_jump);
	if (vars->new_frozen)
	{
		vars->cl_frozen = clock_start();
		vars->new_frozen = 0;
		vars->frozen = 1;
		vars->frozed = 1;
	}
	if (vars->frozen)
		get_clock(&vars->cl_frozen);
	if (vars->stopped == 1)
		return ;
	handle_global_update(vars);
	handle_player_update(vars);
	display_score(vars);
	handle_clock(vars);
	vars->pos_changed = 0;
}
