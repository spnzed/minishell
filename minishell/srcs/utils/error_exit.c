/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:04:44 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/09 15:02:07 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"	

void	error_exit(t_info *data) // faltara complentar
{
	printf("minishell: %s: command not found\n", ft_first_word(data->cmd_line));
}