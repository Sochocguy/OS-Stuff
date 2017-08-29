/*
Justen Pacsai
CS4540 Operating Systems
A4 C and MakeFiles
*/
#ifndef A4_H
#define A4_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *array; //array of characters the string is stored in
	int size; //the current size of the array
	int length; //how many characters in the array, or position to put next character
}String;

#include "string.h"
#include "sort.h"

//extern String *string;

void printString(String *str);
void printChars(String *str);

#endif