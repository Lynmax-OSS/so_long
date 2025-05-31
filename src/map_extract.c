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

static int line_count(char *filepath)
{
	t_map_info line;

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

void	trim_newline(char *line)
{
	char	*nl;

	nl = ft_strchr(line, '\n');
	if (nl)
	{
		*nl = '\0';
		if (nl > line && *(nl - 1) == '\r')
			*(nl - 1) = '\0';
	}
}

char **read_map(char *filepath)
{
	t_map_info line;
	t_game game;

	line.i = 0;
	line.count = line_count(filepath);
	game.map = malloc(sizeof(char*) * (line.count + 1));
	if(game.map == NULL)
	{
		free (game.map);
		return (NULL);
	}
	line.fd = open(filepath, O_RDONLY);
	if(line.fd < 0)
		return (NULL);
	while ((line.line = get_next_line(line.fd))) 
	{
		trim_newline(line.line);
		game.map[line.i++] = ft_strdup(line.line);
		free (line.line);
	}
	game.map[line.i] = NULL;
	close(line.fd);
	return (game.map);
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