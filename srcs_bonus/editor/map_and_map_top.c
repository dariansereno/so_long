/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_and_map_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:04:21 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/20 15:11:48 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

static void	image_tops_1(t_construct c, t_vars *vars, t_data *map)
{
	if (c.c == '5' && (vars->ed_pos.x != c.pos.x || vars->ed_pos.y != c.pos.y))
		construct_image(c.buffer, c.start, *map, vars->wall_special[3]);
	if (c.c == '6' && (vars->ed_pos.x != c.pos.x || vars->ed_pos.y != c.pos.y))
		construct_image(c.buffer, c.start, *map, vars->wall_special[4]);
	if (c.c == '7' && (vars->ed_pos.x != c.pos.x || vars->ed_pos.y != c.pos.y))
		construct_image(c.buffer, c.start, *map, vars->wall_special[5]);
	if (c.c == '1' && (vars->ed_pos.x == c.pos.x && vars->ed_pos.y == c.pos.y))
		construct_image(c.buffer, c.start, *map, vars->sprites[1]);
	if (c.c == '2' && (vars->ed_pos.x == c.pos.x && vars->ed_pos.y == c.pos.y))
		construct_image(c.buffer, c.start, *map, vars->wall_special_h[0]);
	if (c.c == '3' && (vars->ed_pos.x == c.pos.x && vars->ed_pos.y == c.pos.y))
		construct_image(c.buffer, c.start, *map, vars->wall_special_h[1]);
	if (c.c == '4' && (vars->ed_pos.x == c.pos.x && vars->ed_pos.y == c.pos.y))
		construct_image(c.buffer, c.start, *map, vars->wall_special_h[2]);
	if (c.c == '5' && (vars->ed_pos.x == c.pos.x && vars->ed_pos.y == c.pos.y))
		construct_image(c.buffer, c.start, *map, vars->wall_special_h[3]);
	if (c.c == '6' && (vars->ed_pos.x == c.pos.x && vars->ed_pos.y == c.pos.y))
		construct_image(c.buffer, c.start, *map, vars->wall_special_h[4]);
	if (c.c == '7' && (vars->ed_pos.x == c.pos.x && vars->ed_pos.y == c.pos.y))
		construct_image(c.buffer, c.start, *map, vars->wall_special_h[5]);
	if (c.c == '1' && (vars->ed_pos.x == c.pos.x && vars->ed_pos.y == c.pos.y))
		construct_image(c.buffer, c.start, *map, vars->sprites[8]);
}

static void	construct_image_tops(t_construct c, t_vars *vars,
	t_data *map)
{
	if (c.c == '1' && (vars->ed_pos.x != c.pos.x || vars->ed_pos.y != c.pos.y))
		construct_image(c.buffer, c.start, *map, vars->sprites[1]);
	if (c.c == '2' && (vars->ed_pos.x != c.pos.x || vars->ed_pos.y != c.pos.y))
		construct_image(c.buffer, c.start, *map, vars->wall_special[0]);
	if (c.c == '3' && (vars->ed_pos.x != c.pos.x || vars->ed_pos.y != c.pos.y))
		construct_image(c.buffer, c.start, *map, vars->wall_special[1]);
	if (c.c == '4' && (vars->ed_pos.x != c.pos.x || vars->ed_pos.y != c.pos.y))
		construct_image(c.buffer, c.start, *map, vars->wall_special[2]);
	image_tops_1(c, vars, map);
	if (c.c == 'P')
		construct_image(c.buffer, c.start, *map,
			vars->player.sprite[vars->player.direction]);
	else if (c.c == 'G')
		construct_image(c.buffer, c.start, *map, vars->slime[4][0]);
	else if (c.c == 'C')
		construct_image(c.buffer, c.start, *map, vars->sprites[5]);
}

static void	create_map_top_editor(t_vars *vars, char *buffer,
	t_data *map, t_vector2D start)
{
	t_vector2D	it;

	it.y = 0;
	while (it.y < vars->menu.size_map)
	{
		it.x = 0;
		while (it.x < vars->menu.size_map)
		{
			start.x -= vars->sprites[1].width / 2;
			construct_image_tops((t_construct){
				vars->menu.map[it.y][it.x], buffer, start, it}, vars, map);
			it.x++;
			start.y += vars->sprites[1].height / 4;
		}
		it.y++;
		start.x = (vars->menu.size_map * vars->sprites[1].width / 2)
			+ ((vars->sprites[1].width / 2) * (it.y));
		start.y = 0 + ((vars->sprites[1].height / 4) * it.y);
	}
}

void	create_map_editor(t_vars *vars)
{
	t_data		map;
	char		*buffer;
	t_vector2D	start;

	start = (t_vector2D){vars->menu.size_map * vars->sprites[0].width / 2,
		vars->sprites[0].height / 2};
	map.img = mlx_new_image(vars->mlx, (vars->menu.size_map
				+ vars->menu.size_map) * vars->sprites[0].width,
			(vars->menu.size_map + vars->menu.size_map)
			* vars->sprites[0].height);
	map.width = (vars->menu.size_map + vars->menu.size_map)
		* vars->sprites[0].width;
	map.height = (vars->menu.size_map + vars->menu.size_map)
		* vars->sprites[0].height;
	buffer = mlx_get_data_addr(map.img, &map.bits_per_pixel,
			&map.line_length, &map.endian);
	create_map_block_editor(*vars, start, buffer, &map);
	start = (t_vector2D){vars->menu.size_map * vars->sprites[0].width / 2, 0};
	create_map_top_editor(vars, buffer, &map, start);
	mlx_put_image_to_window(vars->mlx, vars->menu.win, map.img, 0, -21);
	mlx_destroy_image(vars->mlx, map.img);
}
