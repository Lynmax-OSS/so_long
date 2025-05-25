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
# include "./mlx/mlx.h"
# define TILESIZE 100
# define WALL "../textures/walls.xpm"
# define FLOOR "../textures/floor.xpm"
# define PLAYER "../textures/player.xpm"
# define COLLECT "../textures/collectibles.xpm"
# define EXIT "../textures/exit.xpm"

typedef struct s_game{

	void *mlx;
	void *win;
	char **map;
	void *wall;
	void *player;
	void *floor;
	void *collect;
	void *exit;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;

}	t_game;


typedef struct s_map_info{

	char *line;
	char *onedmap;
	int count;
	int	fd;
	int i;
	char *find_nl;

} t_map_info;

typedef struct s_ginfo{

	int p_count;
	int c_count;
	int e_count;

} t_ginfo;

typedef struct s_ma_info{

	int rows;
	int cols;
	char tile;

} t_ma_info;



int off(int keycode, t_game *mlx);
int x_off(t_game *mlx);
char **read_map(char *filepath);
int extension_checker(char *map);
void ass_loader(t_game *game);
int map_validation(char **map);
void	render_map(t_game *game);
void	init_mlx(t_game *game);



#endif