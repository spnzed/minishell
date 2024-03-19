/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:55:26 by pquintan          #+#    #+#             */
/*   Updated: 2024/03/12 17:00:17 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool str_nflag(char *str)
{
    int i = 0;
    if (str[i] == '-')
        i++;
    else
        return false;
    if (str[i] == 'n')
        while (str[i] == 'n')
            i++;
    else
        return false;
    return true;
}

static int echo_home(char *line, char *HOME, int i)
{
    if (line[0] == '~')
    {
        if (line[1] == ' ' || line[1] == '\0' || line[1] == '/')
            printf("%s", HOME);
        else
            printf("~");
        if (line[1] == '\0')
            return i + 1;
        else
            return i + 99;
    }
    return i;
}

static int echo_prev_one(t_info *data, t_echo e, char **line)
{
    while (line[e.i] && str_nflag(line[e.i]) == true)
    {
        e.n_option = str_nflag(line[e.i]);
        e.i++;
        e.n++;
    }
    if (line[e.i])
        e.i = echo_home(line[e.i], data->home, e.i);
    else
    {
        if (e.n_option == false)
            return 2;
        else
            return 0;
    }
    if (e.i > 99)
    {
        e.i -= 99;
        e.j++;
    }
    if (e.i == e.n + 2 && !line[e.i])
    {
        if (e.n_option == false)
            return 2;
        else
            return 0;
    }
    return 1;
}

static void process_quotes(t_echo e, char **line, t_info *data)
{
    while (line[e.i][e.j] && line[e.i][e.j] != ' ' && line[e.i][e.j] != '\n' && line[e.i][e.j] != '\t')
    {
        if (line[e.i][e.j] == '~' && line[e.i][e.j - 1] == ' ')
        {
            printf("%s", data->home);
            e.j++;
        }
        if (line[e.i][e.j] == '\"' || line[e.i][e.j] == '\'')
        {
            e.quote = line[e.i][e.j];
            e.j++;
            while (line[e.i][e.j] && e.quote != line[e.i][e.j])
                printf("%c", line[e.i][e.j++]);
            if (e.quote == line[e.i][e.j])
                e.j++;
        }
        else
            printf("%c", line[e.i][e.j++]);
    }
}

static void echo_words(t_echo e, char **line, t_info *data)
{
    while (e.len > e.i)
    {
        process_quotes(e, line, data);
        if (!line[e.i][e.j] && e.i != e.len - 1)
            printf(" ");
        e.i++;
        e.j = 0;
    }
}

int ft_echo(t_info *data, char **line)
{
    t_echo e;
    e.i = 1;
    e.j = 0;
    e.n = 0;
    e.len = ft_arrlen(line);
    e.n_option = false;

    while (line[e.i] && str_nflag(line[e.i]) == true)
    {
        e.n_option = str_nflag(line[e.i]);
        e.i++;
        e.n++;
    }
    if (line[e.i])
        e.i = echo_home(line[e.i], data->home, e.i);
    else
    {
        if (e.n_option == false)
            return printf("\n"), 0;
        else
            return 0;
    }
    if (e.i > 99)
    {
        e.i -= 99;
        e.j++;
    }
    if (e.i == e.n + 2 && !line[e.i])
    {
        if (e.n_option == false)
            return printf("\n"), 0;
        else
            return 0;
    }

    echo_words(e, line, data);

    if (e.n_option == false)
        printf("\n");
    data->exit_id = 0;
    return 0;
}
