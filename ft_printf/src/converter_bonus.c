/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:47:29 by darian            #+#    #+#             */
/*   Updated: 2021/12/07 23:22:19 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	str_islower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			return (0);
		i++;
	}
	return (1);
}

unsigned int	base_to_dec(char *nb, char *base)
{
	int				i;
	unsigned int	pow;
	unsigned int	res;
	unsigned int	base_len;
	int				neg;

	base_len = (unsigned int)ft_strlen(base);
	i = ft_strlen(nb) - 1;
	pow = 1;
	res = 0;
	neg = 1;
	while (i >= 0)
	{
		neg_case(nb, &i, &neg);
		if (nb[i] != '-')
		{
			res += val(nb[i], str_islower(base)) * pow;
			pow = pow * base_len;
			i--;
		}
	}
	return (res * neg);
}

char	*dec_to_base(unsigned int nb, char *base)
{
	char			*res;
	int				i;
	unsigned int	base_len;

	base_len = (unsigned int)ft_strlen(base);
	i = 0;
	res = malloc(sizeof(char) * (size_nb_base(nb, base_len) + 2));
	if (!res)
		return (NULL);
	if (nb == 0)
	{
		res[0] = '0';
		res[1] = 0;
		return (res);
	}
	while (nb > 0)
	{
		res[i] = base[nb % base_len];
		nb /= base_len;
		i++;
	}
	res[i] = 0;
	return (str_rev(res));
}

char	*base_converter(char *nb, char *base_from, char *base_to, int *len)
{
	unsigned int	dec;
	char			*res;

	dec = base_to_dec(nb, base_from);
	res = dec_to_base(dec, base_to);
	*len += ft_strlen(res);
	return (res);
}

char	*convert_hexa(char *nb, int *len, int maj)
{
	if (!maj)
		return (base_converter(nb, "0123456789", "0123456789abcdef", len));
	else
		return (base_converter(nb, "0123456789", "0123456789ABCDEF", len));
}
