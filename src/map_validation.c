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
#include "../Libft/libft.h"
#include "../../ft_printf/ft_printf.h"

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

int	is_rectangle(char **map)
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

int proper_walls(char **map)
{
	int rows;
	int i;
	int	cols;

	i = 0;
	rows = 0;
	while (map[rows] != NULL)
		rows++;
	cols = ft_strlen(map[0]);
	while (i < cols - 1)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while(i < rows - 1 && map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][cols - 2] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	required_elements(char **map)
{

}

int map_validation(char **map)
{
	if (!is_rectangle(map))
		return (0);
	if (!proper_walls(map))
		return (0);
	if (!required_elements(map))
		return (0);
	return (1);
}

int main(void)
{
	char **map;

	map = read_map("../maps/map_1.ber");

	ft_printf("%d\n", is_rectangle(map));
	ft_printf("%d\n", proper_walls(map));
}