/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:25:08 by darian            #+#    #+#             */
/*   Updated: 2022/05/20 13:59:15 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

int	test_key(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		close_win(vars);
	if (keycode == ARROW_UP && vars->menu.selected > 0)
		vars->menu.selected--;
	if (keycode == ARROW_DOWN && vars->menu.selected < 1)
		vars->menu.selected++;
	if (keycode == ENTER)
	{
		if (vars->menu.selected == 0)
			vars->mode = 0;
		else
		{
			vars->mode = 2;
			mlx_clear_window(vars->mlx, vars->win);
		}
	}
	vars->update = 1;
	return (0);
}
