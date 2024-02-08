# File: utility.c
# Date: Feb 2, 2023
# SOFE 3950U Operating Systems Lab 2
# Group# 10:
# Javier Chung - 100785653
# Andy Dai - 100726784

myshell: myshell.c utility.c myshell.h
	gcc -Wall myshell.c utility.c -o myshell
