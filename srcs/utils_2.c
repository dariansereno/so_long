/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:17:09 by dasereno          #+#    #+#             */
/*   Updated: 2022/03/05 16:17:28 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	random_nb(t_vars *vars)
{
	vars->bit = ((vars->seed >> 0) ^ (vars->seed >> 2)
			^ (vars->seed >> 3) ^ (vars->seed >> 5)) & 1;
	return (vars->seed = (vars->seed >> 1) | (vars->bit << 15));
}
