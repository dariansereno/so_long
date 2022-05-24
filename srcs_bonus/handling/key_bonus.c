/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:24:32 by darian            #+#    #+#             */
/*   Updated: 2022/05/21 17:15:38 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

static void	change_pos(t_vector2D pos, t_vector2D new_pos,
	t_vars *vars, int dir)
{
	if (new_pos.y >= 0 && ((*vars).map[new_pos.y][new_pos.x] < '1'
		|| (*vars).map[new_pos.y][new_pos.x] > '7')
			&& (*vars).map[new_pos.y][new_pos.x] != 'G')
	{
		(*vars).map[new_pos.y][new_pos.x] = 'P';
		(*vars).map[pos.y][pos.x] = '0';
		vars->player.direction = dir;
		vars->update = 1;
		vars->moves++;
		vars->p_pos = new_pos;
		if (vars->moves == 1)
			ft_printf("%d move\n", vars->moves);
		else
			ft_printf("%d moves\n", vars->moves);
		vars->last_pos = (t_vector2D){new_pos.x, new_pos.y};
		vars->pos_changed = 1;
	}
}

int	close_win(t_vars *vars)
{
	if (vars->finish == 1)
		ft_printf("You win in %d moves !!\n", vars->moves);
	vars->stopping = 1;
	return (0);
}

void	game_key(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_clear_window(vars->mlx, vars->win);
		vars->mode = MENU;
		vars->new_menu = 1;
	}
	if (vars->stopped == 1 || vars->finish == 1 || vars->frozen)
		return ;
	if (keycode == Z || keycode == W || keycode == ARROW_UP)
		change_pos(vars->p_pos,
			(t_vector2D){vars->p_pos.x, vars->p_pos.y - 1}, vars, NORTHWEST);
	else if (keycode == S || keycode == ARROW_DOWN)
		change_pos(vars->p_pos,
			(t_vector2D){vars->p_pos.x, vars->p_pos.y + 1}, vars, SOUTHEAST);
	else if (keycode == Q || keycode == A || keycode == ARROW_LEFT)
		change_pos(vars->p_pos,
			(t_vector2D){vars->p_pos.x + 1, vars->p_pos.y}, vars, SOUTHWEST);
	else if (keycode == D || keycode == ARROW_RIGHT)
		change_pos(vars->p_pos,
			(t_vector2D){vars->p_pos.x - 1, vars->p_pos.y}, vars, NORTHEAST);
}

int	key_handling(int keycode, t_vars *vars)
{
	if (vars->mode == GAME)
		game_key(keycode, vars);
	else if (vars->mode == MENU)
		menu_key(keycode, vars);
	else if (vars->mode == EDITOR_MENU)
		editor_menu_key(keycode, vars);
	return (0);
}
