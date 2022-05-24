/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:14:09 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/20 15:14:33 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

void	editor_special_key(int k, t_vars *vars)
{
	if (k <= 122 && k >= 97 && !vars->lock)
	{
		vars->menu.map[vars->ed_pos.y][vars->ed_pos.x] = k;
		vars->update = 1;
	}
}

void	editor_block_key_statement(int k, t_vars *vars)
{
	if (k == ONE && !vars->lock)
		vars->menu.map[vars->ed_pos.y][vars->ed_pos.x] = '0';
	if (k == TWO && !vars->lock)
		vars->menu.map[vars->ed_pos.y][vars->ed_pos.x] = '1';
	if (k == THREE && !vars->lock)
		vars->menu.map[vars->ed_pos.y][vars->ed_pos.x] = 'P';
	if (k == FOUR && !vars->lock)
		vars->menu.map[vars->ed_pos.y][vars->ed_pos.x] = 'C';
	if (k == FIVE && !vars->lock)
		vars->menu.map[vars->ed_pos.y][vars->ed_pos.x] = 'E';
	if (k == SIX && !vars->lock)
		vars->menu.map[vars->ed_pos.y][vars->ed_pos.x] = 'G';
	if (k == SEVEN && !vars->lock)
		vars->menu.map[vars->ed_pos.y][vars->ed_pos.x] = '2';
	if (k == EIGHT && !vars->lock)
		vars->menu.map[vars->ed_pos.y][vars->ed_pos.x] = '3';
	if (k == NINE && !vars->lock)
		vars->menu.map[vars->ed_pos.y][vars->ed_pos.x] = '4';
	if (k == ZERO && !vars->lock)
		vars->menu.map[vars->ed_pos.y][vars->ed_pos.x] = '5';
	if (k == MINUS && !vars->lock)
		vars->menu.map[vars->ed_pos.y][vars->ed_pos.x] = '6';
	if (k == PLUS && !vars->lock)
		vars->menu.map[vars->ed_pos.y][vars->ed_pos.x] = '7';
}

void	editor_block_key(int k, t_vars *vars)
{
	editor_block_key_statement(k, vars);
	vars->update = 1;
	if (k == ENTER)
		vars->lock = 1;
	if (k == ESC && vars->lock)
		vars->lock = 0;
	editor_special_key(k, vars);
}

char	*concat_ber(t_vars *vars)
{
	char	*buf;

	vars->editor.name[vars->editor.index++] = '.';
	vars->editor.name[vars->editor.index++] = 'b';
	vars->editor.name[vars->editor.index++] = 'e';
	vars->editor.name[vars->editor.index++] = 'r';
	vars->editor.name[vars->editor.index] = 0;
	buf = ft_strjoin("./user_maps/", vars->editor.name, &vars->alloc);
	return (buf);
}
