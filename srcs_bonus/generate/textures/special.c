/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:54:59 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/20 15:01:41 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes_bonus/so_long_bonus.h"

t_data	*generate_special(t_vars *vars)
{
	t_data	*sprites;
	int		i;
	char	*name;

	i = 0;
	sprites = ft_malloc(sizeof(t_data) * 26, &vars->alloc);
	if (!sprites)
		return (NULL);
	while (i <= 25)
	{
		name = n3c("./textures/special/", ".xpm", i + 1, &vars->alloc);
		if (!name)
			return (NULL);
		sprites[i] = generate_image(*vars, name, &vars->img_alloc);
		if (!sprites[i].img)
			return (NULL);
		i++;
	}
	return (sprites);
}

int	counter(t_alloc *alloc)
{
	int	i;

	i = 0;
	while (alloc)
	{
		i++;
		alloc = alloc->next;
	}
	return (i);
}

t_data	*generate_special_h(t_vars *vars)
{
	t_data	*sprites;
	int		i;
	char	*name;

	i = 0;
	sprites = ft_malloc(sizeof(t_data) * 26, &vars->alloc);
	if (!sprites)
		return (NULL);
	while (i <= 25)
	{
		name = n3c("./textures/special/", "_h.xpm", i + 1, &vars->alloc);
		if (!name)
			return (NULL);
		sprites[i] = generate_image(*vars, name, &vars->img_alloc);
		if (!sprites[i].img)
			return (NULL);
		i++;
	}
	return (sprites);
}
