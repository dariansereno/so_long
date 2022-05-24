/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasereno <dasereno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:05:20 by dasereno          #+#    #+#             */
/*   Updated: 2022/05/20 16:11:49 by dasereno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/so_long_bonus.h"

char	**create_editor_map_base(int size_map, t_alloc *alloc)
{
	char	**map;
	int		i;
	int		j;

	map = ft_malloc(sizeof(char *) * (size_map + 1), &alloc);
	i = 0;
	while (i < size_map)
	{
		j = 0;
		map[i] = ft_malloc(sizeof(char) * (size_map + 1), &alloc);
		while (j < size_map)
		{
			map[i][j] = '0';
			j++;
		}
		map[i][j] = 0;
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**exec_ls(t_alloc **alloc)
{
	int		link[2];
	pid_t	pid;
	char	foo[4096];
	int		read_val;

	pipe(link);
	pid = fork();
	if (pid == 0)
	{
		dup2 (link[1], STDOUT_FILENO);
		close(link[0]);
		close(link[1]);
		mkdir("./user_maps", S_IRUSR | S_IWUSR | S_IXUSR);
		execl("/bin/ls", "ls", "user_maps", "-1", (char *)0);
	}
	else
	{
		close(link[1]);
		read_val = read(link[0], foo, sizeof(foo));
		foo[read_val] = 0;
		return (ft_split(foo, '\n', alloc));
		wait(NULL);
	}
	return (NULL);
}

char	**parse_maps_name(char **maps, t_alloc *alloc)
{
	int		i;
	int		n;
	int		j;
	char	**res;

	i = 0;
	n = 0;
	j = 0;
	while (maps[i])
	{
		if (ft_strnstr(maps[i], "ber", 30))
			n++;
		i++;
	}
	i = 0;
	res = ft_malloc(sizeof(char *) * (n + 1), &alloc);
	while (maps[i])
	{
		if (ft_strnstr(maps[i], "ber", 30))
			res[j++] = ft_strdup(maps[i], alloc);
		i++;
	}
	res[j] = NULL;
	return (res);
}
