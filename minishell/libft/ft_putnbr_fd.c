/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:53:16 by aaespino          #+#    #+#             */
/*   Updated: 2022/02/01 13:56:09 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putchar_fd('-', fd);
			ft_putchar_fd('2', fd);
			n = 147483648;
		}
		else
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
	}
	if (n >= 0)
	{
		if (n / 10 > 0)
		{
			ft_putnbr_fd (n / 10, fd);
		}
		ft_putchar_fd (n % 10 + '0', fd);
	}
}
