/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork+children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:22:03 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/23 19:22:04 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main ()
{
	pid_t	childPid;
	printf("Before fork %d\n", getpid());

	childPid = fork();

	printf("After fork %d\n", getpid());
	exit(0);
}