/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:04:56 by dasereno          #+#    #+#             */
/*   Updated: 2022/04/01 22:31:51 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	call_function_5(va_list args, char const *str, int i, int *nb)
{
	unsigned int	u;
	char			*convert;
	char			*s;

	if (str[i + 1] == 'X')
	{
		u = va_arg(args, unsigned int);
		convert = ft_itoa(u, NULL);
		if (!convert)
			return (0);
		s = convert_hexa(convert, nb, 1);
		if (!s)
			return (0);
		write(1, s, ft_strlen(s));
		free(convert);
		convert = NULL;
		free(s);
		s = NULL;
	}
	return (1);
}

int	call_function_4(va_list args, char const *str, int i, int *nb)
{
	unsigned int	u;
	char			*convert;
	char			*s;

	if (str[i + 1] == 'x')
	{
		u = va_arg(args, unsigned int);
		convert = ft_itoa(u, NULL);
		if (!convert)
			return (0);
		s = convert_hexa(convert, nb, 0);
		if (!s)
			return (0);
		write(1, s, ft_strlen(s));
		free(convert);
		convert = NULL;
		free(s);
		s = NULL;
	}
	return (call_function_5(args, str, i, nb));
}

int	call_function_3(va_list args, char const *str, int i, int *nb)
{
	unsigned int	u;

	if (str[i + 1] == 'u')
	{
		u = va_arg(args, unsigned int);
		ft_putnbr_unsigned(u);
		*nb += size_nb_unsigned(u);
	}
	return (call_function_4(args, str, i, nb));
}

int	call_function_2(va_list args, char const *str, int i, int *nb)
{
	char			*s;
	long long int	lld;

	if (str[i + 1] == '%')
	{
		*nb += 1;
		write(1, "%", 1);
	}
	if (str[i + 1] == 's')
	{
		s = va_arg(args, char *);
		ft_putstr(s);
		*nb += ft_strlen(s);
	}
	else if (str[i + 1] == 'p')
	{
		lld = va_arg(args, long long);
		if (!print_pointer(lld, nb))
			return (0);
	}
	return (call_function_3(args, str, i, nb));
}

int	call_function(va_list args, char const *str, int i, int *nb)
{
	int	d;

	if (str[i + 1] == 'c')
	{
		d = va_arg(args, int);
		write(1, &d, 1);
		*nb += 1;
	}
	else if (str[i + 1] == 'd')
	{
		d = va_arg(args, int);
		ft_putnbr(d);
		*nb += size_nb(d);
	}
	else if (str[i + 1] == 'i')
	{
		d = va_arg(args, int);
		ft_putnbr(d);
		*nb += size_nb(d);
	}
	return (call_function_2(args, str, i, nb));
}
