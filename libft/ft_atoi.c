/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:46:09 by darian            #+#    #+#             */
/*   Updated: 2021/12/04 22:07:24 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int		n;
	long	result;
	int		neg;

	n = 0;
	result = 0;
	neg = 1;
	while (nptr[n] == ' ' || nptr[n] == '\f' || nptr[n] == '\n'
		|| nptr[n] == '\r' || nptr[n] == '\t' || nptr[n] == '\v')
		n++;
	if (nptr[n] == '-' || nptr[n] == '+')
	{
		if (nptr[n] == '-')
			neg *= -1;
		n++;
	}
	while ((nptr[n] >= '0' && nptr[n] <= '9'))
	{
		result = result * 10 + nptr[n] - 48;
		n++;
	}
	return ((int)(result * neg));
}
