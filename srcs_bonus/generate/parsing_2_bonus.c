/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:55:13 by darian            #+#    #+#             */
/*   Updated: 2022/03/10 16:22:40 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

int	count_players(char	**map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

char	**several_start_selecting(char **map, int p)
{
	int	rando;
	int	i;
	int	j;
	int	count;

	rando = rand() % p;
	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (count != rando && map[i][j] == 'P')
			{
				count++;
				map[i][j] = '0';
			}
			if (map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	return (map);
}

int	check_size(t_vector2D it, t_vector2D size, char **map, int *err)
{
	if (it.y == 0 || it.y == size.y - 1)
	{
		if (map[it.y][it.x] < '1' || map[it.y][it.x] > '7')
		{
			*err = -7;
			return (0);
		}
	}
	if (it.x == 0 || it.x == size.x - 1)
	{
		if (map[it.y][it.x] < '1' || map[it.y][it.x] > '7')
		{
			*err = -7;
			return (0);
		}
	}
	return (1);
}
