// File: utility.c
// Date: Feb 2, 2023
// SOFE 3950U Operating Systems Lab 2
// Group# 10:
// Javier Chung - 100785653
// Andy Dai - 100726784

#include "myshell.h"

#define BUFFER_SIZE 1024

// This method takes the statement and performs the specified command
void execute_command(char* statement){
	
	//initializing variables
	char* delim = " \n";
	char* args[128];
	int arg_count = 0; 
	char* token = strtok(statement, delim);
	
	//seperating the command
	while (token != NULL && arg_count < 127) {
		args[arg_count++] = token;
		token = strtok(NULL, delim);
	}
	
	args[arg_count] = NULL;

	char* command = args[0];
		
		//cd command	
		if(strcmp(command, "cd") == 0){
			//strtok will seperate the input by "\n"
			if (arg_count > 1) {
				change_directory(args[1]);
			} else {
				fprintf(stderr, "you need to added an argument. \n");
			}
		}
		//clear command
		else if(strcmp(command, "clr") == 0){
			clear_screen();
		}		
		
		//dir command
		else if(strcmp(command, "dir") == 0){
			if (arg_count > 1) {
				directory_contents(args[1]);
			} else {
				directory_contents(".");
			}
		}
		//environ command
		else if(strcmp(command, "environ") == 0){
			list_environment();
		}
		//echo command
		else if(strcmp(command, "echo") == 0){
			if (arg_count > 1) {
				echo(args[1]);
			}
		}
		//help command
		else if(strcmp(command, "help") == 0){
			printf("All interal commands: \n\n");
			printf("cd ---  changes directories\n");
			printf("clr --- clears your prompt\n");
			printf("dir <directory>---  changes the directory that the shell is in \n");
			printf("environ --- shows all the environment strings\n");
			printf("echo <any word> --- Displays the string that you wrote \n");
			printf("help --- Displays all the interal commands availible and what they do \n");
			printf("pause --- pauses the shell until the user presses the enter key \n");
			printf("quit --- exits out of the shell \n");
		}
		//pause command
		else if(strcmp(command, "pause") == 0){
			pause_shell();
			token = ""; //resetting token after pausing
		else{
			//execution of any commanands that are not internal
			pid_t pid = fork();
			
			//parent process
			if (pid > 0) {
				int status;
				waitpid(pid, &status, 0);
			} else {
				
				//this is the child process, setting up the parent environment variables	 
				char parentEnv[BUFFER_SIZE];
				snprintf(parentEnv, sizeof(parentEnv), "parent=%s/mtshell", getenv("PWD"));		
				setenv("parent", parentEnv, 1);
				
				//execution of the commmand		
				if (execvp(command, args) == -1) {
					//error catch if execution could not be done
					perror("execvp");
					exit(EXIT_FAILURE);
				}
			}
		}
	}

int main(int argc, char* argv[]){
	
	//intializing variables to store commands
	char statement[BUFFER_SIZE];
	char pwd[BUFFER_SIZE];
	FILE *fp = NULL;
	
	//getting current working directory and saving it onto pwd	
	getcwd(pwd, BUFFER_SIZE);
	
	//introduction of the program	
	printf("Welcome to myshell!\n");
	
	//printing out the shell path
	printf("%s:$ ", pwd);
	
	//if more than the start argument is passed, will open the file called
	if (argc > 1) {
		fp = fopen(argv[1], "r");
		//error catch for file opener
		if (fp == NULL) {
			perror("could not open file");
			return 1;
		}
		if (fp) {
			//grabs each line and runs it from the batch file
			while (fgets(statement, BUFFER_SIZE, fp) != NULL) {
				execute_command(statement);
			}
			fclose(fp);
		} else {
			while(fgets(statement, BUFFER_SIZE, stdin)) {
				execute_command(statement);
			}
		}
		
	}
	//loop to constantly take user input
	while((fgets(statement, BUFFER_SIZE, stdin) != NULL)){
		
		//quiting the shell when the user types quit
		if(strcmp(statement, "quit\n" ) == 0){
			//quit
			printf("Terminating the shell.\n");
			return 0;
		}	
		else{
			execute_command(statement);
			//constantly update and get the working directory
			getcwd(pwd, BUFFER_SIZE);
			printf("%s:$ ", pwd);
		}
	}
	return 0;
}
