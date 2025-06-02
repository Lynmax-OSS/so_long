/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:26:35 by keteo             #+#    #+#             */
/*   Updated: 2025/05/25 16:26:35 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	clean_exit(t_game *game)
{
	free_map(game->map);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->collect)
		mlx_destroy_image(game->mlx, game->collect);
	if (game->win)
	{
		mlx_destroy_display(game->mlx);
		mlx_destroy_window(game->mlx, game->win);
	}
	if (game->mlx)
		free(game->mlx);
	exit(0);
	return (0);
}
