# <p align=center> Basic Shell </p>


<p align=center> It is simply a Shell written in C and inspired by other projects found here on GitHub. </p>

<p align=center> The interpreter is a tool that allows us to execute commands in our UNIX operating system. These commands can be simple, such as displaying the contents of a file, or more complex, such as executing a program. The following describes the basic concepts and commands needed to use the interpreter. </p>

---

<p align=center> Basic concepts </p>

<p align=center> I/O redirection: I/O redirection allows us to change the source or destination of the standard input or output of the command we are executing. This is useful when we want to save the output of a command to a file instead of seeing it on the screen, or when we want to give input to a command from a file instead of typing it manually. To do this, the following symbols can be used: </p>
   
<div align="center">

 Option | Meaning |
| --- | --- |
| `>` | To redirect the standard output to a file and overwrite its contents. |
| `>>` | To redirect the standard output to a file and append it to the end of the file. |
|`<`| To redirect the standard input from a file. |

</div>

<p align=center> Program environment: The program environment is a set of variables that define how a program is executed. These variables can range from the current working directory to the search paths for executables and libraries. The environment can be modified by the user to define new variables or modify existing ones. </p>

<p align=center> Background execution: Allows you to execute a program or command in the background, i.e. without having to wait for its execution to finish in order to continue working with the interpreter. To execute a command in the background, the symbol '&' can be added at the end of the command, as in the following example:
sleep 60 & </p>

---

<p align=center> Interpreter commands </p>

<div align="center">

 Option | Meaning |
| --- | --- |
| `cd directory>` | changes the current directory to *directory*. If the *directory* argument does not appear, returns the current directory. |
| `pwd` | Prints the current working directory. |
|`clr`| Clean the screen. |
|`pause`| Stops the command interpreter execution until *Enter* is pressed. |
|`dir <directory>`| Lists the contents of *directory*. |
|`environ`| Displays all environment variables. |
|`echo <comment>`| Displays *comment* on the screen followed by a new line. |
|`help`| Displays the user's manual. |
|`quit`| Exits the mandate interpreter. |

</div>
