/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 23:30:59 by darian            #+#    #+#             */
/*   Updated: 2022/04/05 17:03:04 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long_bonus.h"

void	print_map(char	**map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putstr_fd(map[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

t_vector2D	search_char(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return ((t_vector2D){j, i});
			j++;
		}
		i++;
	}
	return ((t_vector2D){-1, -1});
}

char	*ft_str_add(char *str, int n, char c, t_alloc *alloc)
{
	int		i;
	char	*new;
	int		len;

	len = ft_strlen(str);
	i = 0;
	new = ft_malloc(sizeof(char) * (ft_strlen(str) + n + 1), &alloc);
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	while (i < len + n)
	{
		new[i] = c;
		i++;
	}
	new[i] = 0;
	return (new);
}

char	*read_file(int fd, t_alloc **alloc)
{
	int		read_val;
	char	*str;
	char	*tmp;
	char	buff[1084];

	str = NULL;
	read_val = 1;
	if (fd < 1)
		return (NULL);
	if (read(fd, 0, 0) == -1)
		return (NULL);
	while (read_val)
	{
		read_val = read(fd, buff, 1084);
		buff[read_val] = 0;
		tmp = str;
		str = ft_strjoin(tmp, buff, alloc);
	}
	if (str[0] == 0)
		return (NULL);
	return (str);
}

int	random_seed(int max, int fd)
{
	int		c;
	char	buff[1];
	int		read_val;

	read_val = read(fd, buff, 1);
	if (read_val < 1)
		return (5);
	c = buff[0];
	while (c >= (UCHAR_MAX + 1) / max * max)
	{
	}
	if (c < 0)
		c *= -1;
	return (c % max);
}
