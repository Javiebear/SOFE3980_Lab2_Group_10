// File: utility.c
// Date: Feb 2, 2023
// SOFE 3950U Operating Systems Lab 2
// Group# 10:
// Javier Chung - 100785653
// Andy Dai - 100726784

#ifndef MYSHELL_H
#define MYSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>

#endif

//Function declarations
void change_directory(char* path);
void clear_screen();
void directory_contents(char* path);
void list_environment();
void echo(char* comment);
void pause_shell();
void help();
