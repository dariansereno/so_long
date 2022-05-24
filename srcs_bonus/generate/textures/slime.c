/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:55:38 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/20 14:55:59 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes_bonus/so_long_bonus.h"

int	slime_1(t_vars *vars, t_data **sprites, t_vector2D *it, char sl[5][9])
{
	char	*name;

	while (it->x <= 3)
	{
		name = n3c("./textures/slime/slime_", sl[it->y], it->x, &vars->alloc);
		if (!name)
			return (0);
		sprites[it->y][it->x] = generate_image(*vars, name, &vars->img_alloc);
		if (!sprites[it->y][it->x].img)
			return (0);
		it->x++;
	}
	return (1);
}

t_data	**generate_slime(t_vars *vars)
{
	t_data			**sprites;
	t_vector2D		it;
	static char		sl[5][9] = {"_ne.xpm",
		"_nw.xpm", "_sw.xpm", "_se.xpm", "_face.xpm"};

	it = (t_vector2D){0, -1};
	sprites = ft_malloc(sizeof(t_data) * 5, &vars->alloc);
	if (!sprites)
		return (NULL);
	while (++it.y <= 4)
	{
		it.x = 0;
		sprites[it.y] = ft_malloc(sizeof(t_data) * 4, &vars->alloc);
		if (!sprites[it.y])
			return (NULL);
		while (it.x <= 3)
			if (!slime_1(vars, sprites, &it, sl))
				return (NULL);
	}
	return (sprites);
}
