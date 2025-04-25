/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:31:56 by keteo             #+#    #+#             */
/*   Updated: 2025/04/09 13:31:56 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int off(int keycode, t_game *mlx)
{
	printf("Keycode:%d\n", keycode);
	if(keycode == 65307)
	{	
		mlx_destroy_window(mlx->mlx, mlx->wind);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		exit (0);
	}
	return (0);
}

int x_off(t_game *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->wind);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit (0);
	return (0);
}