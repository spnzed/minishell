/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:49:48 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/20 15:32:38 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char *little_normalizer(char *cmd)
{
	int i;
	int j;
	char *aux;

	i = 0;
	j = 0;
	while (cmd[i] == '\'' || cmd[i] == '\"')
		i++;
	while (cmd[i] && (cmd[i] != '\'' || cmd[i] != '\"'))
		i++;
	aux = malloc(sizeof(char *) * i + 1);
	i = 0;
	while (cmd[i] == '\'' || cmd[i] == '\"')
		i++;
	while (cmd[i] && (cmd[i] != '\'' && cmd[i] != '\"'))
	{
		aux[j] = ft_tolower(cmd[i]);
		j++;
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

int normalize_cmd(t_info *data)
{
	char *aux;

	if ((data->one_cmd[0][0] == '\'' || data->one_cmd[0][0] == '\"')
		|| (data->one_cmd[0][ft_strlen(data->one_cmd[0]) - 1] == '\'' 
		|| data->one_cmd[0][ft_strlen(data->one_cmd[0]) - 1] == '\"'))
	{
 		aux = little_normalizer(data->one_cmd[0]);
		if (ft_strcmp(aux, "echo") == 0)
		{
			if (check_complex_cmd(aux, "echo", 4) == 0 
			|| check_complex_cmd(aux, "echo -n", 7) == 0)
			return(3);
		}
	}
	return (0);
}

int	is_builtin(t_info *data)
{
	char	*aux;
	int		normalized;
	
	if (!data->one_cmd[0])
		return (0);
	normalized = normalize_cmd(data);
	aux = remove_quotes(data->one_cmd[0]);
	if (normalized)
		return (normalized);
	if (ft_strcmp(aux, "env") == 0)
		return(1);
	else if (check_complex_cmd(aux, "pwd", 3) == 0)
		return(2);
	else if (check_complex_cmd(aux, "echo", 4) == 0 
		|| check_complex_cmd(aux, "echo -n", 7) == 0)
		return(3);
	else if (ft_strcmp(aux, "exit") == 0)
		return(4);
	else if(check_complex_cmd(aux, "cd", 2) == 0)
		return(5);
	else if(check_complex_cmd(aux, "export", 6) == 0)
		return(6);
	else if(check_complex_cmd(aux, "unset", 5) == 0)
		return(7);
	else if (ft_strlen(aux) > 0)
    {
        data->exit_id = 127;
        return(0);
    }
	return(0);
}
// mirar en que casos si pones un espacio despues de el comando sigue funcionando
