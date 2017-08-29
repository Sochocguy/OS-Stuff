/*
Justen Pacsai
CS4540 Operating Systems
A4 C and MakeFiles
*/
#ifndef STRING_H
#define STRING_H

String *newString(int initialSize);
void addChar(String *str, char ch);
char getPos(String *str, int position);
int lengthString(String *str);
int appendString(String *destination, String *src);
int swap(String *str, int pos1, int pos2);
void getCString(String * str, char dest[]);
int catCString(String *str, char* src);

#endif