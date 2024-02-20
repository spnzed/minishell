/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:02:00 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/20 17:13:50 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	no_interactive(char *str, t_info *data)
{
	int		i;
	int		size;
	char	*new;

	i = 0;
	size = ft_strlen(str);
	while (i < size)
	{
		new = ft_strndup(&str[i], 1);
		not_interactive_lexer(new, data);
		ft_strdel(&new);
		i++;
	}
	manage_cmd(data);
}

static void launch_mode(int argc, char **argv, t_info *data)
{
	if (argc == 3 && !ft_strncmp(argv[1], "-c", ft_strlen(argv[1])))
		no_interactive(argv[2], data);
	else
	{
		while (1)
		{
			signal(SIGINT, signal_handler);
			signal(SIGQUIT, SIG_IGN);
			data->cmd_line = display_term_message(data);
			if (!data->cmd_line)
				ctrl_d(data);
			manage_cmd(data);
			reset_fd(data);
		}
	}
}

static void	free_ev(t_info *data)
{
	t_environment	*head;
	int				len;

	head = data->signals_env;
	while (head != NULL)
	{
		if (head->full_line)
			free(head->full_line);
		if (head->signal)
			free(head->signal);
		if (head->content)
			free(head->content);
		head = head->next;
	}
	len = ft_lstsize(data->list_env);
	while (len > 0)
		free(&data->list_env[--len]);
	free(data->list_env);
}

int	main(int argc, char **argv, char **env) 
{
	t_info	data;
	lexer(&data, env);
	launch_mode(argc, argv, &data);
	free_ev(&data);
	return (data.status);
}