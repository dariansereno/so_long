/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:40:48 by dasereno          #+#    #+#             */
/*   Updated: 2022/04/01 22:32:32 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	space_flag_4(va_list args, char c1, char c2, int *nb)
{
	long long int	lld;

	if (c1 == ' ' && c2 == 'p')
	{
		lld = va_arg(args, long long);
		if (!print_pointer(lld, nb))
			return (0);
	}
	return (1);
}

int	space_flag_3(va_list args, char c1, char c2, int *nb)
{
	char	*s;
	int		d;

	if (c1 == ' ' && (c2 == 's'))
	{
		s = va_arg(args, char *);
		ft_putstr(s);
		*nb += ft_strlen(s);
	}
	if (c1 == ' ' && (c2 == '%'))
	{
		write(1, "%", 1);
		*nb += 1;
	}
	if (c1 == ' ' && (c2 == 'c'))
	{
		d = va_arg(args, int);
		write(1, &d, 1);
		*nb += 1;
	}
	return (space_flag_4(args, c1, c2, nb));
}

int	space_flag_2(va_list args, char c1, char c2, int *nb)
{
	unsigned int	u;
	char			*convert;
	char			*s;

	if (c1 == ' ' && (c2 == 'x' || c2 == 'X'))
	{
		u = va_arg(args, unsigned int);
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
	return (space_flag_3(args, c1, c2, nb));
}

int	space_flag(va_list args, char c1, char c2, int *nb)
{
	int				d;

	if (c1 == ' ' && (c2 == 'd' || c2 == 'i'))
	{
		d = va_arg(args, int);
		if (d < 0)
		{
			ft_putnbr(d);
			*nb += size_nb(d);
			return (1);
		}
		else
		{
			write(1, " ", 1);
			ft_putnbr(d);
			*nb += 1 + size_nb(d);
			return (1);
		}
	}
	return (space_flag_2(args, c1, c2, nb));
}
