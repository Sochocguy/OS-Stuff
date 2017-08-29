/*
Justen Pacsai
CS4540 Operating Systems
A4 C and MakeFiles
*/
#include "a4.h"

int main() {
	String *string;
	String *string2;
	string = newString(20);
	string2 = newString(20);
	addChar(string,'h');
	addChar(string,'e');
	addChar(string,'l');
	addChar(string,'l');
	addChar(string,'o');
	printString(string);
	printChars(string);
	addChar(string2,'t');
	addChar(string2,'h');
	addChar(string2,'i');
	addChar(string2,'s');
	addChar(string2,'i');
	addChar(string2,'s');
	addChar(string2,'a');
	addChar(string2,'s');
	addChar(string2,'t');
	addChar(string2,'r');
	addChar(string2,'i');
	addChar(string2,'n');
	addChar(string2,'g');
	appendString(string,string2);
	addChar(string,'!');
	addChar(string,'!');
	addChar(string,'!');
	addChar(string,'!');
	printString(string);
	swap(string,0,4);
	printString(string);
	char ch = getPos(string,5);
	printf("%c\n",ch);
	int l = lengthString(string);
	printf("%d\n",l);
	sortString(string);
	printString(string);
	char arraything[100];
	getCString(string,arraything);
	printf("%s\n",arraything);
	catCString(string,"addingstuff");
	printf("%s\n",string->array);
	return 0;
}

void printString(String *str) {
	char dest[100];
	getCString(str,dest);
	printf("%s\n",dest);
}

void printChars(String *str) {
	int i;
	char ch;
	for(i=0;i<str->length;i++) { //prints the characters of str using the getPos method
		ch = getPos(str,i);
		printf("%c ",ch);
	}
	printf("\n");
}