/*
Justen Pacsai
CS4540 Operating Systems
A4 C and MakeFiles
*/
#include "a4.h"

//this method will initialize a new string
String *newString(int initialSize) {
	String *string = malloc(sizeof(String));
	string->array = malloc(initialSize * sizeof(char)); //DON'T KNOW IF THIS IS RIGHT!
	string->size = initialSize; 
	string->length = 0; //This will give us the position of where we are adding the next char
	return string;
}

//this method will add a character to the string (I believe it will be to the end of the string)
void addChar(String *str, char ch) {
	if(str->length < str->size) {
		str->array[str->length] = ch; //assign the character to the array
		str->length++;
	}
	else {
		str->array = realloc(str->array, 5 * sizeof(str->array)); //reallocate memory in the array
		str->size = str->size * 5; //increases size to the size of the array
	}
}

//this method will get the character at a certain position in the character array
char getPos(String *str, int position) {
	char ch;
	if(position > str->length+1) { //if the position is out of bounds
		ch = -1;
	}
	else {
		ch = str->array[position]; //gets the character
	}
	return ch;
}

//this method will return the length of the string passed in
int lengthString(String *str) {
	int length = str->length;
	return length;
}

//this method will append a string to the back of another string 
int appendString(String *destination, String *src) {
	char ch;
	int i;
	for(i=0; i < src->length; i++) {
		if(destination->length < destination->size) { //if we are not out of allocated space
			ch = src->array[i]; //set ch to the array character at i
			addChar(destination,ch); 
		}
		else {
			destination->array = realloc(destination->array, 5 * sizeof(destination->array)); //reallocate memory of the array
			destination->size = destination->size * 5; //make size bigger
			ch = src->array[i]; //same steps as above
			addChar(destination,ch);
		}
	}
	return 0;
}

int swap(String *str, int pos1, int pos2) {
	if(pos1 > str->length || pos2 > str->length) { //if you have any out of range position, it wont work
		return -1;
	}
	else {
		char temp;
		temp = str->array[pos1]; //swaps the characters
		str->array[pos1] = str->array[pos2];
		str->array[pos2] = temp;
		return 0;
	}
}

void getCString(String * str, char dest[]) {
	int i;
	for(i=0;i<str->length;i++) { //copies each str array character into the destination array
		dest[i] = str->array[i];
	}
	dest[str->length] = '\0'; //adds null at the end
}

int catCString(String *str, char* src) {
	int i;
	int length = strlen(src);
	for(i=0; i<length; i++) { //appends the src onto str
		str->array[str->length+i] = src[i];
	}
	return 0;
}


