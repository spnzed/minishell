/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:44:53 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/08 18:18:55 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(t_info *data) // ordenar?
{
	t_environment *temp;

	temp = data->signals_env;
	if(ft_strcmp(data->cmd_line, "export") == 0)
	{
		while(temp)
		{
			printf("declare -x %s=\"%s\"\n", temp->signal, temp->content);
			temp=temp->next;
		}		
	}
	// else if // only ADIOS
	// else if // only ADIOS=
	// else if // ADIOS= + something
	else
	{
		//NOSEPUEDETONTA//data->list_env->next->content = data->split_line[1];
		// mirar si existe en la lista, sobrescribir
		// crear nuevo nodo abajo de la lista.
		//printf("%s\n",data->split_line[1]);
	}
}
/*
pquintan@cbr12s4 ~ % export      ADIOS =
zsh: bad assignment
*/