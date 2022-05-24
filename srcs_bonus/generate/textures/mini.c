/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:53:53 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/20 15:00:04 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes_bonus/so_long_bonus.h"

t_data	*mini_1(t_vars *vars, t_data *sprites, int *i)
{
	char	*name;

	while (*i <= 25)
	{
		name = n3c("./textures/mini/", "_mini.xpm", *i + 1, &vars->alloc);
		if (!name)
			return (NULL);
		sprites[*i] = generate_image(*vars, name, &vars->img_alloc);
		sprites[*i].ch[0] = 97 + *i;
		sprites[*i].ch[1] = 0;
		if (!sprites[*i].img)
			return (NULL);
		*i += 1;
	}
	sprites[26] = generate_image(*vars,
			"./textures/mini/wall_mini.xpm", &vars->img_alloc);
	if (!sprites[26].img)
		return (NULL);
	sprites[26].ch[0] = '2';
	sprites[26].ch[1] = 0;
	*i += 1;
	return (sprites);
}

t_data	*mini_2(t_vars *vars, int *i, t_data *sprites)
{
	char	*name;

	while (*i <= 32)
	{
		name = n3c("./textures/mini/wall_", "_mini.xpm", *i - 26, &vars->alloc);
		if (!name)
			return (NULL);
		sprites[*i] = generate_image(*vars, name, &vars->img_alloc);
		if (!sprites[*i].img)
			return (NULL);
		sprites[*i].ch[0] = '7' + *i - 27;
		if ('7' + *i - 27 == ':')
			sprites[*i].ch[0] = '0';
		if ('7' + *i - 27 == ';')
			sprites[*i].ch[0] = '-';
		if ('7' + *i - 27 == '<')
			sprites[*i].ch[0] = '+';
		sprites[*i].ch[1] = 0;
		*i += 1;
	}
	sprites[33] = generate_image(*vars,
			"./textures/mini/player_mini.xpm", &vars->img_alloc);
	if (!sprites[33].img)
		return (NULL);
	return (sprites);
}

t_data	*mini_3(t_vars *vars, t_data *sprites)
{
	sprites[33].ch[0] = '3';
	sprites[33].ch[1] = 0;
	sprites[34] = generate_image(*vars,
			"./textures/mini/slime_mini.xpm", &vars->img_alloc);
	if (!sprites[34].img)
		return (NULL);
	sprites[34].ch[0] = '6';
	sprites[34].ch[1] = 0;
	sprites[35] = generate_image(*vars,
			"./textures/mini/popo_mini.xpm", &vars->img_alloc);
	if (!sprites[35].img)
		return (NULL);
	sprites[35].ch[0] = '4';
	sprites[35].ch[1] = 0;
	sprites[36] = generate_image(*vars,
			"./textures/mini/end_mini.xpm", &vars->img_alloc);
	if (!sprites[36].img)
		return (NULL);
	sprites[36].ch[0] = '5';
	sprites[36].ch[1] = 0;
	return (sprites);
}

t_data	*generate_mini(t_vars *vars)
{
	t_data	*sprites;
	int		i;

	sprites = ft_malloc(sizeof(t_data) * 37, &vars->alloc);
	if (!sprites)
		return (NULL);
	i = 0;
	sprites = mini_1(vars, sprites, &i);
	if (!sprites)
		return (NULL);
	sprites = mini_2(vars, &i, sprites);
	if (!sprites)
		return (NULL);
	sprites = mini_3(vars, sprites);
	if (!sprites)
		return (NULL);
	return (sprites);
}
