/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:56:08 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/07 18:09:10 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_print_num_arg(char **split_cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("exit: ", 2);
	ft_putstr_fd(split_cmd[1], 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	exit (255);
}

void	ft_normin(char **split_cmd)
{
	long long int	tmp_nbr;
	long long int	nbr;

	tmp_nbr = ft_atoll(split_cmd[1]);
	if (tmp_nbr == 0)
		exit (0);
	nbr = (uint8_t)tmp_nbr;
	ft_arrfree(split_cmd, ft_arrlen(split_cmd));
	exit(nbr);
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

int	ft_exit(t_info *data, char **split_cmd)
{
	if (split_cmd[1] && ft_is_bigger_maxll(split_cmd[1]) == 1)
		ft_print_num_arg(split_cmd);
	if (ft_arrlen(split_cmd) >= 2)
	{
		if (ft_isnumeric(split_cmd[1]) && ft_arrlen(split_cmd) >= 3)
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			data->exit_id = 1;
			return (0);
		}
		else if (!ft_isnumeric(split_cmd[1]))
			ft_print_num_arg(split_cmd);
		else if (ft_isnumeric(split_cmd[1]))
			ft_normin(split_cmd);
		data->exit_id = 0;
		return(0);
	}
	data->exit_id = 0;
	exit(0);
	return(0);
}

// int	ft_exit(t_info *data)
// {
// 	printf("exit\n");
// 	exit(data->exit_id);
// 	return(0);
// }
