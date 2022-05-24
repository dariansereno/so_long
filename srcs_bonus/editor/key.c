/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:21:02 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/20 15:14:02 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

void	destroy_old_data(t_vars *vars)
{
	vars->new_menu = 1;
	vars->mode = MENU;
	mlx_destroy_window(vars->mlx, vars->mini_win);
	vars->mini_win = NULL;
}

void	create_file_map(int k, t_vars *vars)
{
	int		fd;
	char	*buf;
	int		i;

	i = 0;
	if (k == ENTER && vars->editor.index > 2)
	{
		if (vars->editor.name[0])
		{
			buf = concat_ber(vars);
			if (!buf)
				return ;
			fd = open(buf, O_WRONLY | O_TRUNC | O_CREAT, 0644);
			if (!fd)
				return ;
			while (vars->menu.map[i])
			{
				ft_putstr_fd(vars->menu.map[i++], fd);
				ft_putchar_fd('\n', fd);
			}
			close(fd);
		}
		destroy_old_data(vars);
	}
}

void	lock_key(int k, t_vars *vars)
{
	if ((k >= 20 && k <= 176) && k != 92 && k != 96
		&& k != 39 && k != 42 && vars->editor.index < 24)
	{
		vars->editor.name[vars->editor.index++] = k;
		vars->editor.name[vars->editor.index] = 0;
	}
	if (k == RETURN && vars->editor.index > 0)
	{
		vars->editor.index--;
		vars->editor.name[vars->editor.index] = 0;
		mlx_clear_window(vars->mlx, vars->menu.win);
	}
	create_file_map(k, vars);
	vars->update = 1;
}

void	editor_key_confirm(t_vars *vars)
{
	vars->mode = MENU;
	mlx_destroy_window(vars->mlx, vars->mini_win);
	vars->mini_win = NULL;
	vars->new_menu = 1;
	vars->lock = 0;
	vars->ed_pos = (t_vector2D){0, 0};
	vars->editor.index = 0;
	vars->editor.name[0] = 0;
}

int	editor_key(int k, t_vars *vars)
{
	if (k == ESC && !vars->lock)
		editor_key_confirm(vars);
	if (vars->lock)
		lock_key(k, vars);
	if (k == ARROW_UP && vars->ed_pos.y - 1 >= 0 && !vars->lock)
		vars->ed_pos.y -= 1;
	else if (k == ARROW_DOWN && vars->ed_pos.y + 1
		<= vars->menu.size_map - 1 && !vars->lock)
		vars->ed_pos.y += 1;
	else if (k == ARROW_LEFT && vars->ed_pos.x + 1
		<= vars->menu.size_map - 1 && !vars->lock)
		vars->ed_pos.x += 1;
	else if (k == ARROW_RIGHT && vars->ed_pos.x - 1 >= 0 && !vars->lock)
		vars->ed_pos.x -= 1;
	vars->update = 1;
	editor_block_key(k, vars);
	return (0);
}
