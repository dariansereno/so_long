/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:36:31 by darian            #+#    #+#             */
/*   Updated: 2022/05/21 14:00:49 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_error(int err)
{
	if (err == -1)
		ft_putstr_fd("Error\nMalloc error\n", 1);
	if (err == -2)
		ft_putstr_fd("Error\nMap is a directory\n", 1);
	if (err == -3)
		ft_putstr_fd("Error\nInvalid(s) char(s) in map\n", 1);
	if (err == -4)
		ft_putstr_fd("Error\nInvalid number of arguments\n", 1);
	if (err == -5)
		ft_putstr_fd("Error\nInvalid numbers of chars in map\n", 1);
	if (err == -6)
		ft_putstr_fd("Error\nMap is not a rectangle\n", 1);
	if (err == -7)
		ft_putstr_fd("Error\nInvalid walls\n", 1);
	if (err == -8)
		ft_putstr_fd("Error\nInvalid map\n", 1);
	if (err == -9)
		ft_putstr_fd("Error\nInvalid map extension.\n", 1);
	if (err == -10)
		ft_putstr_fd("Error\nMap to big to fit in the screen.\n", 1);
}

int	check_map_name(char *path, t_alloc **alloc)
{
	char	**res;
	int		i;

	res = ft_split(path, '.', alloc);
	i = 0;
	while (res[i])
		i++;
	if (i == 0)
		return (1);
	i -= 1;
	if (ft_strncmp(res[i], "ber", ft_strlen(res[i]))
		|| (!ft_strncmp(res[i], "ber", ft_strlen(res[i])) && i == 0))
		return (1);
	return (0);
}

int	check_error_start(t_vars *vars, char **argv, int argc)
{
	int	error;

	if (argc == 2 && check_map_name(argv[1], &vars->alloc) != 0)
	{
		print_error(-9);
		free_game(vars);
		return (0);
	}
	error = initialise_global(vars, argv);
	if (argc != 2 || error < 0)
	{
		free_game(vars);
		if (argc != 2)
			print_error(-4);
		else
			print_error(error);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars		vars;

	vars.alloc = NULL;
	vars.img_alloc = NULL;
	if (!check_error_start(&vars, argv, argc))
		return (0);
	create_map(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_handling, &vars);
	mlx_loop_hook(vars.mlx, updating, &vars);
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	mlx_loop(vars.mlx);
	free_game(&vars);
}
