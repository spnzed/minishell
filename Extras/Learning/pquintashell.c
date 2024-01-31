#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

//
//	START BUILDIN SHELL COMMANDS
//

/*
	Function Declarations for builtin shell commands:
 */
int lsh_cd(char **args);
int lsh_help();
int lsh_exit();

/*
	List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int (*builtin_func[]) (char **) = {
	&lsh_cd,
	&lsh_help,
	&lsh_exit
};

int lsh_num_builtins() {
	return sizeof(builtin_str) / sizeof(char *);
}

/*
	Builtin function implementations.
*/
int lsh_cd(char **args)
{
	if (args[1] == NULL) {
	fprintf(stderr, "lsh: expected argument to \"cd\"\n");
	} else {
	if (chdir(args[1]) != 0) {
	perror("lsh");
	}
	}
	return 1;
}

int lsh_help(void)//(char **args)
{

	int i;
	printf("Pquintan LSH\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");

	for (i = 0; i < lsh_num_builtins(); i++) {
	printf("	%s\n", builtin_str[i]);
	}

	printf("Use the man command for information on other programs.\n");
	return 1;
}

int lsh_exit(void)
{
	return 0;
}

//
//	FINISH BUILDIN SHELL COMMANDS
//

int ft_getchar() 
{
	char c;
	if (read(0, &c, 1) == 1)	// Read a character from stdin
	return (unsigned char)c;	// Convert to int to match getchar's return type
	else 
	return EOF;	// End of file or error
}

char	*lsh_read_line(void)
{
	int bufsize = LSH_RL_BUFSIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = ft_getchar();
		if (c == EOF || c == '\n') // If we hit EOF, replace it with a null character and return.
		{
			buffer[position] = '\0';
			return(buffer);
		}
		else
			buffer[position] = c;
		position++;
		if (position >= bufsize) // If we have exceeded the buffer, reallocate.
		{
			bufsize += LSH_RL_BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

char **lsh_split_line(char *line)
{
	int bufsize = LSH_TOK_BUFSIZE;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, LSH_TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize += LSH_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens)
			{
				fprintf(stderr, "lsh: allocation error\n");
			exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}

int lsh_launch(char **args)
{
	pid_t pid;
	pid_t wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		// Child process
		if (execvp(args[0], args) == -1)
		{
			perror("lsh");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0) // Error forking
		perror("lsh");
	else
	{
		// Parent process
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return 1;
}

int lsh_execute(char **args)
{
	int i;
	i = 0;
	if (args[0] == NULL) // An empty command was entered.
		return 1;
	while(i < lsh_num_builtins())
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
			return (*builtin_func[i])(args);
		i++;
	}
	return lsh_launch(args);
}

void	lshell_loop(void)
{
	// read standard input
	// parse string into program and arguments
	// execute run parsed command
	char *line;
	char **args;
	int status;
	do
	{
		printf("> ");
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args);

		free(line);
		free(args);
	} while(status); // so at least does once the loop 
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	lshell_loop();

	return EXIT_SUCCESS;
}
