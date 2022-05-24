/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:18:28 by darian            #+#    #+#             */
/*   Updated: 2022/05/21 14:56:27 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	construct_image(char *buffer,
	t_vector2D start, t_data image2, t_data image)
{
	int	y;
	int	x;
	int	pixel;
	int	og;

	y = 0;
	while (y <= image.height)
	{
		x = 0;
		while (x <= image.width)
		{
			pixel = ((start.y + y) * image2.line_length) + ((start.x + x) * 4);
			og = (y * image.line_length) + (x * 4);
			if (!(image.addr[og] == 0 && image.addr[og + 1] == 0
					&& image.addr[og + 2] == 0))
			{
				buffer[pixel + 0] = image.addr[og + 0];
				buffer[pixel + 1] = image.addr[og + 1];
				buffer[pixel + 2] = image.addr[og + 2];
				buffer[pixel + 3] = image.addr[og + 3];
			}
			x++;
		}
		y++;
	}
}

unsigned int	my_mlx_pixel_get(t_img *img, int x, int y)
{
	char				*dst;

	dst = img->data + (y * img->size_line + x * (img->bpp / 8));
	return (*(unsigned int *)dst);
}

t_data	generate_image(t_vars vars, char *path, t_alloc **alloc)
{
	t_data	sprite;

	sprite.img = mlx_xpm_file_to_image(vars.mlx, path,
			&sprite.width, &sprite.height);
	if (!sprite.img)
		return (sprite);
	sprite.addr = mlx_get_data_addr(sprite.img, &sprite.bits_per_pixel,
			&sprite.line_length, &sprite.endian);
	malloc_add(alloc, malloc_new(sprite.img));
	return (sprite);
}
