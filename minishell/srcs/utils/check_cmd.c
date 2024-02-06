/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:48:19 by pquintan          #+#    #+#             */
/*   Updated: 2024/02/06 11:58:44 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_complex_cmd(char *strbase, char *strcomp, int len)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	while(strbase[x] && x < len)
	{
		if(strbase[x] == strcomp[x])
			y++;
		x++;
	}
	if (x == len)
		return(0);
	else
		return(1);
}