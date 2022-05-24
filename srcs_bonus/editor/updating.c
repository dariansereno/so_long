/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:29:52 by dasereno          #+#    #+#             */
/*   Updated: 2022/04/08 15:34:18 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

void	editor_updating(t_vars *vars)
{
	if (vars->update == 1)
	{
		create_map_editor(vars);
		if (vars->lock == 1)
		{
			if (vars->editor.name[0])
				mlx_string_put(vars->mlx, vars->menu.win, vars->menu.size_map
					* (64 / 2) / 2, vars->menu.size_map * (64 / 2) + 50,
					create_trgb(0, 255, 255, 255), vars->editor.name);
		}
		vars->update = 0;
	}
	return ;
}
