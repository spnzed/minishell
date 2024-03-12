/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:12:21 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/12 16:31:29 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_envsize(t_env *env)
{
	int	size;

	size = 0;
	while (env)
	{
		env = env->next;
		size++;
	}
	return (size);
}

static void	swap_env(t_env *tempvar, t_env *temp, t_env *exp_order)
{
	tempvar = temp->next;
	temp->next = temp->next->next;
	tempvar->next = exp_order;
	exp_order = tempvar;
}

t_env	*order_exp(t_env *exp)
{
	t_env	*exp_order;
	int		len_list;
	int		index;
	t_env	*temp;
	t_env	*tempvar;

	exp_order = ft_copy_env(exp);
	len_list = ft_envsize(exp_order);
	index = 0;
	tempvar = NULL;
	while (index < len_list)
	{
		temp = exp_order;
		while (temp->next != NULL)
		{
			if ((ft_strcmp(temp->signal, temp->next->signal)) > 0)
				swap_env(tempvar, temp, exp_order);
			else
				temp = temp->next;
		}
		index++;
	}
	return (exp_order);
}

static char	**concat_array(char **array, int i, t_env *temp, int strsize)
{
	array[i] = malloc(sizeof(char) * (strsize + 1));
	ft_strlcpy(array[i], temp->signal, strsize + 1);
	ft_strlcat(array[i], "=", strsize + 1);
	ft_strlcat(array[i], temp->content, strsize + 1);
	return (array);
}

char	**ft_env_to_array(t_env *head)
{
	int		i;
	int		strsize;
	int		lstsize;
	char	**array;
	t_env	*temp;

	i = 0;
	lstsize = ft_envsize(head);
	array = malloc(sizeof(char *) * (lstsize + 1));
	if (!array)
		return (NULL);
	temp = head;
	while (i < lstsize)
	{
		strsize = ft_strlen(temp->signal) + 1 + ft_strlen(temp->content);
		if (ft_strlen(temp->content) > 0)
			array = concat_array(array, i, temp, strsize);
		temp = temp->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}
