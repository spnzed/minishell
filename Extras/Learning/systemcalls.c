/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   systemcalls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:19:23 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/23 19:21:26 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char const *argv[])
{
	printf("Hi there\n");

	char	*argv2[] = {"ls", "-la", NULL};
	execvp(argv2[0], argv2);

	printf("... and done !");
}