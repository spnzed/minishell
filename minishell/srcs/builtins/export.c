/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:44:53 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/14 19:46:34 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(t_info *data)
{
	t_environment *temp;

	temp = data->list_exp;
	if(ft_strcmp(data->cmd_line, "export") == 0)
	{
		while(temp)
		{
			printf("declare -x %s=\"%s\"\n", temp->signal, temp->content);
			temp=temp->next;
		}		
	}
	// else if // only ADIOS // la guardo en export pero no en env
	// else if // only ADIOS= // la guardo en las dos export: ADIOS="" env: ADIOS=
	// else if // ADIOS= + something // la guardo en las dos export: HOLA="si", env: HOLA=si
	else
	{
		// nueva idea
		// si lo meto debajo de la lista env luego se ordenara sola en el export
		
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

// cuando pones export HOLA sin un igual detras se guarda en export y no en env
/*
no se puede poner un numero al principio del nombre de la variable ejemplo:
bash-3.2$ export 3GOL="no"
bash: export: `3GOL=no': not a valid identifier
bash: export: `.gol3=si': not a valid identifier // ni punto
// deduzco que solo letras 
*/
