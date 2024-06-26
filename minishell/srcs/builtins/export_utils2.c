/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:44:53 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/28 16:55:54 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_array(int strsize, t_environment *temp, char *array)
{
	array = malloc(sizeof(char) * (strsize + 1));
	ft_strlcpy(array, temp->signal, strsize + 1);
	ft_strlcat(array, "=", strsize + 1);
	ft_strlcat(array, temp->content, strsize + 1);
}

char	**ft_env_to_array(t_environment *head)
{
	int				i;
	int				strsize;
	int				lstsize;
	char			**array;
	t_environment	*temp;

	i = 0;
	lstsize = ft_envsize(head);
	array = malloc(sizeof(char *) * (lstsize + 1));
	if (!array)
		return (NULL);
	temp = head;
	while (i < lstsize && temp)
	{
		strsize = ft_strlen(temp->signal) + ft_strlen(temp->content) + 2;
		if (ft_strlen(temp->content) > 0)
			add_array(strsize, temp, array[i]);
		temp = temp->next;
		i++;
	}
	array[i] = NULL;
	return (array);
}

void	export_error_not_valid_id(char *arg, t_info *data)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(ft_remove_quotes_str(arg), 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	data->exit_id = 1;
}

char	*first_num(char *var)
{
	int		x;
	int		y;
	char	*zero;

	x = 0;
	y = 0;
	zero = "";
	if (var[x] >= '0' && var[x] <= '9')
		return (var);
	return (zero);
}

int	export_valid(char *cmd)
{
	char	*non_alnum;
	char	*found;
	char	*var;

	var = ft_before_set(cmd, '=');
	non_alnum = ft_strdup(" !#$%%&\\()*+,-./:;<>@[]^`{|}~");
	found = ft_strpbrk(var, non_alnum);
	found = ft_strjoin(found, first_num(var));
	if (ft_strlen(found) > 0)
		return (0);
	return (1);
}
