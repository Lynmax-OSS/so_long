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
# include "./Libft/libft.h"
# include "./minilibx_linux/mlx.h"
# define TILESIZE 100
# define WALL "./textures/walls.xpm"
# define FLOOR "./textures/floor.xpm"
# define PLAYER "./textures/character.xpm"
# define COLLECT "./textures/collectibles.xpm"
# define EXIT "./textures/exit.xpm"

typedef struct s_game{

	void	*mlx;
	void	*win;
	char	**map;
	void	*wall;
	void	*player;
	void	*floor;
	void	*collect;
	void	*exit;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;

}	t_game;

typedef struct s_map_info{

	char *line;
	char *onedmap;
	int count;
	int	fd;
	int i;
	char *find_nl;

} t_map_info;

typedef struct s_elements{

	int p_count;
	int c_count;
	int e_count;

} t_elements;

typedef struct s_map_dim{

	int rows;
	int cols;
	char tile;

} t_map_dim;

typedef struct s_access{

	int	collectibles;
	int	found_exit;

} t_access;

int		count_collectibles(char **map);
int		map_validation(char **map);
int		extension_checker(char *map);
int		input_handler(int keycode, t_game *game);
int 	is_map_playable(char **map);
int		clean_exit(t_game *game);
void	move_player(t_game *game, int dx, int dy);
void	ass_loader(t_game *game);
void	render_map(t_game *game);
void	init_mlx(t_game *game);
void	find_player_position(t_game *game);
void	free_map(char **map);
char	**read_map(char *filepath);

#endif