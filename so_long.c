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

int main(void)
{
	t_data mlx;

	mlx.mlx = mlx_init();
	mlx.wind = mlx_new_window(mlx.mlx, 1920, 1080, "Gay Bowser");
	mlx_hook(mlx.wind, 2, 1L<<0, off, &mlx);
	mlx_hook(mlx.wind, 17, 1L<<17, x_off, &mlx);
	mlx_loop(mlx.mlx);
}