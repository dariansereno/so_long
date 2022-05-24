/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:56:45 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/20 14:59:58 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes_bonus/so_long_bonus.h"

char	*n3c(char *s1, char *s2, int n, t_alloc **alloc)
{
	char	*nb;
	char	*str;
	char	*tmp;

	nb = ft_itoa(n, alloc);
	str = ft_strjoin(s1, nb, alloc);
	tmp = str;
	str = ft_strjoin(tmp, s2, alloc);
	return (str);
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

t_data	*generate_jump(t_vars *vars)
{
	t_data	*sprites;
	int		i;
	char	*name;

	i = 0;
	sprites = ft_malloc(sizeof(t_data) * 8, &vars->alloc);
	if (!sprites)
		return (NULL);
	while (i <= 7)
	{
		name = n3c("./textures/player/player_j", ".xpm", i, &vars->alloc);
		if (!name)
			return (NULL);
		sprites[i] = generate_image(*vars, name, &vars->img_alloc);
		if (!sprites[i].img)
			return (NULL);
		i++;
	}
	return (sprites);
}
