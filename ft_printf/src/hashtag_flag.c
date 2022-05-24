/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtag_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:18:17 by dasereno          #+#    #+#             */
/*   Updated: 2022/04/01 22:31:58 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	hashtag_flag_4(va_list args, char c1, char c2, int *nb)
{
	unsigned int	u;

	if (c1 == '#' && c2 == 'u')
	{
		u = va_arg(args, unsigned int);
		ft_putnbr_unsigned(u);
		*nb += size_nb_unsigned(u);
	}
	return (1);
}

int	hashtag_flag_3(va_list args, char c1, char c2, int *nb)
{
	char			*s;
	long long int	lld;

	if (c1 == '#' && c2 == '%')
	{
		*nb += 1;
		write(1, "%", 1);
	}
	else if (c1 == '#' && c2 == 's')
	{
		s = va_arg(args, char *);
		ft_putstr(s);
		*nb += ft_strlen(s);
	}
	else if (c1 == '#' && c2 == 'p')
	{
		lld = va_arg(args, long long);
		if (!print_pointer(lld, nb))
			return (0);
	}
	return (hashtag_flag_4(args, c1, c2, nb));
}

int	hashtag_flag_2(va_list args, char c1, char c2, int *nb)
{
	int	d;

	if (c1 == '#' && c2 == 'c')
	{
		d = va_arg(args, int);
		write(1, &d, 1);
		*nb += 1;
	}
	else if (c1 == '#' && c2 == 'd')
	{
		d = va_arg(args, int);
		ft_putnbr(d);
		*nb += size_nb(d);
	}
	else if (c1 == '#' && c2 == 'i')
	{
		d = va_arg(args, int);
		ft_putnbr(d);
		*nb += size_nb(d);
	}
	return (hashtag_flag_3(args, c1, c2, nb));
}

void	hexa_if_zero(unsigned int u, int *nb, char c2)
{
	if (u != 0 && c2 == 'x')
	{
		write(1, "0x", 2);
		*nb += 2;
	}
	if (u != 0 && c2 == 'X')
	{
		write(1, "0X", 2);
		*nb += 2;
	}
}

int	hashtag_flag(va_list args, char c1, char c2, int *nb)
{
	unsigned int	u;
	char			*convert;
	char			*s;

	if (c1 == '#' && (c2 == 'x' || c2 == 'X'))
	{
		u = va_arg(args, unsigned int);
		hexa_if_zero(u, nb, c2);
		convert = ft_itoa(u, NULL);
		if (!convert)
			return (0);
		if (c2 == 'X')
			s = convert_hexa(convert, nb, 1);
		else
			s = convert_hexa(convert, nb, 0);
		if (!s)
			return (0);
		write(1, s, ft_strlen(s));
		free(convert);
		convert = NULL;
		free(s);
		s = NULL;
	}
	return (hashtag_flag_2(args, c1, c2, nb));
}
