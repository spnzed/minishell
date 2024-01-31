/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:57:18 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/31 13:58:52 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

# define RESET   "\033[0m"
# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN    "\033[1;36m"
# define WHITE   "\033[1;37m"

int main(int argc, char **argv, char **env) {
    printf(BLUE"Número de argumentos: %d\n"RESET, argc);
    printf(GREEN"Argumentos:\n"RESET);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    printf(YELLOW"Variables de entorno:\n"RESET);
    for (int i = 0; env[i] != NULL; i++) {
        printf("env[%d]: %s\n", i, env[i]);
    }
    return 0;
}
