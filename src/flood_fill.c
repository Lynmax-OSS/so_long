/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:39:03 by keteo             #+#    #+#             */
/*   Updated: 2025/05/25 15:39:03 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char **clone_map(char **map)
{
	int i;
	char **clone;

	i = 0;
	while (map[i])
		i++;
	clone = malloc(sizeof(char *) * (i + 1));
	if (!clone)
		return (NULL);
	i = 0;
	while (map[i])
	{
		clone[i] = ft_strdup(map[i]);
		i++;
	}
	clone[i] = NULL;
	return (clone);
}

void free_cloned_map(char **map)
{
	int i;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void flood(char **map, int x, int y, t_access *acc)
{
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
		acc->collectibles++;
	if (map[y][x] == 'E')
	{
		acc->found_exit = 1;
		return ;
	}
	map[y][x] = '1';
	flood(map, x + 1, y, acc);
	flood(map, x - 1, y, acc);
	flood(map, x, y + 1, acc);
	flood(map, x, y - 1, acc);
}

int	find_clone_position(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_map_playable(char **map)
{
	t_access	acc;
	char		**clone;
	int			x;
	int			y;

	acc.collectibles = 0;
	acc.found_exit = 0;
	clone = clone_map(map);
	if (!clone)
		return (0);
	if (!find_clone_position(clone, &x, &y))
	{
		free_cloned_map(clone);
		return (0);
	}
	flood(clone, x, y, &acc);
	free_cloned_map(clone);
	return (acc.found_exit && acc.collectibles >= count_collectibles(map));
}
