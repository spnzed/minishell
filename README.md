<h1 align=center>
	<b>minishell</b>
	 
  <i>42cursus' project #9</i>
</h2>
In this project, we are going to develop our own C-based shell capable of handling redirections, pipes, environment variables, and various built-in functionalities.
  <h1 align=center>

![minishelle](https://github.com/spnzed/minishell/assets/95354392/e8f39a7e-446a-49c1-adb5-36761ac6ec79)

---

<h3 align=center>
Mandatory
</h3>

<b>Shell should:</b>

- Display a prompt for user input while awaiting a new command.
- Implement a functional history mechanism.
- Search for and execute the appropriate executable, considering the PATH variable or specifying a relative or absolute path.
- Limit the use of global variables to a single instance for signal reception. This approach ensures that the signal handler does not access primary data structures.
- Exercise caution; the global variable should only convey the received signal number, providing no other information or data access. Thus, incorporating "norm" type structures in the global scope is forbidden.
- Refrain from interpreting unclosed quotes or unnecessary special characters like \ (backslash) or ; (semicolon).
- Manage ' (single quote) to prevent the shell from interpreting meta-characters within the quoted sequence.
- Manage " (double quote) to prevent the shell from interpreting meta-characters within the quoted sequence, with the exception of $ (dollar sign)."

<b>Implement redirections:</b>
- "<" should redirect input.
- ">" should redirect output.
- "<<" should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history!
- ">>" should redirect output in append mode.

<b>Implement pipes "|":</b>
- The output of each command in the pipeline is connected to the input of the next command via a pipe

<b>Environment variables "$":</b>
- ($ followed by a sequence of characters) which should expand to their values.

<b>Handle "$?":</b>
- Should expand to the exit status of the most recently executed foreground pipeline.

<b>Handle ctrl-C, ctrl-D and ctrl-\:</b>
- Behave like in bash. If interactive mode:
    - ctrl-C displays a new prompt on a new line.
    - ctrl-D exits the shell.
    - ctrl-\ does nothing.

<b>Builtins:</b>
- echo with option -n
- cd with only a relative or absolute path
- pwd with no options
- export with no options
- unset with no options
- env with no options or arguments
- exit with no options

<h3 align=center>


<h2>
The Project
</h2>

### ⚙️ Process

**1. Lexer**

**2. Parser**

1. Separations
2. Pipes
3. Command and arguments
4. Protections
5. Redirections <, >, >>
6. Environment variables

**3. Expander**


**4. Executor**
1. Redirections
2. Env, export, unset
3. Exit and $?
4. Pipe/signal/process links

### 📁 Structure

* ```include/```  	Libs.
* ```srcs/```		Our program.
	* ```main/```	The sauce!
	* ```utils/```	Supporting cast.
