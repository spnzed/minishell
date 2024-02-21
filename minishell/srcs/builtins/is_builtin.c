/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:49:48 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/21 15:12:23 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_info *data)
{
	int	i;

	i = 0;
	if (ft_strcmp(data->cmd_line, "env") == 0)
		i = 1;
	else if (ft_strcmp(data->cmd_line, "pwd") == 0)
		i = 2;
	else if (check_complex_cmd(data->cmd_line, "echo", 4) == 0 
		|| check_complex_cmd(data->cmd_line, "echo -n", 7) == 0)
		i = 3;
	else if (ft_strcmp(data->cmd_line, "exit") == 0)
		i = 4;
	else if(check_complex_cmd(data->cmd_line, "cd", 2) == 0)
		i = 5;
	else if(check_complex_cmd(data->cmd_line, "export", 6) == 0)
		i = 6;
	else if(check_complex_cmd(data->cmd_line, "unset", 5) == 0)
		i = 7;
	else if (ft_strlen(data->cmd_line) > 0)
    {
        data->exit_id = 127;
        return(i);
    }
    else
        return(11);
	return(i);
}
	// 	error_exit(data); // arreglar error

// mirar en que casos si pones un espacio despues de el comando sigue funcionando
