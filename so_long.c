/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:58:46 by keteo             #+#    #+#             */
/*   Updated: 2025/04/09 12:58:46 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_game game;
	char **map;

	if (ac == 2)
	{
		if(!extension_checker(av[1]))
			return (0);
		map = read_map(av[1]);
		if(!map_validation(map))
			return (0);
		game.map = map;
		init_mlx(&game);
		ass_loader(&game);
		mlx_loop_hook(game.mlx, render_map, &game);
		mlx_loop(game.mlx);
		// get sprites( path to xpm files)
		// render map( displays sprites based on map)
		// (we need to loop this)handle inputs()
		// (same with this)game loops until level cleared
		// exit game(has to detect that the player has unlocked exit picked up collectibles and exited the map)
	}
}