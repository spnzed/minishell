/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_exp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:43:48 by pquintan          #+#    #+#             */
/*   Updated: 2024/04/03 11:44:02 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_environment	*order_exp(t_environment *exp)
{
	int				len_list;
	int				index;
	t_environment	*exp_order;

	exp_order = ft_copy_environment(exp);
	len_list = ft_environmentsize(exp_order);
	index = 0;
	return (loop_exp(index, len_list, exp_order));
}
