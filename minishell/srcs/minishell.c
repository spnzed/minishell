/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:02:00 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/30 15:01:07 by aaespino         ###   ########.fr       */
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

t_list	*start_env(char **env)
{
	int		i;
	t_list	*begin;
	t_list	*new;
	t_list	*str;

	if (!env || !*env)
		return (0);
	str = malloc(sizeof(t_list));
	if (!str)
		return(NULL);
	begin = 0;
	i = -1;
	while(env[++i])
	{
		str->content = (readline(env[i]));
		if (!str)
			exit(1);
		new = ft_lstnew(str);
		ft_lstadd_back(&begin, new);
	}
	return (begin);
}

int	main(int argc, char **argv, char **env) 
{
	// (void)argc;
	// (void)argv;
	// (void)env;
	t_info	data;

	data.list_env = start_env(env);
	data.list_path = 0;
	data.list_input = 0;
	data.ret = 0;
	data.tab_var_env = 0;

	if (argc == 3 && !ft_strncmp(argv[1], "-c", ft_strlen(argv[1])))
	{
		no_interactive(argv[2], &data);
		executor(&data);					//Work_in_progress
		free_all(&data, 1);
	}
	else
	{
		while (1)
		{
			signal(SIGINT, signal_handler);
			signal(SIGQUIT, SIG_IGN);
			data.cmd_line = display_term_message(); //prompter();		//TO_DO
			if (!data.cmd_line)
				//ctrl_d(&data);
			executor(&data);				//Work_in_progress
			free_all(&data, 0);
		}
	}
	return (0);
}