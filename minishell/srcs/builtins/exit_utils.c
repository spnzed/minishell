/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:56:08 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/28 16:38:18 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_normin(char **split_cmd)
{
	long long int	tmp_nbr;
	long long int	nbr;

	tmp_nbr = ft_atoll(split_cmd[1]);
	if (tmp_nbr == 0)
		exit (0);
	nbr = (uint8_t)tmp_nbr;
	ft_arrfree(split_cmd, ft_arrlen(split_cmd));
	exit (nbr);
}

int	ft_is_bigger_maxll(char *str)
{
	int	negative;

	negative = 0;
	if (str[0] == '-')
		negative = 1;
	if (ft_strcmp(str, "-9223372036854775808") == 0)
		return (0);
	else if (ft_strcmp(str, "9223372036854775807") == 0)
		return (0);
	else if (ft_strcmp(str, "-9223372036854775808") > 0 && negative == 1)
		return (1);
	else if (ft_strcmp(str, "9223372036854775807") > 0)
		return (1);
	return (0);
}
