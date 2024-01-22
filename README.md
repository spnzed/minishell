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

### 🗺️ Map Rules

<b>Map Requisites:</b>
- Only ``P`` *(Character)*, ``1`` *(wall)*, ``0`` *(empty)*, ``C`` *(collectible)*, and ``E`` *(exit)* will be accepted characters in our map (except if you add enemies as bonus)
- The map must be rectangular, i.e. all rows must have the same length
- There must be at least one exit, one player, and one collectible on the map
- The map must be closed, i.e. surrounded by walls

> <i>If any of these checks fail, the game must end with a error message.</i>

🏆 | The goal is for the player(s) to collect all the collectibles on the map before going to an exit in the least possible number of steps

<b>Map Creation:</b>
- Create a new text file with a .ber extension. This will be your map file.
- Open the text file in a text editor.
- Define the map dimensions using this 5 symbols to represent different elements on the map:
	- 0 for an empty space
	- 1 for a wall
	- C for a collectible
	- E for a map exit,
	- P for the player’s starting position.

- Create a rectangular or square map, knowing that the map must be surrounded by '1's (walls) and must contain only one 'P' (player's starting point), one 'E' (exit), and multiple 'C's (collectibles). To test all the game features and have a better gaming experience, create a good level design using other game objects such as '0' for empty spaces (where the player can move).
- After creating the map, you can run it by passing the path where the map was created:

### 📁 Structure

* ```libft/```  My own Libft library.
* ```maps/```  Some maps (for running and testing the game).
* ```mlx/```  Mlx library.
* ```src/```  The sauce!
* ```textures/```  All sprites used in the game in .xpm.


---
<h2>
Usage
</h2>

### Prerequisites

**Linux and MacOS**
This project requires the [GNU Compiler Collection](https://gcc.gnu.org/), the [GNU Make](https://www.gnu.org/software/make/) compiler, internet to clone [MiniLibX](https://github.com/42Paris/minilibx-linux#readme) in the libraryfolder and X11 Development Libraries and Headers (`sudo apt-get install libx11-dev`).

**Windows**

You'll need to install Xserver in your machine seeing as the library runs on X-Window system. You may also use WSL on Windows 11 and run ```wsl --update``` and you should be good to go. <br>
❗️| Make sure you have all the required tools installed on your local machine, then continue with these steps.<br>

### 🛠️ Instructions

**0. Download the archives**

```bash
# Clone the repository
$ git clone https://github.com/spnzed/so_long.git

# Enter into the directory
$ cd so_long/
```

**1. Run the Game**
```bash
# Run the command make root directory to run the mandatory part
$ make

# This command compiles the executable file 'so_long' and runs it along with any map
# of your choice (or a custom one) located in the directory 'maps'.
#	To execute it, run the following command:
$ ./so_long map.ber
```
**2. How to play**
- Control the player using the arrow keys (up, down, left, and right) or the letter keys (w, a, s, and d).
- Press the 'R' key on your keyboard to reset the current level.
- Press the [ESC] key or Click in the 'X' window to exit the game.

<p align="center">
<img width="841" alt="Captura de pantalla 2023-08-17 a las 12 01 43" src="https://github.com/spnzed/so_long/assets/95354392/ea6a73d7-2560-4c9f-b3d8-5e7263044a35">

</p>
