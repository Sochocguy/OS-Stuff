/*
Justen Pacsai
CS4540 Operating Systems
A4 C and MakeFiles
*/
#include "a4.h"

//Got help from Geral Glasgow on the logic for the sort. He said that it was from Hardin as well.
void sortString(String *src) {

 int b,a = 0;

 while(a==0){ //while a swap occured
 	a=1; //set so that if a swap doesn't occur, it breaks
 	for(b=0;b<src->length-1;b++){
 		if(src->array[b] > src->array[b+1]) { 
				swap(src,b,b+1); //swap them two 
				a=0; //since a swap occured set a=0
		}	
 	}

 }
}


