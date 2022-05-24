/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:09:40 by darian            #+#    #+#             */
/*   Updated: 2022/05/21 15:47:23 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

int	is_obstacle(char **map, t_vector2D pos, int dir, t_vector2D size)
{
	if (dir == TOP && pos.y - 1 >= 0 && (map[pos.y - 1][pos.x] < '1'
		|| map[pos.y - 1][pos.x] > '7') && map[pos.y - 1][pos.x] != 'G')
		return (0);
	if (dir == BOTTOM && pos.y + 1 <= size.y - 1 && (map[pos.y + 1][pos.x] < '1'
		|| map[pos.y + 1][pos.x] > '7') && map[pos.y + 1][pos.x] != 'G')
		return (0);
	if (dir == LEFT && pos.x - 1 >= 0 && (map[pos.y][pos.x - 1] < '1'
		|| map[pos.y][pos.x - 1] > '7') && map[pos.y][pos.x - 1] != 'G')
		return (0);
	if (dir == RIGHT && pos.x + 1 <= size.x - 1 && (map[pos.y][pos.x + 1] < '1'
		|| map[pos.y][pos.x + 1] > '7') && map[pos.y][pos.x + 1] != 'G')
		return (0);
	return (1);
}

void	player_dead(t_vars *vars, t_vector2D pos)
{
	if (pos.x == vars->last_pos.x && pos.y == vars->last_pos.y)
	{
		mlx_loop_end(vars->mlx);
		ft_putstr_fd("You lose...\n", 1);
	}
}
