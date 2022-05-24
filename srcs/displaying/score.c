/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:23:19 by darian            #+#    #+#             */
/*   Updated: 2022/05/20 15:28:59 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	put_string(char	*s1, char *s2, t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 15, 30,
		create_trgb(0, 255, 255, 255), s1);
	mlx_string_put(vars->mlx, vars->win, 15, 45,
		create_trgb(0, 255, 255, 255), s2);
}

static void	display_score_2(char *tmp1, char *tmp2,
	char *itoa_tmp, t_vars *vars)
{
	char	*tmp3;

	tmp3 = tmp2;
	tmp2 = ft_strjoin(tmp3, " items!", &vars->alloc);
	if (!tmp2)
		return ;
	itoa_tmp = ft_itoa(vars->items, &vars->alloc);
	if (!itoa_tmp)
		return ;
	tmp3 = ft_strjoin(itoa_tmp, tmp2, &vars->alloc);
	if (!tmp3)
		return ;
	put_string(tmp3, tmp1, vars);
}

void	display_score(t_vars *vars)
{
	char	*tmp1;
	char	*tmp2;
	char	*itoa_tmp;

	tmp1 = " moves!";
	itoa_tmp = ft_itoa(vars->moves, &vars->alloc);
	if (!itoa_tmp)
		return ;
	tmp1 = ft_strjoin(itoa_tmp, tmp1, &vars->alloc);
	if (!tmp1)
		return ;
	tmp2 = "/";
	itoa_tmp = ft_itoa(vars->total_items, &vars->alloc);
	if (!itoa_tmp)
		return ;
	tmp2 = ft_strjoin(tmp2, itoa_tmp, &vars->alloc);
	if (!tmp2)
		return ;
	display_score_2(tmp1, tmp2, itoa_tmp, vars);
}
