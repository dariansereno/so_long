/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_llu_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 23:11:49 by dasereno          #+#    #+#             */
/*   Updated: 2021/12/07 23:12:10 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	size_nb_base_llu(unsigned long long nb, int base_len)
{
	int	n;

	n = 0;
	if (nb == 0)
		return (n);
	while (nb > 0)
	{
		nb /= base_len;
		n++;
	}
	return (n);
}

long long	val_llu(char c)
{
	if (c >= '0' && c <= '9')
		return ((long long)c - '0');
	else
		return ((long long)c - 'a' + 10);
}
