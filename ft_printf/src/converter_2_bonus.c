/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 23:16:23 by dasereno          #+#    #+#             */
/*   Updated: 2021/12/07 23:21:30 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	size_nb_base(unsigned int nb, unsigned int base_len)
{
	int	n;

	n = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= base_len;
		n++;
	}
	return (n);
}

unsigned int	val(char c, int lower)
{
	if (c >= '0' && c <= '9')
		return ((unsigned int)c - '0');
	else if (c < '0' && c > '9' && lower)
		return ((unsigned int)c - 'a' + 10);
	else
		return ((unsigned int)c - 'A' + 10);
}

void	neg_case(char *nb, int *i, int *neg)
{
	if (nb[*i] == '-')
	{
		*neg *= -1;
		*i -= 1;
	}
}
