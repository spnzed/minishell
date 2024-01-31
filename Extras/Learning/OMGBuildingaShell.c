/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OMGBuildingaShell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:58:18 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/23 19:29:55 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define	MAXARGS 128

int MAXLINE = 1024;
char prompt[] = "miniconchis> ";

struct command {
	int		argc;
	char	*argv[MAXARGS];
	enum	builtin_t {
		NONE, QUIT, JOBS, BG, FG
	}	builtin;
};

int parse (const char *cmdline, struct command * cmd)
{
	static char		array[1024];
	const char		delims[10] = " \t\r\n";
	char 			*line = array;
	char			*token;
	char			*endline;
	int				is_bg;
	
	if (!cmdline)
		error("command line is NULL\n");
	(void) strncpy(line, cmdline, MAXLINE);
	endline = line + strlen(line);

	cmd->argc = 0;
	
	while (line < endline)
	{
		line += strspn(line, delims);
		if (line >= endline)
			break ; 
		token = line + strcspn(line, delims);
		*token = '\0';
		cmd->argv[cmd->argc++] = line;
		if (cmd->argc >= MAXARGS-1)
			break ;
		line = token + 1;
	}
	
	cmd->argv[cmd->argc] = NULL;
	
	if (cmd->argc == 0)
		return 1;
	cmd->builtin = parseBuiltin(cmd);

	if ((is_bg = (*cmd->argv[cmd->argc-1] == '&')) != 0)
		cmd->argv[--cmd->argc] = NULL;
	return is_bg;
}

void	runSystemCommand(struct command *cmd, int bg)
{
	pid_t	childPid;

	if ((childPid = fork()) < 0)
		error("fork() error");
	else if (childPid == 0)
	{
		if (execvp(cmd->argv[0], cmd->argv) < 0)
		{
			printf("%s: Command not found\n", cmd->argv[0]);
			exit (0);
		}
	}
	else
	{
		if (bg)
			printf("Child in backgrounf [%d]\n", childPid);
		else
			wait(&childPid);
	}
}

void eval(char *cmdline)
{
	int				bg;
	struct command	cmd;

	printf("Evaluating '%s'\n", cmdline);
	
	bg = parse(cmdline, &cmd);

	if (bg == -1)
		return ;
	if (cmd.argv[0] == NULL)
		return ;
	if (cmd.builtin == NONE)
		runSystemCommand(&cmd, bg);
	else
		runBuiltinCommand(&cmd, bg);
}

int main (int argc, char **argv)
{
	char	cmdline[MAXLINE];

	while (1)
	{
		printf("%s", prompt);
		
		if ((fgets(cmdline, MAXLINE, stdin) == NULL) && ferror(stdin))
			error ("fgets error");
		if (feof(stdin))
		{
			printf("\n");
			exit (0);
		}
		cmdline[strlen(cmdline)-1] = '\0';
		eval(cmdline);
	}
}