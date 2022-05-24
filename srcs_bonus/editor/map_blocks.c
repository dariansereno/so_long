/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_blocks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:11:33 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/20 15:12:57 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

static void	special_block_h(t_construct c, t_vars vars, t_data *map)
{
	if (c.c >= 'a' && c.c <= 'z' && (vars.ed_pos.x == c.pos.x
			&& vars.ed_pos.y == c.pos.y))
		construct_image(c.buffer, c.start,
			*map, vars.special_h[c.c - 97]);
}

static void	special_block(t_construct c, t_vars vars, t_data *map)
{
	if (c.c >= 'a' && c.c <= 'z'
		&& (vars.ed_pos.x != c.pos.x || vars.ed_pos.y != c.pos.y))
		construct_image(c.buffer, c.start, *map, vars.special[c.c - 97]);
	else
		special_block_h(c, vars, map);
}

static void	image_blocks_1(t_construct c, t_vars vars, t_data *map)
{
	if (c.c == '1')
		construct_image(c.buffer, c.start, *map, vars.sprites[2]);
	if (c.c == '2')
		construct_image(c.buffer, c.start, *map, vars.special[23]);
	if (c.c == '3')
		construct_image(c.buffer, c.start, *map, vars.special[25]);
	if (c.c == '4')
		construct_image(c.buffer, c.start, *map, vars.special[22]);
	if (c.c == '5')
		construct_image(c.buffer, c.start, *map, vars.special[14]);
	if (c.c == '6')
		construct_image(c.buffer, c.start, *map, vars.special[11]);
	if (c.c == '7')
		construct_image(c.buffer, c.start, *map, vars.special[4]);
}

static void	construct_image_blocks(t_construct c, t_vars vars, t_data *map)
{
	image_blocks_1(c, vars, map);
	if (c.c == 'P' && (vars.ed_pos.x != c.pos.x || vars.ed_pos.y != c.pos.y))
		construct_image(c.buffer, c.start, *map, vars.sprites[4]);
	else if (c.c == 'P' && (vars.ed_pos.x == c.pos.x
			&& vars.ed_pos.y == c.pos.y))
		construct_image(c.buffer, c.start, *map, vars.sprites[9]);
	else if ((c.c == 'C' || c.c == '0' || c.c == 'G'
			|| (c.c != 'G' && c.c == 'G'))
		&& (vars.ed_pos.x != c.pos.x || vars.ed_pos.y != c.pos.y))
		construct_image(c.buffer, c.start, *map, vars.sprites[0]);
	else if ((c.c == 'C' || c.c == '0' || c.c == 'G'
			|| (c.c != 'G' && c.c == 'G'))
		&& (vars.ed_pos.x == c.pos.x && vars.ed_pos.y == c.pos.y))
		construct_image(c.buffer, c.start, *map, vars.sprites[7]);
	else if (c.c == 'E' && (vars.ed_pos.x != c.pos.x
			|| vars.ed_pos.y != c.pos.y))
		construct_image(c.buffer, c.start, *map, vars.sprites[3]);
	else if (c.c == 'E' && (vars.ed_pos.x == c.pos.x
			&& vars.ed_pos.y == c.pos.y))
		construct_image(c.buffer, c.start, *map, vars.sprites[10]);
	else
		special_block(c, vars, map);
}

void	create_map_block_editor(t_vars vars,
	t_vector2D start, char *buffer, t_data *map)
{
	t_vector2D	it;

	it.y = 0;
	while (it.y < vars.menu.size_map)
	{
		it.x = 0;
		while (it.x < vars.menu.size_map)
		{
			start.x -= vars.sprites[0].width / 2;
			construct_image_blocks((t_construct){vars.menu.map[it.y][it.x],
				buffer, start, it}, vars, map);
			it.x++;
			start.y += vars.sprites[0].height / 4;
		}
		it.y++;
		start.x = (vars.menu.size_map * vars.sprites[0].width / 2)
			+ ((vars.sprites[0].width / 2) * (it.y));
		start.y = vars.sprites[0].height / 2
			+ ((vars.sprites[0].height / 4) * it.y);
	}
}
