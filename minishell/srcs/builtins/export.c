/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:44:53 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/16 15:05:38 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_environmentsize(t_environment *env)
{
	int	size;

	size = 0;
	while (env)
	{
		env = env->next;
		size++;
	}
	return (size);
}

static t_environment	*order_exp(t_environment *exp) // t_list env
{
	t_environment *exp_order;
	int len_list;
	int index;
	t_environment *temp;
	t_environment *tempvar;

	exp_order = ft_copy_environment(exp);
	len_list = ft_environmentsize(exp_order);
	index = 0;

	while (index < len_list)
	{
		temp = exp_order;
		while (temp->next != NULL)
		{
			if ((ft_strcmp(temp->signal, temp->next->signal)) > 0)
			{
				tempvar = temp->next;
				temp->next = temp->next->next;
				tempvar->next = exp_order;
				exp_order = tempvar;
			}
			else
				temp = temp->next;
		}
		index++;
	}
	return (exp_order);
}

static void	sub_var(t_list *list, char *signal, char *content)
{
	int		len_signal;
	int		len;
	char	*new_content;

	len_signal = ft_strlen(signal);
	len = ft_strlen(signal) + ft_strlen(content) + 2;
	//printf("base: %s, %s\n", signal, content);
	while(list)
	{
		if (check_complex_cmd(list->content, signal, len_signal) == 0)
		{
			//printf("antes: %s\n", list->content);
			free(list->content);
			new_content = malloc(sizeof len);
			new_content = ft_strjoin(signal, "=");
			//printf("1r join: %s\n", new_content);
			new_content = ft_strjoin(new_content, content);
			//printf("2n join: %s\n", new_content);
			list->content = ft_memcpy(list->content, new_content, len);
			//printf("despues: %s\n", list->content);
		}
		list = list->next;
	}
}

static int	search_on_lists(t_info *data, t_environment *list, char *str)
{
	char	*signal;
	char	*content;

	signal = ft_before_set(str, '=');
	content = ft_after_set(str, '=');
	while (list)
	{
		if (ft_strcmp(signal, list->signal) == 0)
		{
			//printf("actualizado\n"); // falta actualizar en list_env
			list->content = content;
			sub_var(data->list_env, signal, content);
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
	t_environment	*tmp;

	temp = data->list_exp;
	if(ft_strcmp(data->cmd_line, "export") == 0)
	{
		while(temp)
		{
			printf("declare -x %s", temp->signal);
			if (temp->content != NULL)
				printf("=\"%s\"\n", temp->content);
			else
				printf("\n");
			temp = temp->next;
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
			data->list_exp = start_sig(order_env(data->list_env)); // actualiza export ? SI // mirar casos mas largos
		}
	}
	// else // only ADIOS // la guardo en export pero no en env
	else
	{
		data->str_trim = ft_strtrim(data->cmd_line, "export ");
		if (ft_strchr(data->str_trim, '"'))
			data->str_trim = ft_remove_quotes_str(data->str_trim);
		tmp = ft_envnew(data->str_trim);
		tmp->signal = data->str_trim;
		//printf("data->str_trim %s | tmp: %s\n", data->str_trim, tmp->content);
		if (!tmp)
		{
			ft_envclear(&data->list_exp, free);
			return ;
		}
		if (!data->list_exp)
			data->list_exp = tmp;	
		else
			ft_envadd_back(&data->list_exp, tmp);
		data->list_exp = order_exp(data->list_exp);
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

/*
42-Minishell ~ % export ADIOS="vamoooooooooos"
actualizado
antes: ADIOS=vamoooooooADIOS
despues: ADIOS=vamoooooooADIOS
*/