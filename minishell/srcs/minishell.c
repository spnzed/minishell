/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:02:00 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/01 19:02:26 by aaespino         ###   ########.fr       */
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
		lexer(new, data);
		ft_strdel(&new);
		i++;
	}
}

int	main(int argc, char **argv, char **env) 
{
	t_info	data;

	init_data(&data, env);
	// t_info temp = data;
	// while (temp.list_env)
	// {
	// 	printf("%s\n", temp.list_env->content);
	// 	temp.list_env = temp.list_env->next;
	// }
	
	if (argc == 3 && !ft_strncmp(argv[1], "-c", ft_strlen(argv[1])))
	{
		no_interactive(argv[2], &data);
		manage_cmd(&data);
		free_all(&data, 1);
	}
	else
	{
		while (1)
		{
			signal(SIGINT, signal_handler);
			signal(SIGQUIT, SIG_IGN);
			data.cmd_line = display_term_message();
			if (!data.cmd_line)
				ctrl_d(&data);
			manage_cmd(&data);				//Work_in_progress
			//free_all(&data, 0);			// de momento no libera nada
		}
	}
	return (0);
}