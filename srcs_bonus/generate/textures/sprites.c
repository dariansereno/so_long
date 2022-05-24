/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:56:09 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/20 15:01:47 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes_bonus/so_long_bonus.h"

t_data	*sprites_1(t_vars *vars, t_data *sprites)
{
	sprites[0] = generate_image(*vars,
			"./textures/blocks/ground.xpm", &vars->img_alloc);
	if (!sprites[0].img)
		return (NULL);
	sprites[1] = generate_image(*vars,
			"./textures/blocks/wall.xpm", &vars->img_alloc);
	if (!sprites[1].img)
		return (NULL);
	sprites[2] = generate_image(*vars,
			"./textures/blocks/obs.xpm", &vars->img_alloc);
	if (!sprites[2].img)
		return (NULL);
	sprites[3] = generate_image(*vars,
			"./textures/blocks/endunlock.xpm", &vars->img_alloc);
	if (!sprites[3].img)
		return (NULL);
	sprites[4] = generate_image(*vars,
			"./textures/blocks/start.xpm", &vars->img_alloc);
	if (!sprites[4].img)
		return (NULL);
	sprites[5] = generate_image(*vars,
			"./textures/items/bonus.xpm", &vars->img_alloc);
	if (!sprites[5].img)
		return (NULL);
	return (sprites);
}

t_data	*sprites_2(t_vars *vars, t_data *sprites)
{
	sprites[6] = generate_image(*vars,
			"./textures/blocks/endlock.xpm", &vars->img_alloc);
	if (!sprites[6].img)
		return (NULL);
	sprites[7] = generate_image(*vars,
			"./textures/blocks/ground_h.xpm", &vars->img_alloc);
	if (!sprites[7].img)
		return (NULL);
	sprites[8] = generate_image(*vars,
			"./textures/blocks/wall_h.xpm", &vars->img_alloc);
	if (!sprites[8].img)
		return (NULL);
	sprites[9] = generate_image(*vars,
			"./textures/blocks/start_h.xpm", &vars->img_alloc);
	if (!sprites[9].img)
		return (NULL);
	sprites[10] = generate_image(*vars,
			"./textures/blocks/endunlock_h.xpm", &vars->img_alloc);
	if (!sprites[10].img)
		return (NULL);
	return (sprites);
}

t_data	*generate_sprites(t_vars *vars)
{
	t_data	*sprites;

	sprites = ft_malloc(sizeof(t_data) * 12, &vars->alloc);
	if (!sprites)
		return (NULL);
	sprites = sprites_1(vars, sprites);
	if (!sprites)
		return (NULL);
	sprites = sprites_2(vars, sprites);
	if (!sprites)
		return (NULL);
	return (sprites);
}
