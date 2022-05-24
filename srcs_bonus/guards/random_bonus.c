/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:03:34 by darian            #+#    #+#             */
/*   Updated: 2022/05/20 14:12:49 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

int	can_move(char **map, t_vector2D pos, t_vector2D size)
{
	if (is_obstacle(map, pos, 0, size) && is_obstacle(map, pos, 1, size)
		&& is_obstacle(map, pos, 2, size) && is_obstacle(map, pos, 3, size))
		return (0);
	return (1);
}

static int	random_move(t_vars *vars, t_vector2D pos)
{
	int	rando;
	int	max_try;

	(void)vars;
	max_try = 5;
	if (!can_move(vars->map, pos, vars->size))
		return (-1);
	rando = rand() % 4;
	while (is_obstacle(vars->map, pos, rando, vars->size) && max_try-- > 0)
		rando = rand() % 4;
	return (rando);
}

static void	choose_guard_pos(t_vars *vars, t_lst_guard **li,
	t_vector2D new_pos, int dir)
{
	vars->map[(*li)->guard.pos.y][(*li)->guard.pos.x] = '0';
	if (vars->save[(*li)->guard.pos.y][(*li)->guard.pos.x] != 'G')
		vars->map[(*li)->guard.pos.y][(*li)->guard.pos.x]
			= vars->save[(*li)->guard.pos.y][(*li)->guard.pos.x];
	vars->map[new_pos.y][new_pos.x] = 'G';
	(*li)->guard.pos = new_pos;
	(*li)->guard.direction = dir;
}

static void	move_guard(t_vars *vars, t_lst_guard **li)
{
	int	choice;

	choice = random_move(vars, (*li)->guard.pos);
	if (choice == TOP && !is_obstacle(vars->map, (*li)->guard.pos,
			TOP, vars->size))
		choose_guard_pos(vars, li, (t_vector2D){(*li)->guard.pos.x,
			(*li)->guard.pos.y - 1}, NORTHWEST);
	if (choice == BOTTOM && !is_obstacle(vars->map, (*li)->guard.pos,
			BOTTOM, vars->size))
		choose_guard_pos(vars, li, (t_vector2D){(*li)->guard.pos.x,
			(*li)->guard.pos.y + 1}, SOUTHEAST);
	if (choice == LEFT && !is_obstacle(vars->map, (*li)->guard.pos,
			LEFT, vars->size))
		choose_guard_pos(vars, li, (t_vector2D){(*li)->guard.pos.x - 1,
			(*li)->guard.pos.y}, NORTHEAST);
	if (choice == RIGHT && !is_obstacle(vars->map, (*li)->guard.pos,
			RIGHT, vars->size))
		choose_guard_pos(vars, li, (t_vector2D){(*li)->guard.pos.x + 1,
			(*li)->guard.pos.y}, SOUTHWEST);
	if (choice != -1)
		vars->update = 1;
	player_dead(vars, (*li)->guard.pos);
}

void	move_guards(t_vars *vars)
{
	t_vector2D	it;
	t_lst_guard	*tmp;
	int			*checked;

	checked = ft_malloc(sizeof(int)
			* guards_size(vars->li_guards), &vars->alloc);
	ft_intset(checked, guards_size(vars->li_guards), 0);
	it.y = -1;
	while (vars->map[++it.y])
	{
		it.x = 0;
		while (vars->map[it.y][it.x])
		{
			if (vars->map[it.y][it.x] == 'G')
			{
				tmp = guards_find(vars->li_guards, it);
				if (tmp && !checked[tmp->index])
				{
					move_guard(vars, &tmp);
					checked[tmp->index] = 1;
				}
			}
			it.x++;
		}
	}
}
