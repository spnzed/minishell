/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils3.c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:44:53 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/04 16:11:11 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	list_exp_add(char *cmd, t_info *data)
{
	t_environment	*tmp;

	tmp = NULL;
	tmp = ft_envnew(cmd);
	tmp->signal = ft_before_set(cmd, '=');
	tmp->content = ft_after_set(cmd, '=');
	tmp->full_line = ft_strdup(cmd);
	if (!tmp)
	{
		ft_envclear(&data->list_exp, free);
		return ;
	}
	if (!data->list_exp)
		data->list_exp = tmp;
	else
		ft_envadd_back(&data->list_exp, tmp);
}

void	export_and_grep(t_environment *temp, char **split_cmd, int x)
{
	if (((x + 1) == 1) && (ft_arrlen(split_cmd) == 1))
	{
		while (temp)
		{
			printf("declare -x %s", temp->signal);
			if (temp->content != NULL)
				printf("=\"%s\"\n", temp->content);
			else
				printf("\n");
			temp = temp->next;
		}
	}
}