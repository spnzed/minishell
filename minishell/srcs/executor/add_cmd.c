/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:39:48 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/27 13:58:59 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**add_cmd(char **route, char *cmd)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = ft_strdup("/");
	if (!tmp)
		return (NULL);
	tmp = ft_strjoin_clean(tmp, cmd);
	if (!tmp)
		return (NULL);
	while (route[++i])
	{
		route[i] = ft_strjoin_clean(route[i], tmp);
		if (!route[i])
		{
			free(tmp);
			return (NULL);
		}
	}
	route[i] = NULL;
	free(tmp);
	return (route);
}
