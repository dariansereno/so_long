/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:15:19 by darian            #+#    #+#             */
/*   Updated: 2022/05/20 15:25:05 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

static int	initialise_global_4(t_vars *vars)
{
	if (vars->size.x > 40 || vars->size.y > 40)
		return (-10);
	vars->jump = generate_jump(vars);
	vars->last_pos = search_char(vars->map, 'P');
	vars->p_pos = vars->last_pos;
	vars->li_guards = generate_guard_list(vars->map, vars->alloc);
	vars->sprites = generate_sprites(vars);
	vars->player.sprite = generate_player(vars);
	vars->slime = generate_slime(vars);
	vars->cl_slime = clock_start();
	vars->cl_jump = clock_start();
	vars->mini = generate_mini(vars);
	vars->mode = 1;
	vars->mini_win = NULL;
	vars->user_maps = NULL;
	vars->menu.win = NULL;
	vars->menu.size_map = 0;
	vars->select_m = 0;
	vars->menu.selected = 0;
	vars->menu.buttons = ft_malloc(sizeof(t_data) * 6, &vars->alloc);
	if (!vars->menu.buttons)
		return (-1);
	return (initialise_global_5(vars));
}

static int	initialise_global_3(t_vars *vars)
{
	int	i;

	vars->save = ft_malloc(sizeof(char *) * (vars->size.y + 1), &vars->alloc);
	if (!vars->save)
		return (-1);
	i = 0;
	while (vars->map[i])
	{
		vars->save[i] = ft_strdup(vars->map[i], vars->alloc);
		if (!vars->save[i])
		{
			return (-1);
		}
		i++;
	}
	vars->save[i] = NULL;
	return (initialise_global_4(vars));
}

static int	initialise_global_2(t_vars *vars, int fd)
{
	if (!vars->map)
	{
		if (fd != -1 && fd < 0)
			return (fd);
		else
			return (-8);
	}
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		return (-1);
	}
	vars->cl_guards = clock_start();
	vars->map = resize_map(vars->map, &vars->size, vars->alloc);
	if (!vars->map)
	{
		return (-1);
	}
	return (initialise_global_3(vars));
}

void	initialise_global_before(t_vars *vars)
{
	vars->jump = NULL;
	vars->li_guards = NULL;
	vars->player.sprite = NULL;
	vars->map = NULL;
	vars->mlx = NULL;
	vars->save = NULL;
	vars->slime = NULL;
	vars->sprites = NULL;
	vars->win = NULL;
	vars->is_guards = 0;
	vars->update_ending = 0;
	vars->items = 0;
	vars->player.direction = SOUTHEAST;
	vars->update = 0;
	vars->stopped = 0;
	vars->bit = 0;
	vars->finish = 0;
	vars->slime_sp = 0;
	vars->lock = 0;
	vars->new_menu = 1;
	vars->menu.map = NULL;
	vars->new_editor_win = 0;
	vars->menu.win = NULL;
	vars->new_game = 0;
}

int	initialise_global(t_vars *vars, char **argv)
{
	int	fd;

	initialise_global_before(vars);
	vars->mini_win = NULL;
	vars->new_mini_win = 0;
	vars->map_select = 0;
	vars->total_items = 0;
	vars->random = open("/dev/random", O_RDONLY);
	if (vars->random < 1)
		vars->random = open("/dev/urandom", O_RDONLY);
	if (vars->random < 1)
		return (-1);
	fd = open(argv[1], O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (-2);
	}
	vars->ending = 0;
	vars->moves = 0;
	vars->new_win = 0;
	vars->jump_sp = 0;
	fd = open(argv[1], O_RDONLY | O_NOFOLLOW | O_NOCTTY);
	vars->map = read_map(&fd, &vars->size, &vars->total_items, vars);
	return (initialise_global_2(vars, fd));
}
