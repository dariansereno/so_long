/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:36:09 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/20 14:10:01 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

void	display_buttons(t_vars *vars, int a, int b, int c)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->menu.buttons[a].img,
		((10 * 64) / 2) - 64, 100);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->menu.buttons[b].img,
		((10 * 64) / 2) - 64, 150);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->menu.buttons[c].img,
		((10 * 64) / 2) - 64, 200);
}

void	menu_updating(t_vars *vars)
{
	if (vars->menu.selected == 0)
		display_buttons(vars, 1, 2, 4);
	else if (vars->menu.selected == 1)
		display_buttons(vars, 0, 3, 4);
	else
		display_buttons(vars, 0, 2, 5);
}

void	display_string_menu_maps(t_vars *vars, int i, int col, int n)
{
	if (vars->select_m == i)
		mlx_string_put(vars->mlx, vars->win, 10 * 64 / 2 - (col * 80),
			20 + n * 20, create_trgb(0, 255, 0, 255),
			del_ber(vars->user_maps[i], vars->alloc));
	else
		mlx_string_put(vars->mlx, vars->win, 10 * 64 / 2 - (col * 80),
			20 + n * 20, create_trgb(0, 255, 255, 255),
			del_ber(vars->user_maps[i], vars->alloc));
}

void	menu_maps_updating(t_vars *vars)
{
	int	i;
	int	len;
	int	col;
	int	n;

	n = 0;
	col = 0;
	i = 0;
	len = 0;
	while (vars->user_maps[len])
		len++;
	col = len / 15;
	while (vars->user_maps[i])
	{
		display_string_menu_maps(vars, i, col, n);
		i++;
		n++;
		if (i % 15 == 0 && i != 0)
		{
			col--;
			n = 0;
		}
	}
}
