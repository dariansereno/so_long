/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:15:14 by darian            #+#    #+#             */
/*   Updated: 2022/05/21 13:43:00 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf_body(char *str, int *i, va_list args, int *nb)
{
	if (str[*i] == '%' && is_type(str[*i + 1]))
	{
		if (!call_function(args, str, *i, nb))
			return (0);
		*i += 1;
	}
	else if (str[*i] == '%' && str[*i + 1] != 0
		&& is_flag(str, *i))
	{
		if (!call_flags_functions(args, str[*i + 1],
				str[*i + is_flag(str, *i) + 1], nb))
			return (0);
		*i += is_flag(str, *i) + 1;
	}
	else
	{
		write(1, &str[*i], 1);
		*nb += 1;
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	va_start(args, str);
	while (str[i])
	{
		if (!ft_printf_body((char *)str, &i, args, &nb))
			return (0);
		i++;
	}
	return (nb);
}
