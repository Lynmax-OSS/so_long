/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:58:58 by keteo             #+#    #+#             */
/*   Updated: 2025/04/09 12:58:58 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include "./minilibx-linux/mlx.h"

typedef struct s_data{

	int *mlx;
	int *img;
	int *wind;

}	t_data;

int off(int keycode, t_data *mlx);
int x_off(t_data *mlx);



#endif