/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:22:04 by darian            #+#    #+#             */
/*   Updated: 2022/03/05 16:00:04 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	construct_image_blocks(t_construct c, t_vars vars, t_data *map)
{
	if (c.c == '1')
		construct_image(c.buffer, c.start, *map, vars.sprites[2]);
	else if (c.c == 'P')
		construct_image(c.buffer, c.start, *map, vars.sprites[4]);
	else if (c.c == 'C' || c.c == '0')
		construct_image(c.buffer, c.start, *map, vars.sprites[0]);
	else if (c.c == 'E' && vars.items >= vars.total_items)
		construct_image(c.buffer, c.start, *map, vars.sprites[3]);
	else if (c.c == 'E' && vars.items < vars.total_items)
		construct_image(c.buffer, c.start, *map, vars.sprites[6]);
}

void	create_map_block(t_vars vars,
	t_vector2D start, char *buffer, t_data *map)
{
	t_vector2D	it;

	it.y = 0;
	while (it.y < vars.size.y)
	{
		it.x = 0;
		while (it.x < vars.size.x)
		{
			start.x -= vars.sprites[0].width / 2;
			construct_image_blocks((t_construct){vars.save[it.y][it.x],
				buffer, start, it}, vars, map);
			it.x++;
			start.y += vars.sprites[0].height / 4;
		}
		it.y++;
		start.x = (vars.size.x * vars.sprites[0].width / 2)
			+ ((vars.sprites[0].width / 2) * (it.y));
		start.y = vars.sprites[0].height / 2
			+ ((vars.sprites[0].height / 4) * it.y);
	}
}

static void	construct_image_tops(t_construct c, t_vars *vars,
	t_data *map)
{
	if (c.c == '1')
		construct_image(c.buffer, c.start, *map, vars->sprites[1]);
	else if (c.c == 'P')
		construct_image(c.buffer, c.start, *map,
			vars->player.sprite[vars->player.direction]);
	else if (c.c == 'C')
		construct_image(c.buffer, c.start, *map, vars->sprites[5]);
}

static void	create_map_top(t_vars *vars, char *buffer,
	t_data *map, t_vector2D start)
{
	t_vector2D	it;

	it.y = 0;
	while (it.y < vars->size.y)
	{
		it.x = 0;
		while (it.x < vars->size.x)
		{
			start.x -= vars->sprites[1].width / 2;
			construct_image_tops((t_construct){
				vars->map[it.y][it.x], buffer, start, it}, vars, map);
			it.x++;
			start.y += vars->sprites[1].height / 4;
		}
		it.y++;
		start.x = (vars->size.x * vars->sprites[1].width / 2)
			+ ((vars->sprites[1].width / 2) * (it.y));
		start.y = 0 + ((vars->sprites[1].height / 4) * it.y);
	}
}

void	create_map(t_vars *vars)
{
	t_data		map;
	char		*buffer;
	t_vector2D	start;

	start = (t_vector2D){vars->size.x * vars->sprites[0].width / 2,
		vars->sprites[0].height / 2};
	map.img = mlx_new_image(vars->mlx, (vars->size.x + vars->size.y)
			* vars->sprites[0].width, (vars->size.y + vars->size.x)
			* vars->sprites[0].height);
	map.width = (vars->size.x + vars->size.y) * vars->sprites[0].width;
	map.height = (vars->size.y + vars->size.x) * vars->sprites[0].height;
	buffer = mlx_get_data_addr(map.img, &map.bits_per_pixel,
			&map.line_length, &map.endian);
	create_map_block(*vars, start, buffer, &map);
	start = (t_vector2D){vars->size.x * vars->sprites[0].width / 2, 0};
	create_map_top(vars, buffer, &map, start);
	mlx_put_image_to_window(vars->mlx, vars->win, map.img, 0, -21);
	mlx_destroy_image(vars->mlx, map.img);
}
