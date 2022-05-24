/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:54:29 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/20 15:00:34 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes_bonus/so_long_bonus.h"

t_data	*generate_wall(t_vars *vars)
{
	t_data	*sprites;
	int		i;
	char	*name;

	i = 0;
	sprites = ft_malloc(sizeof(t_data) * 6, &vars->alloc);
	if (!sprites)
		return (NULL);
	while (i <= 5)
	{
		name = n3c("./textures/special/wall_", ".xpm", i + 1, &vars->alloc);
		if (!name)
			return (NULL);
		sprites[i] = generate_image(*vars, name, &vars->img_alloc);
		if (!sprites[i].img)
			return (NULL);
		i++;
	}
	return (sprites);
}

t_data	*generate_wall_h(t_vars *vars)
{
	t_data	*sprites;
	int		i;
	char	*name;

	sprites = ft_malloc(sizeof(t_data) * 6, &vars->alloc);
	if (!sprites)
		return (NULL);
	i = 0;
	while (i <= 5)
	{
		name = n3c("./textures/special/wall_", "_h.xpm", i + 1, &vars->alloc);
		if (!name)
			return (NULL);
		sprites[i] = generate_image(*vars, name, &vars->img_alloc);
		if (!sprites[i].img)
			return (NULL);
		i++;
	}
	return (sprites);
}
