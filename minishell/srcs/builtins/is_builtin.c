/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:49:48 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/06 16:17:01 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* NORMALIZERS */
int	is_builtin(t_info *data)
{
	if (ft_strcmp(data->one_cmd[0], "env") == 0)
		return(1);
	else if (check_complex_cmd(data->one_cmd[0], "pwd", 3) == 0)
		return(2);
	else if (check_complex_cmd(data->one_cmd[0], "echo", 4) == 0 
		|| check_complex_cmd(data->one_cmd[0], "echo -n", 7) == 0)
		return(3);
	else if (ft_strcmp(data->one_cmd[0], "exit") == 0)
		return(4);
	else if(check_complex_cmd(data->one_cmd[0], "cd", 2) == 0)
		return(5);
	else if(check_complex_cmd(data->one_cmd[0], "export", 6) == 0)
		return(6);
	else if(check_complex_cmd(data->one_cmd[0], "unset", 5) == 0)
		return(7);
	else if (ft_strlen(data->one_cmd[0]) > 0)
    {
        data->exit_id = 127;
        return(0);
    }
	return(0);
}
	// 	error_exit(data); // arreglar error

// mirar en que casos si pones un espacio despues de el comando sigue funcionando
