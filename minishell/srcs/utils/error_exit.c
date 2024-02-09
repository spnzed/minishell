/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_Exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:04:44 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/07 15:21:03 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_first_word(char *str)
{
	int x;
	char *str_copy;
	int len;

	x = 0;
	len = ft_strlen(str);
	str_copy = (char *)malloc(len + 1);
	while (str[x] && (str[x] == ' ' || str[x] == '\t'))
		x++;
	while (str[x] && str[x] != ' ' && str[x] != '\t')
	{
		str_copy[x] = str[x];
		x++;
	}
	str_copy[x] = '\0';
	return(str_copy);
}		

void	ft_error_cmd(t_info *data) // faltara complentar
{
	printf("minishell: %s: command not found\n", ft_first_word(data->cmd_line));
}