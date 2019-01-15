/******************************************************************************
* 
* Name: 	Zaid Albirawi
* Email: 	zalbiraw@uwo.ca
*
* helper.h
*
******************************************************************************/

#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "d_linked_list.h"

#define FALSE 0
#define TRUE 1

#define MAX_STR_LEN 1024
#define MAX_NUM_LEN 4

#define DELETE 127
#define KEYLEFT 4
#define KEYRIGHT 5
#define KEYUP 3
#define KEYDOWN 2
#define TAB '\t'
#define WHITE_SPACE ' '

#define CAT "cat"
#define TEE "tee"
#define OUT "out"
#define EXIT "exit"

#define FAILURE 1
#define SUCCESS 0
#define TERMINATE -1

#define READ "r"
#define WRITE "w"

#define FCFS 0
#define LIFO 1
#define SJF 2
#define RR 3

void print_user();
char getch(FILE*);
void delete(int, char*);
char switch_keypad(char);
char* trim(char*, int);
int get_arg_number(char*);
char*** transform_d_linked_list_to_3d_char(d_linked_list_t*);
void print(FILE*, char*, int);
void print_exceed_memory(FILE*, int);
void print_insufficient_memory(FILE*, int);
void print_starting(FILE*, int);
void print_completed(FILE*, int);
void print_memory_status(FILE*, int);
void print_allocate_memory(FILE*, int, int);
void print_deallocate_memory(FILE*, int, int);
void print_mode(FILE*, int);
#endif