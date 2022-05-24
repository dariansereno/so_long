/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:35:18 by dasereno          #+#    #+#             */
/*   Updated: 2022/04/08 17:47:03 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

void	mini_editor_menu(t_vars *vars)
{
	t_vector2D	it;
	int			n;

	it = (t_vector2D){0, 0};
	n = 0;
	while (it.y < 10)
	{
		it.x = 0;
		while (it.x < 4)
		{
			if (n == 37)
				return ;
			mlx_put_image_to_window(vars->mlx, vars->mini_win,
				vars->mini[n].img, (it.x * 30) + 5, (it.y * 40) + 5);
			mlx_string_put(vars->mlx, vars->mini_win, (it.x * 30) + 5,
				(it.y * 40) + 30, create_trgb(0, 255, 255, 255),
				vars->mini[n].ch);
			n++;
			it.x++;
		}
		it.y++;
	}
}
