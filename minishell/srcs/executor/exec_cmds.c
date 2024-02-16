/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:54:15 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/16 16:36:08 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
1. waitpid(-1, &status, 0): 
	Espera a que un proceso hijo termine. 
		-1 indica que waitpid debe esperar a cualquier hijo.
		&status es un puntero a un entero donde waitpid almacenará el estado de 
			salida del proceso hijo. 
		0 indica que waitpid debe esperar de manera bloqueante hasta que un hijo termine.
	
	Entonces en pid se almacena el ID del proceso hijo

2. WIFSIGNALED(status):
	Devuelve verdadero si el proceso hijo terminó debido a una señal.

3. pid == data->pid:
	Significa que el proceso hijo que ha terminado es el proceso hijo específico 
	que se creó en la iteración actual del bucle exec_cmds. 
	
	En ese caso, se comprueba si el proceso hijo terminó de manera 
	normal (WIFEXITED(status)).
	
	Si es así, se actualiza el estado del proceso padre (data->status) con 
	el estado de salida del proceso hijo (WEXITSTATUS(status)).
*/
static void	wait_childs(t_info *data)
{
    int nbr;
    int pid;
    int status;

    nbr = data->cmd_nbr;
    while (nbr--)
	{
		pid = waitpid(-1, &status, 0);
        if (nbr == 0 && WIFSIGNALED(status))
        {
            status += 128;
            catch_signal(data, status, 0);
        }
		else if (pid == data->pid)
			if (WIFEXITED(status))
				data->status = WEXITSTATUS(status);
	}
	return ;
}

/*
	SIGINT:		CTRL+C
	SIG_IGN:	Ignorar
	PID:		Process ID
*/
int	exec_cmds(t_info *data)
{
	int	i;

	i = -1;
	while (++i < data->cmd_nbr)
	{
		pipe(data->fd);
		signal(SIGINT, SIG_IGN);
		data->pid = fork();
		if (!call_childs(data, i))
			return (parent_process(data));
	}
	wait_childs(data);
	return (0);
}
