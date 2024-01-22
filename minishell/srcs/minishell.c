/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:02:00 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/19 15:25:11 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

static void	no_interactive(char *str)
{
	int		i;
	int		size;
	char	*new;

	i = -1;
	size = ft_strlen(str);
	while (++i < size)
	{
		new = ft_strndup(str + i, 1);
		tokenizer(new);				//TO_DO
		ft_strdel(new);
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
	begin = 0;
	i = 0;
	while(env[i])
	{
		str = (readline(env[i]));
		if (!str)
			exit(1);
		new = ft_lstnew(str);
		ft_lstadd_back(&begin, new);
	}
	return (begin);
}

int	main(int argc, char **argv, char **env) 
{
	t_info	data;

	data.list_env = start_env(env);
	data.list_path = 0;
	data.list_input = 0;
	data.ret = 0;
	data.tab_var_env = 0;

	if (argc == 3 && !ft_strcmp(argv[1], "-c"))
	{
		no_interactive(argv[2]);
	}
	else
	{}
	return (data.ret);
}