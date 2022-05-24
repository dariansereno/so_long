/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:24:32 by darian            #+#    #+#             */
/*   Updated: 2022/05/21 17:15:22 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	change_pos(t_vector2D pos, t_vector2D new_pos,
	t_vars *vars, int dir)
{
	if (new_pos.y >= 0 && (*vars).map[new_pos.y][new_pos.x] != '1')
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
	}
}

int	close_win(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	if (vars->finish == 1)
		ft_printf("You win in %d moves !!\n", vars->moves);
	vars->stopped = 1;
	return (0);
}

int	key_handling(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		close_win(vars);
	if (vars->stopped == 1 || vars->finish == 1)
		return (0);
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
	return (0);
}
