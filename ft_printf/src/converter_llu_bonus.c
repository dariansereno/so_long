/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_llu_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:55:15 by darian            #+#    #+#             */
/*   Updated: 2021/12/09 19:52:09 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

unsigned long long	base_to_dec_llu(char *nb, char *base)
{
	int						i;
	unsigned long long		pow;
	unsigned long long		res;
	unsigned long long		base_len;

	base_len = (long long)ft_strlen(base);
	i = ft_strlen(nb) - 1;
	pow = 1;
	res = 0;
	while (i >= 0)
	{
		res += val_llu(nb[i]) * pow;
		pow = pow * base_len;
		i--;
	}
	return (res);
}

char	*str_rev(char *str)
{
	int		start;
	int		end;
	char	c;

	start = 0;
	c = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		c = str[start];
		str[start] = str[end];
		str[end] = c;
		start++;
		end--;
	}
	return (str);
}

char	*dec_to_base_llu(unsigned long long nb, char *base)
{
	char	*res;
	int		i;
	int		base_len;

	base_len = ft_strlen(base);
	i = 0;
	res = malloc(sizeof(char) * (size_nb_base_llu(nb, base_len) + 1));
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

char	*base_converter_llu(char *nb, char *base_from, char *base_to, int *len)
{
	unsigned long long	dec;
	char				*res;

	dec = base_to_dec_llu(nb, base_from);
	res = dec_to_base_llu(dec, base_to);
	*len += ft_strlen(res);
	return (res);
}

int	print_pointer(unsigned long long pointer, int *nb)
{
	char		*res;
	char		*convert;

	write(1, "0x", 2);
	*nb += 2;
	convert = ft_itoa_llu(pointer);
	if (!convert)
		return (0);
	res = base_converter_llu(convert, "0123456789", "0123456789abcdef", nb);
	if (!res)
		return (0);
	write(1, res, ft_strlen(res));
	free(res);
	res = NULL;
	free(convert);
	convert = NULL;
	return (1);
}
