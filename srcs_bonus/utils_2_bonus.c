/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:57:24 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/21 17:07:18 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

int	random_nb(t_vars *vars)
{
	vars->bit = ((vars->seed >> 0) ^ (vars->seed >> 2)
			^ (vars->seed >> 3) ^ (vars->seed >> 5)) & 1;
	return (vars->seed = (vars->seed >> 1) | (vars->bit << 15));
}

char	**double_str_dup(char **map, t_vector2D size, t_alloc **alloc)
{
	char	**cpy;
	int		i;
	int		j;

	i = 0;
	cpy = ft_malloc(sizeof(char *) * (size.y + 1), alloc);
	while (map[i])
	{
		j = 0;
		cpy[i] = ft_malloc(sizeof(char) * (size.x + 1), alloc);
		while (map[i][j])
		{
			cpy[i][j] = map[i][j];
			j++;
		}
		cpy[i][j] = 0;
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
