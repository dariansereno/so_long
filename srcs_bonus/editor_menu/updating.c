/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:30:42 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/20 15:05:00 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

void	editor_menu_updating(t_vars *vars)
{
	char	*ito;

	ito = ft_itoa(vars->menu.size_map, &vars->alloc);
	mlx_string_put(vars->mlx, vars->win, 10 * 64 / 2 - 190, 175,
		create_trgb(0, 255, 255, 255),
		"Enter the size of the map (max 40).ARROW UP to see saved maps.");
	mlx_string_put(vars->mlx, vars->win, 10 * 64 / 2 - 25, 215,
		create_trgb(0, 255, 255, 255), ito);
}
