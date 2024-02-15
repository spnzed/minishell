/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:44:53 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/15 19:00:55 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sub_var(t_list *list, char *signal, char *content)
{
	int	len;
	int	x;
	int	i;

	len = ft_strlen(signal) - 1;
	x = 0;
	i = 0;
	while (list)
	{
		//printf("%s, %d, %d\n", signal, len, check_complex_cmd(list->content, signal, len));
		if (check_complex_cmd(list->content, signal, len) == 0) // no sirve
		{
			printf("%s, %s\n", signal, content);
			char *charcontent = (char *)list->content;
			while(charcontent[x] && charcontent[x] != '=')
				x++;
			x++;
			while(charcontent[x])
			{
				charcontent[x] = content[i];
				x++;
				i++;
			}
		}
		list = list->next;
	}
}

static	int	search_on_lists(t_info *data, t_environment *list, char *str)
{
	char	*signal;
	char	*content;

	signal = ft_before_set(str, '=');
	content = ft_after_set(str, '=');
	while (list->next)
	{
		if (ft_strcmp(signal, list->signal) == 0)
		{
			printf("actualizado\n"); // falta actualizar en list_env
			list->content = content;
			sub_var(data->list_env, signal, content); // arreglar // necesito reallocar memoria para poder imprimir otra vez
			return(0);
		}
		list = list->next;
	}
	return(1);
}

void	ft_export(t_info *data)
{
	t_environment	*temp;
	t_list			*new;

	temp = data->list_exp;
	if(ft_strcmp(data->cmd_line, "export") == 0)
	{
		while(temp)
		{
			printf("declare -x %s=\"%s\"\n", temp->signal, temp->content);
			temp=temp->next;
		}		
	}
	// else if // only ADIOS= // la guardo en las dos export: ADIOS="" env: ADIOS=
	// else if // ADIOS= + something // la guardo en las dos export: HOLA="si", env: HOLA=si
	else if (ft_strchr(data->cmd_line, '='))
	{
		data->str_trim = ft_strtrim(data->cmd_line, "export ");
		if (ft_strchr(data->str_trim, '"'))
			data->str_trim = ft_remove_quotes_str(data->str_trim);
		if (search_on_lists(data, data->list_exp, data->str_trim) == 0)
			return ;
		else // creo nuevo
		{
			new = ft_lstnew(data->str_trim);
			if (!new)
			{
				ft_lstclear(&data->list_env, free);
				return ;
			}
			if (!data->list_env)
				data->list_env = new;	
			else
				ft_lstadd_back(&data->list_env, new);
			data->list_exp = start_sig(order_env(data->list_env)); // actualiza export ? SI
		}
	}
	// else // only ADIOS // la guardo en export pero no en env
	else
	{
		//data->list_exp->full_line
		//data->list_exp->signal
		//data->list_exp->content
	}
}
/*
pquintan@cbr12s4 ~ % export      ADIOS =
zsh: bad assignment
*/

// cuando pones export HOLA sin un igual detras se guarda en export y no en env
/*
no se puede poner un numero al principio del nombre de la variable ejemplo:
bash-3.2$ export 3GOL="no"
bash: export: `3GOL=no': not a valid identifier
bash: export: `.gol3=si': not a valid identifier // ni punto
// deduzco que solo letras 
*/
