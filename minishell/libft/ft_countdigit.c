/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:53:20 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/23 19:29:54 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_countdigit(long num)
{
	int	count;

	count = 1;
	if (num < 0)
		count++;
	while (num >= 10)
	{
		count++;
		num /= 10;
	}
	return (count);
}
