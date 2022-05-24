/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:55:30 by darian            #+#    #+#             */
/*   Updated: 2021/11/23 16:23:48 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str;

	str = (char *)s + ft_strlen(s);
	while (*str != (unsigned char)c)
	{
		if (str == s)
			return (NULL);
		str--;
	}
	return (str);
}
