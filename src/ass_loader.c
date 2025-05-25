/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ass_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42.fr>              +#+  +:+       +#+          */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:27:47 by keteo            #+#    #+#              */
/*   Updated: 2025/05/01 21:27:47 by keteo           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ass_loader(t_game *game)
{
	int x;
	int y;
	y = 0;
	while (game->map[y])
		y++;
	game->height = y;
	game->width = ft_strlen(game->map[0]);
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL, &x, &y);
	game->floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &x, &y);
	game->player = mlx_xpm_file_to_image(game->mlx, PLAYER, &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &x, &y);
	game->collect = mlx_xpm_file_to_image(game->mlx, COLLECT, &x, &y);
	game->moves = 0;
	game->collectibles = count_collectibles(game->map);
	find_player_position(game);
}