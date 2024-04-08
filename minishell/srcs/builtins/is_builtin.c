/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:49:48 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/08 17:22:28 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*little_normalizer(char *cmd)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	j = 0;
	aux = NULL;
	while (cmd[i] == '\'' || cmd[i] == '\"')
		i++;
	while (cmd[i] && (cmd[i] != '\'' || cmd[i] != '\"'))
		i++;
	aux = malloc(sizeof(char) * i + 1);
	i = 0;
	while (cmd[i] == '\'' || cmd[i] == '\"')
		i++;
	while (cmd[i] && (cmd[i] != '\'' && cmd[i] != '\"'))
	{
		aux[j] = ft_tolower(cmd[i]);
		j++;
		i++;
	}
	aux[j] = '\0';
	return (aux);
}

int	normalize_cmd(char **cmd)
{
	char	*aux;

	aux = NULL;
	if (cmd[0] != NULL && ft_strlen(cmd[0]) > 0)
	{
		if ((cmd[0][0] == '\'' || cmd[0][0] == '\"')
			|| (cmd[0][ft_strlen(cmd[0]) - 1] == '\''
			|| cmd[0][ft_strlen(cmd[0]) - 1] == '\"'))
		{
			aux = little_normalizer(cmd[0]);
			if (ft_strncmp(aux, "echo", 4) == 0)
			{
				if (check_complex_cmd(aux, "echo") == 0
					|| check_complex_cmd(aux, "echo -n") == 0)
				{
					free(aux);
					return (3);
				}
			}
		}
	}
	free(aux);
	return (0);
}

static int	free_and_return(char *aux, int ret)
{
	free(aux);
	return (ret);
}

static int	what_builtin(char *aux, t_info *data)
{
	if (ft_strcmp(aux, "env") == 0)
		return (1);
	else if (ft_strcmp(aux, "pwd") == 0)
		return (2);
	else if (check_complex_cmd(aux, "echo") == 0
		|| check_complex_cmd(aux, "echo -n") == 0)
		return (3);
	else if (ft_strcmp(aux, "exit") == 0)
		return (4);
	else if (check_complex_cmd(aux, "cd") == 0)
		return (5);
	else if (check_complex_cmd(aux, "export") == 0)
		return (6);
	else if (check_complex_cmd(aux, "unset") == 0)
		return (7);
	else if (ft_strlen(aux) > 0)
	{
		data->exit_id = 127;
		return (0);
	}
	else
		return (0);
}

int	is_builtin(char **cmd, t_info *data)
{
	char	*aux;
	int		normalized;

	if (!cmd[0])
		return (0);
	normalized = normalize_cmd(cmd);
	aux = remove_quotes(cmd[0]);
	if (normalize_cmd(cmd))
		return (normalized);
	return (free_and_return(aux, what_builtin(aux, data)));
}
