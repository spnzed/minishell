/* ************************************************************************		*/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:22:46 by aaespino          #+#    #+#             */
/*   Updated: 2024/02/16 15:59:20 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************		*/

#include "minishell.h"

void	signal_handler_heredoc(int sig)
{
	if (sig == SIGINT)
		exit(0);
	else if (sig == SIGQUIT)
	{
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

/*
Las señales en sistemas Unix y similares son identificadas por números enteros. 
A continuación, te proporciono las 31 señales más comunes, junto con su traducción 
en inglés y su valor numérico:

1. SIGHUP		(Hangup)
2. SIGINT		(Interrupt)
3. SIGQUIT		(Quit)
4. SIGILL		(Illegal instruction)
5. SIGTRAP		(Trace trap)
6. SIGABRT		(Abort)
7. SIGBUS		(Bus error)
8. SIGFPE		(Floating-point exception)
9. SIGKILL		(Kill)
10. SIGUSR1		(User-defined signal 1)
11. SIGSEGV		(Segmentation fault)
12. SIGUSR2		(User-defined signal 2)
13. SIGPIPE		(Broken pipe)
14. SIGALRM		(Alarm clock)
15. SIGTERM		(Termination)
16. SIGSTKFLT	(Stack fault)
17. SIGCHLD		(Child status has changed)
18. SIGCONT		(Continue)
19. SIGSTOP		(Stop)
20. SIGTSTP		(Terminal stop signal)
21. SIGTTIN		(Background read from control terminal)
22. SIGTTOU		(Background write to control terminal)
23. SIGURG		(Urgent condition on socket)
24. SIGXCPU		(CPU time limit exceeded)
25. SIGXFSZ		(File size limit exceeded)
26. SIGVTALRM	(Virtual alarm clock)
27. SIGPROF		(Profiling timer expired)
28. SIGWINCH	(Window size change)
29. SIGIO		(I/O now possible)
30. SIGPWR		(Power failure restart)
31. SIGSYS		(Bad system call)

Cuando sumas 128 al valor numérico de una señal, obtienes el número que se usa en el 
estado devuelto por `waitpid` cuando un proceso hijo termina debido a esa señal. 
Por ejemplo, si sumas 128 a 2 (que es el valor de SIGINT), obtienes 130, que es el 
número que se usará en el estado devuelto por `waitpid` cuando un proceso hijo termine 
debido a SIGINT.

De esta forma

	Señal + valor numerico de señal

	2 + 128 = 130 	-> 	SIGINT	->	CTRL+C
	3 + 128 = 131 	-> 	SIGQUIT	->	CTRL+\
*/
void	catch_signal(t_info *data, int status, int set_status)
{
	if (status == 130)
		ft_putstr_fd("\n", STDOUT_FILENO);
	if (status == 131)
		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
	if (set_status)
		data->status = status;
}

/*
	SIGINT: CTRL+C
	SIGQUIT: CTRL+\
*/
void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		rl_replace_line("", 0);
		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_redisplay();
	}
}
