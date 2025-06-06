/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keteo <keteo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:28:20 by keteo             #+#    #+#             */
/*   Updated: 2024/11/19 15:27:15 by keteo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fb)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fb);
		if (n == -2147483648)
		{
			ft_putchar_fd('2', fb);
			n = 147483648;
		}
		else
		{
			n = -n;
		}
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fb);
	}
	ft_putchar_fd((n % 10) + '0', fb);
}
