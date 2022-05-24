/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:25:08 by darian            #+#    #+#             */
/*   Updated: 2022/05/21 16:51:07 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	handle_player_update(t_vars *vars)
{
	t_vector2D	pos;

	pos = search_char(vars->map, 'P');
	if (pos.x == -1 || pos.y == -1)
		return ;
	if ((*vars).save[pos.y][pos.x] == 'C')
	{
		vars->items++;
		ft_printf("%d/%d items collected!\n", vars->items, vars->total_items);
		(*vars).save[pos.y][pos.x] = '0';
	}
	if ((*vars).save[pos.y][pos.x] == 'E' && vars->items
		== vars->total_items && vars->ending == 0)
	{
		ft_printf("You win in %d moves !!\n", vars->moves);
		close_win(vars);
	}
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

int	updating(t_vars *vars)
{
	if (vars->stopped == 1)
		return (0);
	handle_global_update(vars);
	handle_player_update(vars);
	display_score(vars);
	return (0);
}
