/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative_convert_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darian <darian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:36:10 by darian            #+#    #+#             */
/*   Updated: 2022/04/01 22:32:04 by darian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*invert_and_add_one_binary(char *bin)
{
	int	i;

	i = 0;
	while (bin[i])
	{
		if (bin[i] == '1')
			bin[i] = '0';
		else if (bin[i] == '0')
			bin[i] = '1';
		i++;
	}
	i = ft_strlen(bin) - 1;
	while (i >= 0)
	{
		if (bin[i] == '0')
		{
			bin[i] = '1';
			return (bin);
		}
		else if (bin[i] == '1')
			bin[i] = '0';
		i--;
	}
	return (bin);
}

char	*convert_bin_to_8bit_bin(char *bin)
{
	int		i;
	int		j;
	int		total_len;
	char	*result;

	total_len = 8 - (int)ft_strlen(bin);
	i = 0;
	j = 0;
	if (total_len <= 0)
		return (bin);
	else
	{
		result = malloc(sizeof(char) * 9);
		if (!result)
			return (NULL);
	}
	while (i < 8 - (int)ft_strlen(bin))
		result[i++] = '0';
	while (i < 8 && bin[j])
		result[i++] = bin[j++];
	result[i] = 0;
	free(bin);
	bin = NULL;
	return (result);
}

char	*convert_hex_to_8bit_hex(char *hex)
{
	int		i;
	int		j;
	int		total_len;
	char	*result;

	total_len = 8 - (int)ft_strlen(hex);
	i = 0;
	j = 0;
	if (total_len <= 0)
		return (hex);
	else
	{
		result = malloc(sizeof(char) * 9);
		if (!result)
			return (NULL);
	}
	while (i < 8 - (int)ft_strlen(hex))
		result[i++] = 'f';
	while (i < 8 && hex[j])
		result[i++] = hex[j++];
	result[i] = 0;
	free(hex);
	hex = NULL;
	return (result);
}

char	*negative_dec_to_hex_2(char *bin, int *i)
{
	char	*res;

	bin = convert_bin_to_8bit_bin(bin);
	if (!bin)
		return (NULL);
	bin = invert_and_add_one_binary(bin);
	res = base_converter(bin, "01", "0123456789abcdef", i);
	if (!res)
		return (NULL);
	free(bin);
	bin = NULL;
	res = convert_hex_to_8bit_hex(res);
	if (!res)
		return (NULL);
	return (bin);
}

char	*negative_dec_to_hex(long nb)
{
	int		i;
	char	*convert;
	char	*bin;

	i = 0;
	nb *= -1;
	convert = ft_itoa(nb, NULL);
	if (!convert)
		return (NULL);
	bin = base_converter(convert, "0123456789", "01", &i);
	free(convert);
	convert = NULL;
	if (!bin)
		return (NULL);
	return (negative_dec_to_hex_2(bin, &i));
}
