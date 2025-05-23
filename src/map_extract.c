/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:03:25 by keteo             #+#    #+#             */
/*   Updated: 2025/04/17 11:03:25 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../so_long.h"
#include "../Libft/libft.h"
#include "../../ft_printf/ft_printf.h"

int line_count(char *filepath)
{
	t_line_info line;

	line.count = 0;
	line.fd = open(filepath, O_RDONLY);
	if(line.fd < 0)
		exit(1);
	while ((line.line = get_next_line(line.fd)) != NULL)
	{
		line.count++;
		free(line.line);
	}
	close (line.fd);
	return (line.count);
}

char **read_map(char *filepath)
{
	t_line_info line;

	line.i = 0;
	line.count = line_count(filepath);
	line.map = malloc(sizeof(char*) * (line.count + 1));
	if(line.map == NULL)
	{
		free (line.map);
		return (NULL);
	}
	line.fd = open(filepath, O_RDONLY);
	if(line.fd < 0)
		return (NULL);
	while ((line.line = get_next_line(line.fd))) 
	{
		line.find_nl = ft_strchr(line.line, '\n');
		if(line.find_nl)
		{
			*(line.find_nl) = 0;
			if (line.find_nl > line.line && *(line.find_nl - 1) == '\r')
				*(line.find_nl - 1) = '\0';
		}
		line.map[line.i++] = ft_strdup(line.line);
		free (line.line);
	}
	line.map[line.i] = NULL;
	close(line.fd);
	return (line.map);
}

// int main(void)
// {
// 	char **map;
// 	int i;

// 	i = 0;
// 	map = read_map("../maps/map_1.ber");
	
// 	while (map[i] != NULL)
// 	{
// 		ft_printf("%s\n", map[i]);
// 		i++;
// 	}
// 	free (map);
// }