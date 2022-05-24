/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:57:32 by dasereno          #+#    #+#             */
/*   Updated: 2021/12/09 17:26:44 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	while_flag_checker(char *str, int i, char flag, int *n)
{
	while (str[i] && str[i] == flag)
	{
		i++;
		*n += 1;
	}
	if (is_type(str[i]))
		return (1);
	return (0);
}

int	is_flag(char *str, int i)
{
	int	ret;

	ret = 0;
	if (while_flag_checker(str, i + 1, ' ', &ret))
		return (ret);
	if (while_flag_checker(str, i + 1, '#', &ret))
		return (ret);
	if (while_flag_checker(str, i + 1, '+', &ret))
		return (ret);
	return (0);
}

int	call_flags_functions(va_list args, char c1, char c2, int *nb)
{
	if (!space_flag(args, c1, c2, nb))
		return (0);
	if (!hashtag_flag(args, c1, c2, nb))
		return (0);
	if (!plus_flag(args, c1, c2, nb))
		return (0);
	return (1);
}
