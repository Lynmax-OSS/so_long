/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:26:40 by keteo             #+#    #+#             */
/*   Updated: 2025/05/25 13:26:40 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_mlx(t_game *game)
{
	t_map_dim	axis;

	axis.rows = 0;
	axis.cols = 0;
	while (game->map[axis.rows] != NULL)
		axis.rows++;
	axis.cols = ft_strlen(game->map[0]);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, axis.cols * 100,
			axis.rows * 100, "Down the Dungeon");
}
