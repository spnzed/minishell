/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:44:53 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/14 19:51:52 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_info *data)
{

}
// solo puede dar un error que es de sintaxis
// sera una funcion que servira tanto para el export como para el unset
// EJEMPLOS:
// bash-3.2$ unset 1fsg
// bash: unset: `1fsg': not a valid identifier
// bash-3.2$ export 764fskalldgg
// bash: export: `764fskalldgg': not a valid identifier