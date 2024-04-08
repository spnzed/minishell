/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:33 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/08 12:28:45 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_settings(t_info *data)
{
	if (tcgetattr(STDIN_FILENO, &data->n_settings) != 0)
	{
		perror("tcgetattr");
		return (1);
	}
	data->o_settings = data->n_settings;
	data->n_settings.c_lflag &= ~ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &data->n_settings) != 0)
	{
		perror("tcsetattr");
		return (1);
	}
	return (0);
}
