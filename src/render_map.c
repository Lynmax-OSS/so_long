/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42.fr>              +#+  +:+       +#+          */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:46:50 by keteo            #+#    #+#              */
/*   Updated: 2025/05/01 16:46:50 by keteo           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 100, y * 100);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if(game->map[y][x] == 1)
				put_image(game, game->wall, x, y);
			else
				put_image(game, game->floor, x, y);
			if (game->map[y][x] == 'P')
				put_image(game, game->player, x, y);
			else if (game->map[y][x] == 'E')
				put_image(game, game->exit, x, y);
			else if (game->map[y][x] == 'C')
			 put_image(game, game->collect, x, y);
			x++;
		}
		y++;
	}
}