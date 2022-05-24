/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:04:37 by darian            #+#    #+#             */
/*   Updated: 2022/03/05 15:51:12 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

t_clock	clock_start(void)
{
	t_clock	clock;

	clock.clock.sec = 0;
	clock.clock.ms = 0;
	gettimeofday(&clock.start, NULL);
	gettimeofday(&clock.time, NULL);
	clock.fl_time = (((double)(clock.time.tv_usec / 1000))
			/ 1000.0) + (double)clock.time.tv_sec;
	clock.fl_start = (((double)(clock.start.tv_usec / 1000))
			/ 1000.0) + (double)clock.start.tv_sec;
	return (clock);
}

void	get_clock(t_clock *clock)
{
	gettimeofday(&clock->time, NULL);
	clock->fl_time = (((double)(clock->time.tv_usec / 1000))
			/ 1000.0) + (double)clock->time.tv_sec;
	clock->clock.sec = clock->time.tv_sec - clock->start.tv_sec;
	clock->clock.ms = clock->time.tv_usec / 10000;
	clock->clock.full = clock->fl_time - clock->fl_start;
}

void	reset_clock(t_clock	*clock)
{
	gettimeofday(&clock->time, NULL);
	gettimeofday(&clock->start, NULL);
	clock->fl_time = (((double)(clock->time.tv_usec / 1000))
			/ 1000.0) + (double)clock->time.tv_sec;
	clock->fl_start = (((double)(clock->start.tv_usec / 1000))
			/ 1000.0) + (double)clock->start.tv_sec;
	clock->clock.ms = 0;
	clock->clock.sec = 0;
	clock->clock.full = 0.0;
	clock->time.tv_usec = 0;
}
