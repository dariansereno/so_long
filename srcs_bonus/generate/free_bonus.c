/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:26:57 by darian            #+#    #+#             */
/*   Updated: 2022/05/21 15:06:10 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

void	ft_img_clear(t_alloc **lst, void *mlx_ptr)
{
	t_alloc	*tmp;

	if (*lst)
	{
		while (*lst != NULL)
		{
			tmp = (*lst)->next;
			mlx_destroy_image(mlx_ptr, (*lst)->ptr);
			free(*lst);
			*lst = tmp;
		}
	}
}

void	free_game(t_vars *vars)
{
	ft_img_clear(&vars->img_alloc, vars->mlx);
	ft_malloc_clear(&vars->alloc);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mini_win)
		mlx_destroy_window(vars->mlx, vars->mini_win);
	if (vars->menu.win)
		mlx_destroy_window(vars->mlx, vars->menu.win);
	if (vars->mlx)
	{
		mlx_destroy_display((*vars).mlx);
		free((*vars).mlx);
	}
}
