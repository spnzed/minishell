/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:39:48 by aaespino          #+#    #+#             */
/*   Updated: 2024/03/22 13:30:32 by pquintan         ###   ########.fr       */
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
			return (NULL);
	}
	route[i] = NULL;
	return (route);
}
