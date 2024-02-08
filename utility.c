// File: utility.c
// Date: Feb 2, 2023
// SOFE 3950U Operating Systems Lab 2
// Group# 10:
// Javier Chung - 100785653
// Andy Dai - 100726784

#include "myshell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

//this method changes the directory of the
void change_directory(char* path){

	//if no path was specified when changing directories, print out cwd
	if (path == NULL){
		char cwd[1024];
		if(getcwd(cwd, sizeof(cwd)) != NULL){ //gets current working dir
			printf("%s\n", cwd);
		}
		else{
			perror("getcwd() error: ");
		}
	}else{
	
		if (chdir(path) != 0){ // changes directory to path
			perror("myshell");
		}
	}
}

//this method will clear the screen of myshell
void clear_screen(){
	system("clear");
}

//this method will list the current directories contents
void directory_contents(char* path){
	DIR* directory;
	struct dirent* en;

	
	//when no directory is specified, this one is set to the path
	if(path == NULL){
		directory = opendir("."); //open the current directory
	}else{ //the specified path is expanded
		directory = opendir(path); //open the specified directory
	}
	

   	if (directory != NULL) {
      		while ((en = readdir(directory)) != NULL) {
         		printf("%s\n", en->d_name); //prints contents of directory
      		}
      	closedir(directory); //close the directory
   	}
   	else{
   		perror("opendir() error: ");
   	}	
}

//this method will list all environment strings
void list_environment(){

	//all environment variables are stored in this global var
	extern char** environ; 
	
	//iterate through the environ global array
	for (int i = 0; environ[i] != NULL; i++) {
    		printf("%s\n", environ[i]);
  	}

}

//this method will echo a comment
void echo(char* comment){
	printf("%s\n", comment);

}

//this method will pause the shell
void pause_shell(){
	printf("myshell has now paused. Press ENTER to continue...\n");
	
	char key;
	//looping untill the user presses ENTER using getchar function
	while (key != '\n'){
		//get the next char 
		key = getchar();
	}
	
}
