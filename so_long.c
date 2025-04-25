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

int main(int ac, char **av)//Map file path should be theonly arguement needed
{
	if (ac == 2)
	{
		checkfile_extention (needs path to file)
		get map (needs path to file to read)
		validate map (result form get map comes here)
		get sprites( path to xpm files)
		render map( displays sprites based on map)
		(we need to loop this)handle inputs()
		(same with this)game loops until level cleared
		exit game(has to detect that the player has unlocked exit picked up collectibles and exited the map)
	}
}