/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:04:36 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/05 16:31:29 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//NULO AL FINAL
static t_list	*start_env(char **env)
{
	int		i;
	t_list	*begin;
	t_list	*new;

	begin = NULL; // Inicializa el inicio de la lista como NULL
	i = -1;
	while (env[++i])
	{
		new = ft_lstnew(env[i]);
		if (!new)
		{
			ft_lstclear(&begin, free); // Libera la lista si falla la asignación de memoria
			return (NULL);
		}
		if (!begin) // Si la lista está vacía, asigna el nuevo nodo como el inicio
			begin = new;
		else // Si la lista no está vacía, agrega el nuevo nodo al final
			ft_lstadd_back(&begin, new);
	}

	return (begin);
}

//NULO AL PRINCIPIO
// static t_list	*start_env(char **env)
// {
// 	int		i;
// 	t_list	*begin;
// 	t_list	*new;

// 	begin = malloc(sizeof(t_list));
// 	if (!begin)
// 		return(NULL);
// 	new = malloc(sizeof(t_list));
// 	if (!new)
// 		return(NULL);
// 	i = -1;
// 	while(env[++i])
// 	{
// 		new = ft_lstnew(env[i]);
// 		ft_lstadd_back(&begin, new);
// 	}
// 	return (begin);
// }

int	init_env(t_info *data, char **env)
{
	data->list_env = start_env(env);
	if (!data->list_env)
		return (1);
	return (0);
}
