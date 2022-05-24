/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:31:43 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/20 13:33:08 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

char	*del_ber(char *str, t_alloc *alloc)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = ft_malloc(sizeof(char) * ft_strlen(str) + 1, &alloc);
	while (str[i] && ft_strncmp(str + i, ".ber", 4))
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}

void	select_string_put_editor_maps(t_vars *vars, int i, int n, int col)
{
	if (vars->map_select == i)
		mlx_string_put(vars->mlx, vars->win, 10 * 64 / 2 - (col * 80),
			20 + n * 20, create_trgb(0, 255, 0, 255),
			del_ber(vars->user_maps[i], vars->alloc));
	else
		mlx_string_put(vars->mlx, vars->win, 10 * 64 / 2 - (col * 80),
			20 + n * 20, create_trgb(0, 255, 255, 255),
			del_ber(vars->user_maps[i], vars->alloc));
}

void	editor_maps_updating(t_vars *vars)
{
	int	i;
	int	len;
	int	col;
	int	n;

	n = 0;
	col = 0;
	i = 0;
	len = 0;
	while (vars->user_maps[len])
		len++;
	col = len / 15;
	while (vars->user_maps[i])
	{
		select_string_put_editor_maps(vars, i, n, col);
		i++;
		n++;
		if (i % 15 == 0 && i != 0)
		{
			col--;
			n = 0;
		}
	}
}
