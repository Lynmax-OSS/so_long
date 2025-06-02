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

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		if (ac != 2)
			return (1);
		if (!extension_checker(av[1]))
			return (1);
		game.map = read_map(av[1]);
		if (!map_validation(game.map))
		{
			free_map(game.map);
			return (1);
		}
		init_mlx(&game);
		ass_loader(&game);
		render_map(&game);
		mlx_key_hook(game.win, input_handler, &game);
		mlx_hook(game.win, 17, 0, clean_exit, &game);
		mlx_loop(game.mlx);
		return (0);
	}
}
