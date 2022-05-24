/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:54:07 by darian            #+#    #+#             */
/*   Updated: 2022/04/05 17:03:55 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_neg(int nb)
{
	if (nb < 0)
		return (1);
	return (0);
}

static int	size_nb(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char	*rev_str(char *str)
{
	int		i;
	int		len;
	char	c;

	i = 0;
	len = ft_strlen(str) - 1;
	while (i < len)
	{
		c = str[i];
		str[i] = str[len];
		str[len] = c;
		i++;
		len--;
	}
	return (str);
}

static char	*ft_return(char *str, int n)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = 0;
		return (str);
	}
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		str[2] = '1';
		str[3] = '4';
		str[4] = '7';
		str[5] = '4';
		str[6] = '8';
		str[7] = '3';
		str[8] = '6';
		str[9] = '4';
		str[10] = '8';
		str[11] = 0;
		return (str);
	}
	return (NULL);
}

char	*ft_itoa(int n, t_alloc **alloc)
{
	int		i;
	int		neg;
	char	*str;

	i = 0;
	neg = 0;
	str = ft_malloc(sizeof(char) * (size_nb(n) + is_neg(n) + 1), alloc);
	if (!str)
		return (NULL);
	if (ft_return(str, n) != NULL)
		return (ft_return(str, n));
	if (is_neg(n))
	{
		n *= -1;
		neg = 1;
	}
	while (n != 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		str[i++] = '-';
	str[i] = 0;
	return (rev_str(str));
}
