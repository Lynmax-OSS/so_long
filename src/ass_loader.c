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

void ass_loader(t_game *game)
{
    int size;

    size = TILESIZE;
    game->wall = mlx_xpm_file_to_image(game->mlx, WALL, &size, &size);
    game->floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &size, &size);
    game->player = mlx_xpm_file_to_image(game->mlx, PLAYER, &size, &size);
    game->collect = mlx_xpm_file_to_image(game->mlx, COLLECT, &size, &size);
    game->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &size, &size);
}