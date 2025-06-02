/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:53:38 by keteo             #+#    #+#             */
/*   Updated: 2025/04/18 15:53:38 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../Libft/libft.h"

int	extension_checker(char *map)
{
	int	path_len;

	path_len = ft_strlen(map);
	if (!ft_strrchr(map, '.'))
		ft_printf("Error:Invalid file\n");
	else if (ft_strncmp(map + path_len - 3, "ber", 3) == 0)
		return (1);
	return (0);
}
