/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:27:49 by darian            #+#    #+#             */
/*   Updated: 2021/12/03 21:08:56 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'X'
		|| c == 'i' || c == 'i' || c == 'u' || c == 'x' || c == '%')
		return (1);
	return (0);
}

int	count_args(char const	*str)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && is_type(str[i + 1]))
		{
			i += 1;
			n++;
		}
		i++;
	}
	return (n);
}
