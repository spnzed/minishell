/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:56:08 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/02 17:19:03 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	space_and_num(char *str)
{
	int	x;
	int	flag;

	x = 0;
	flag = 0;
	while (str[x] != '\0')
	{
		while (str[x] == ' ')
			x++;
		if (str[x] >= '0' && str[x] <= '9')
			flag++;
		else if (str[x])
			return (1);
		x++;
	}
	if (flag > 0)
		return (0);
	else
		return (1);
}

static void	ft_print_quotes_arg(char *split_cmd)
{
	char	*new;
	int		n;

	new = ft_remove_quotes_str(split_cmd);
	if (ft_strrchr(new, ' ') && ft_strcmp_len(new, " ", 1))
		new = ft_strtrim(new, " ");
	if (space_and_num(new) == 0)
	{
		n = ft_atoi(new);
		free (new);
		exit (n);
	}
	else
	{
		write(2, "exit\n", 6);
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(new, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		free (new);
		exit (255);
	}
}

static void	ft_print_num_arg(char **split_cmd)
{
	write(2, "exit\n", 6);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("exit: ", 2);
	ft_putstr_fd(split_cmd[1], 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	exit (255);
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
		else if (split_cmd[1][0] == '\'' || split_cmd[1][0] == '\"')
			ft_print_quotes_arg(split_cmd[1]);
		else if (!ft_isnumeric(split_cmd[1]))
			ft_print_num_arg(split_cmd);
		else if (ft_isnumeric(split_cmd[1]))
			ft_normin(split_cmd);
		data->exit_id = 0;
		return (0);
	}
	data->exit_id = 0;
	exit (0);
	return (0);
}
