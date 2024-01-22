/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:25:57 by aaespino          #+#    #+#             */
/*   Updated: 2022/02/05 18:44:02 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	countdigit(int number)
{
	int	count;

	count = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		count++;
	while (number != 0)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

char	*is_min(void)
{
	char	*str;

	str = ft_calloc (12, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

char	*is_negative(int n, char *str)
{
	size_t	i;

	i = countdigit(n);
	str[0] = '-';
	while (i > 0)
	{	
		str[i] = (n % 10) + 48;
		n = (n / 10);
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;

	if (n == -2147483648)
		return (is_min());
	str = ft_calloc(countdigit(n) + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = countdigit(n);
	if (n >= 0)
	{
		while (i > 0)
		{
			i--;
			str[i] = (n % 10) + 48;
			n = (n / 10);
		}
	}
	if (n < 0)
		is_negative (n * -1, str);
	return (str);
}
