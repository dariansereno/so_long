/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_update_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:52:31 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/21 16:53:31 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

void	handle_clock(t_vars *vars)
{
	if (vars->cl_jump.clock.full > 0.125)
	{
		vars->jump_sp++;
		vars->update_ending = 1;
		if (vars->jump_sp > 7)
			vars->jump_sp = 0;
		reset_clock(&vars->cl_jump);
	}
	if (vars->cl_guards.clock.full > 0.900 && vars->finish == 0
		&& vars->is_guards)
	{
		move_guards(vars);
		reset_clock(&vars->cl_guards);
	}
	if (vars->cl_slime.clock.full > 0.200 && vars->is_guards)
	{
		vars->slime_sp++;
		vars->update = 1;
		if (vars->slime_sp > 3)
			vars->slime_sp = 0;
		reset_clock(&vars->cl_slime);
	}
	if (vars->cl_frozen.clock.full > 0.5)
		vars->frozen = 0;
}
