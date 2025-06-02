/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:52:53 by keteo             #+#    #+#             */
/*   Updated: 2025/05/25 14:52:53 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	input_handler(int keycode, t_game *game)
{
	if (keycode == 65307)
		clean_exit(game);
	if (keycode == 119)
		move_player(game, 0, -1);
	if (keycode == 115)
		move_player(game, 0, 1);
	if (keycode == 97)
		move_player(game, -1, 0);
	if (keycode == 100)
		move_player(game, 1, 0);
	return (0);
}
