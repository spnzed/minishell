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
<p align="center">
  <a href="https://github.com/spnzed/minishell/blob/main/en.subject.pdf">
    <img alt="Subject" src="https://github.com/spnzed/minishell/blob/main/en.subject.pdf"
  </a>
</p>

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

### 🤓 Before starting

What is Bash? How does it work?

A shell is a program that allows users to interact with the services of an operating system. Bash, the GNU shell, is presently the most widely used shell program. We approached the task of recreating bash quite literally, and our initial step involved understanding the inner workings of bash.

To do so, these are the recommended readings.

- ![Bash Manual](https://github.com/spnzed/minishell/blob/main/bash.pdf)
- ![Writing Your Own Shell](https://github.com/spnzed/minishell/blob/main/Chapter5-WritingYourOwnShell.pdf)

Essentially it breaks down the process into 4 steps: lexer → parser → expander → executor, which we replicated in our project.

### ⚙️ The Engine `lexer → parser → expander → executor`

![193665518-0c0c7fec-38a9-4f6c-91ca-fef606abfb0d](https://github.com/spnzed/minishell/assets/95354392/8e1fea33-b933-45a8-a0d3-bf056b85df44)
@maiadegraaf credits for the image!

**1. Lexer aka tokenizer**

Reads the line word by word, utilizing white space as delimiters. Initially, it verifies whether the word is a token, such as `|, <, <<, >, or >>`. Otherwise, it assumes the string is a regular word.

**2. Parser**

Then parser recieves the parameters, and distributes the different nodes together based on the tokens. Each group becomes a command.

![194295673-3c9e17c3-d5ab-40dc-82ef-72b909f4acb3](https://github.com/spnzed/minishell/assets/95354392/2c525e6e-8222-42d3-ad0d-633915c3d608)
@maiadegraaf credits for the image!

With a loop we will go through the previous arguments given by the Lexer until it finds a pipe (`|`). It then takes all the nodes before the pipe as one command, and creates a node in the struct. If it doesn't find a pipe it takes all the (remaining) nodes as one command.

1. Separations
2. Pipes
3. Command and arguments
4. Protections
5. Redirections `<, >, >>`
6. Environment variables

**3. Expander**

Before a node from t_simple_cmds is handled it is expanded. The expander takes variables, identified by $, and replaces them with their value from the environment variables. Such that `$USER becomes mgraaf`, and `$?` is replaced with the exit code.

**4. Executor**
1. Redirections
2. Env, export, unset
3. Exit and `$?`
4. Pipe/signal/process links

## Builtins

We were asked to implement some basic builtins with the help of some functions, here is a brief overview of them:

| Builtin | Description | Options | Parameters | Helpful Functions |
| :-----: | :---------: | :-----: | :--------: | :---------------: |
| ``echo`` | Prints arguments separated with a space followed by a new line | ``-n`` | :heavy_check_mark: | [write](https://man7.org/linux/man-pages/man2/write.2.html) |
| ``cd`` | Changes current working directory, updating ``PWD`` and ``OLDPWD`` | :x: | :heavy_check_mark: | [chdir](https://man7.org/linux/man-pages/man2/chdir.2.html) |
|  ``pwd``| Prints current working directory | :x: | :x: | [getcwd](https://www.man7.org/linux/man-pages/man3/getcwd.3.html) |
| ``env`` | Prints environment | :x: | :x: | [write](https://man7.org/linux/man-pages/man2/write.2.html) |
| ``export`` | Adds/replaces variable in environment | :x: | :heavy_check_mark: | :x: |
| ``unset`` | Removes variable from environment | :x: | :heavy_check_mark: | :x: |

@madebypixel02 credits for the table info!

### 📁 Structure

* ```include/```  	Libs.
* ```srcs/```		Our program.
	* ```main/```	The sauce!
	* ```utils/```	Supporting cast.
