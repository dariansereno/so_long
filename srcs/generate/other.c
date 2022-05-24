/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:15:19 by darian            #+#    #+#             */
/*   Updated: 2022/05/20 15:27:56 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	initialise_global_before(t_vars *vars)
{
	vars->jump = NULL;
	vars->map = NULL;
	vars->mlx = NULL;
	vars->save = NULL;
	vars->sprites = NULL;
	vars->win = NULL;
	vars->player.sprite = NULL;
	vars->total_items = 0;
	vars->ending = 0;
	vars->moves = 0;
	vars->stopped = 0;
	vars->finish = 0;
	vars->slime_sp = 0;
	vars->jump_sp = 0;
	vars->bit = 0;
	vars->update_ending = 0;
}

static int	initialise_global_4(t_vars *vars)
{
	vars->items = 0;
	vars->player.direction = SOUTHEAST;
	vars->update = 0;
	vars->win = mlx_new_window(vars->mlx, vars->size.y * 64,
			(vars->size.x * 32) + 43, "so_long");
	vars->jump = generate_jump(vars);
	vars->last_pos = search_char(vars->map, 'P');
	vars->p_pos = vars->last_pos;
	vars->sprites = generate_sprites(vars);
	vars->player.sprite = generate_player(vars);
	if (!vars->jump || !vars->win || !vars->sprites
		|| !vars->player.sprite)
		return (-1);
	return (1);
}

static int	initialise_global_3(t_vars *vars)
{
	int	i;

	vars->seed = random_seed(30, vars->random);
	close(vars->random);
	i = 0;
	while (vars->map[i])
	{
		vars->save[i] = ft_strdup(vars->map[i], vars->alloc);
		if (!vars->save[i])
			return (-1);
		i++;
	}
	vars->save[i] = NULL;
	if (vars->size.x > 40 || vars->size.y > 40)
		return (-10);
	return (initialise_global_4(vars));
}

static int	initialise_global_2(t_vars *vars, int fd, char **argv)
{
	fd = open(argv[1], O_RDONLY | O_NOFOLLOW | O_NOCTTY);
	vars->map = read_map(&fd, &vars->size, &vars->total_items, vars);
	if (!vars->map)
	{
		if (fd != -1 && fd < 0)
			return (fd);
		else
			return (-8);
	}
	vars->map = resize_map(vars->map, &vars->size, &vars->alloc);
	if (!vars->map)
	{
		free_game(vars);
		return (-1);
	}
	vars->save = ft_malloc(sizeof(char *) * (vars->size.y + 1), &vars->alloc);
	if (!vars->save)
		return (-1);
	return (initialise_global_3(vars));
}

int	initialise_global(t_vars *vars, char **argv)
{
	int	fd;

	initialise_global_before(vars);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (-1);
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
	return (initialise_global_2(vars, fd, argv));
}
