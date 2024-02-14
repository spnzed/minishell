/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 19:45:05 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/14 20:01:33 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_pipe(char *str, char c)
{
	int		i;
	int		size;
	char	**ret;

	i = -1;
	size = cmd_count(str);
	ret = malloc(sizeof(char *) * (size + 1));
	if (!ret || !str)
		return (NULL);
	while (++i < size)
	{
		while (*str == c)
			str++;
		ret[i] = return_string(str, c);
		if (ret[i] == NULL)
			return (ft_free(ret, i));
		str += ft_strlen(ret[i]);
		i++;
	}
}