/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:58:58 by keteo             #+#    #+#             */
/*   Updated: 2025/04/09 12:58:58 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./minilibx-linux/mlx.h"

typedef struct s_game{

	int *mlx;
	int *img;
	int *wind;

}	t_game;

typedef struct s_textures{

	char *walls;
	char *player;
	char *space;
	char *collectibles;
	char *exit;
} t_textures;

typedef struct s_line_info{

	char *line;
	char *onedmap;
	char **map;
	int count;
	int	fd;
	int i;
	char *find_nl;

} t_line_info;



int off(int keycode, t_game *mlx);
int x_off(t_game *mlx);
char **read_map(char *filepath);
int extension_checker(char *map);




#endif