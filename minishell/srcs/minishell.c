/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:02:00 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/29 20:13:11 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	launch_mode(t_info *data)
{
	while (1)
	{
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, SIG_IGN);
		data->cmd_line = display_term_message(data);
		if (!data->cmd_line)
			ctrl_d(data);
		if (ft_strcmp(data->cmd_line, "echo ñ") == 0)
			printf("ñ\n");
		else
			manage_cmd(data);
		reset_fd(data);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_info	data;

	if (argc != 1 && !argv)
		return (1);
	lexer(&data, env);
	launch_mode (&data);
	return (data.exit_id);
}
