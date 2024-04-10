/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_exp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:43:48 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/10 13:42:45 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	order_exp(t_environment *exp)
{
	int				len_list;
	int				index;

	len_list = ft_environmentsize(exp);
	index = 0;
	loop_exp(index, len_list, exp);
}
