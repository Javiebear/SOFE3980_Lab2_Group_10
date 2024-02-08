# SOFE3980_Lab2_Group_10

## Operations and Commands:

### Change Directory Command:  cd <directory>
This command will change the current directory to the specified <directory> directory inputted by the user which is done by using the chdir(<directory>) command. If the user does not specify the directory, it will print the current working directory. If there is an incorrect directory specified, it will display an error. 

### Clear Screen Command: clr
	This command will clear the screen of the terminal using the system(“clear”) command.

### List Contents of Directory Command: dir <directory>
	This command will list all the contents of the directory. It uses the DIR to open a directory path which is by default the one you are using else it will use the specified one. Then using the built in struct dirent, the code will take the directory files and print the contents within. 

### List Environment Variables Command: environ
	This command will print out all environment strings.

### Echo Command: echo <command>
	This command will take the string inputted by the user and print it out onto the terminal. Using the built in environment variable environ that stores all global variables, it will iterate through the global array and print out its contents.

### Help Command: 
	This command will display the user manual using the more filter.

### Pause Command: pause
	This command will freeze myshell until the user presses ENTER to continue execution. This is done using a while loop that will take chars from user input. Once that expected char ‘\n’ is entered, the while loop will end and the script will continue.

### Quit Command: quit
	This command will terminate the shell once the user inputs ‘quit’ in the terminal.


## Handling Program Invocation
	To execute the program, you must download the following code and place it into a folder of your choice. Run the terminal and change your directory to the one where you have placed these files in. in the terminal type ‘make’ to compile the program. To execute the program type ‘./myshell’.
 
## File-based command execution
If you want to run the myshell with the batch file type ./myshell batchfile.sh.
