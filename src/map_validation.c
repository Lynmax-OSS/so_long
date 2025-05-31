/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:52:51 by keteo             #+#    #+#             */
/*   Updated: 2025/04/18 15:52:51 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int	map_validation(char **map)
// {
// 	t_line_info line;
// 	int index;
// 	int j;

// 	index = 0;
// 	line.count = 0;
// 	while(map[index])
// 	{
// 		index++;
// 		line.count++;
// 	}
// 	index = 0;
// 	j = 0;
// 	while(map[j])
// 	{
// 		if(map[j] == 0 || map[j + line.count])
// 		{
// 			while(map[j][index] == '1')
// 				index++;
// 		}
// 		else if(map[j] > 0 && map[j] < j + line.count)
// 		j++;
// 	}
// 	return (0);
// }

char **read_map(char *filepath);

static int	is_rectangle(char **map)
{
	int i;
	int row_len;

	i = 0;
	if (!map || !map[0])
		return (0);
	row_len = ft_strlen(map[0]);
	while (map[i]) 
	{
		if(ft_strlen(map[i]) != row_len)
			return (0);
		i++;
	}
	return (1);
}

static int proper_walls(char **map)
{
	t_map_dim coordinate;
	int i;

	i = 0;
	coordinate.rows = 0;
	while (map[coordinate.rows] != NULL)
		coordinate.rows++;
	coordinate.cols = ft_strlen(map[0]);
	while (i < coordinate.cols - 1)
	{
		if (map[0][i] != '1' || map[coordinate.rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while(i < coordinate.rows - 1 && map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][coordinate.cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int element_count(char c, t_elements *count)
{
	if (c == 'P')
		count->p_count++;
	else if (c == 'E')
		count->e_count++;
	else if (c == 'C')
		count->c_count++;
	else if (c != '1' && c != '0')
		return (0);
	return (1);	
}

static int	required_elements(char **map)
{
	t_elements count;
	int i;
	int j;

	i = 0;
	count.p_count = 0;
	count.e_count = 0;
	count.c_count = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (!element_count(map[i][j], &count))
				return (0);
			j++;
		}
		i++;
	}
	if (count.p_count != 1 || count.e_count != 1 || count.c_count < 1)
		return (0);
	return (1);
}

int map_validation(char **map)
{
	if (!is_rectangle(map))
	{
		ft_printf("Error:Not a rectangle\n");
		return (0);
	}
	if (!proper_walls(map))
	{
		ft_printf("Error:Leak in the walls\n");
		return (0);
	}
	if (!required_elements(map))
	{
		ft_printf("Error:Not enough/Unkown character element\n");
		return (0);
	}
	if (!is_map_playable(map))
	{
		ft_printf("Error:Map not playable\n");
		return (0);
	}
	return (1);
}

// int main(void)
// {
// 	char **map;

// 	map = read_map("../maps/map_1.ber");

// 	ft_printf("%d\n", map_validation(map));
// }