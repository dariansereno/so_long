/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:41:13 by darian            #+#    #+#             */
/*   Updated: 2022/05/21 14:56:02 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_data	*generate_sprites_2(t_vars *vars, t_data *sprites)
{
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
	sprites[6] = generate_image(*vars,
			"./textures/blocks/endlock.xpm", &vars->img_alloc);
	if (!sprites[6].img)
		return (NULL);
	return (sprites);
}

t_data	*generate_sprites(t_vars *vars)
{
	t_data	*sprites;

	sprites = ft_malloc(sizeof(t_data) * 7, &vars->alloc);
	if (!sprites)
		return (NULL);
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
	return (generate_sprites_2(vars, sprites));
}

t_data	*generate_player(t_vars *vars)
{
	t_data	*sprites;

	sprites = ft_malloc(sizeof(t_data) * 4, &vars->alloc);
	if (!sprites)
		return (NULL);
	sprites[0] = generate_image(*vars,
			"./textures/player/player_ne.xpm", &vars->img_alloc);
	if (!sprites[0].img)
		return (NULL);
	sprites[1] = generate_image(*vars,
			"./textures/player/player_nw.xpm", &vars->img_alloc);
	if (!sprites[1].img)
		return (NULL);
	sprites[2] = generate_image(*vars,
			"./textures/player/player_sw.xpm", &vars->img_alloc);
	if (!sprites[2].img)
		return (NULL);
	sprites[3] = generate_image(*vars,
			"./textures/player/player_se.xpm", &vars->img_alloc);
	if (!sprites[3].img)
		return (NULL);
	return (sprites);
}

t_data	*generate_jump_2(t_vars *vars, t_data *sprites)
{
	sprites[3] = generate_image(*vars,
			"./textures/player/player_j3.xpm", &vars->img_alloc);
	if (!sprites[3].img)
		return (NULL);
	sprites[4] = generate_image(*vars,
			"./textures/player/player_j4.xpm", &vars->img_alloc);
	if (!sprites[4].img)
		return (NULL);
	sprites[5] = generate_image(*vars,
			"./textures/player/player_j5.xpm", &vars->img_alloc);
	if (!sprites[5].img)
		return (NULL);
	sprites[6] = generate_image(*vars,
			"./textures/player/player_j6.xpm", &vars->img_alloc);
	if (!sprites[6].img)
		return (NULL);
	sprites[7] = generate_image(*vars,
			"./textures/player/player_j7.xpm", &vars->img_alloc);
	if (!sprites[7].img)
		return (NULL);
	return (sprites);
}

t_data	*generate_jump(t_vars *vars)
{
	t_data	*sprites;

	sprites = ft_malloc(sizeof(t_data) * 8, &vars->alloc);
	if (!sprites)
		return (NULL);
	sprites[0] = generate_image(*vars,
			"./textures/player/player_j0.xpm", &vars->img_alloc);
	if (!sprites[0].img)
		return (NULL);
	sprites[1] = generate_image(*vars,
			"./textures/player/player_j1.xpm", &vars->img_alloc);
	if (!sprites[1].img)
		return (NULL);
	sprites[2] = generate_image(*vars,
			"./textures/player/player_j2.xpm", &vars->img_alloc);
	if (!sprites[2].img)
		return (NULL);
	return (generate_jump_2(vars, sprites));
}
