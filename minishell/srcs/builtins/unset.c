/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:44:53 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/16 13:40:54 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_info *data)
{
	//t_list	*temp;
	int			len;
	t_list		*prev;
	t_list		*after;

	//temp = ft_copy_list(data->list_env);
	data->str_trim = ft_strtrim(data->cmd_line, "unset ");
	len = ft_strlen(data->str_trim);
	while(data->list_env)
	{
		if (check_complex_cmd(data->list_env->content, data->str_trim, len) == 0)
		{
			printf("content: %s | trim: %s\n", data->list_env->content, data->str_trim);
			printf("prev: %s\n after: %s\n data->list_env: %s\n", prev->content, after->content, data->list_env->content);
		}
		prev = data->list_env;
		after = data->list_env->next->next;
		data->list_env = data->list_env->next;
		//printf("prev: %s\n after: %s\n data->list_env: %s\n", prev->content, after->content, data->list_env->content);
	}
}
// int	search_on_lists(t_info *data, t_environment *list, char *str)

// voy a hacerlo con el list_exp porque cambiaremos la list_env ?

// solo puede dar un error que es de sintaxis
// sera una funcion que servira tanto para el export como para el unset
// EJEMPLOS:
// bash-3.2$ unset 1fsg
// bash: unset: `1fsg': not a valid identifier
// bash-3.2$ export 764fskalldgg
// bash: export: `764fskalldgg': not a valid identifier

/*typedef struct		s_environment
{
	char					*full_line;
	char					*signal;
	char					*content;
	struct s_environment	*next;
}					t_environment;
*/