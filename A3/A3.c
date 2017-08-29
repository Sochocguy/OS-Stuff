/*
Justen Pacsai
CS4540 Operating Systems
A3 Thread Swap 
*/

// Got inspriation and modeled it from http://ashishsingh14.blogspot.com/2014/04/function-to-reverse-string-using.html

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_OF_THREADS 8

//structs
typedef struct {
    int tid; //threads ID
    int size; //size of the 
    int *start;//pointer to the start of the array we are trying to swap
    int *finalstart; //pointer to the start of the array we are storing the final result in
    int numberPerThread; //number of swaps that will occur
    int remainingLength; //keeps track of the remaining elements 
}threadInfo;

//structs
typedef struct {
    int *array; //pointer to the array
    int size; //size of the array
}Info;

//Prototypes
void printArray(int arr[], int size);
void* swap (void *data);

int main() {
    Info info[3]; // array that holds the structs for info array
    Info final[1];//array that hold the structs for final array

    final[0].array = NULL; 
    final[0].size = 40; 
    final[0].array = (int *)malloc(sizeof(int)*final[0].size); //malloc the amount of space needed

    //sets the appropriate information into each corresponding element in the struct array
    info[0].array = NULL;
    info[0].size = 16;
    info[0].array = (int *)malloc(sizeof(int)*info[0].size); //malloc the amount of space needed
    
    info[1].array = NULL;
    info[1].size = 35;
    info[1].array = (int *)malloc(sizeof(int)*info[1].size); //malloc the amount of space needed
    
    info[2].array = NULL;
    info[2].size = 40;
    info[2].array = (int *)malloc(sizeof(int)*info[2].size); //malloc the amount of space needed

    //gets random number
    int randomNumber; //random number variable
    randomNumber = rand() % 100; //stores random number betweeen 1-100 in randomNumber
    printf("The Random Number is %d\n",randomNumber); //prints the random number

    //Fill the arrays
    int i;
    int temp1 = randomNumber;
    int temp2 = randomNumber;
    int temp3 = randomNumber;
    
    //these for loops will go through and store the appropriate number at the appropriate array index
    for(i=0; i < info[0].size; i++) {
        info[0].array[i] = i + temp1;
    }
    for(i=0; i < info[1].size; i++) {
        info[1].array[i] = i + temp2;
    }
    for(i=0; i < info[2].size; i++) {
        info[2].array[i] = i + temp3;
    }

    //print the arrays
    printArray(info[0].array,info[0].size);
    printArray(info[1].array,info[1].size);
    printArray(info[2].array,info[2].size);

    //declare thread array
    pthread_t threads[NUM_OF_THREADS];

    //figure out how many numbers will be switched per thread and how many will remain
    int lengthperthread1 = info[0].size / NUM_OF_THREADS; //gets the number of swaps that will occur for each thread          
    int remaininglength1 = info[0].size %  NUM_OF_THREADS; //get the remaining length 

    int lengthperthread2 = info[1].size /  NUM_OF_THREADS; //gets the number of swaps that will occur for each thread           
    int remaininglength2 = info[1].size %  NUM_OF_THREADS; //get the remaining length 

    int lengthperthread3 = info[2].size /  NUM_OF_THREADS; //gets the number of swaps that will occur for each thread          
    int remaininglength3 = info[2].size %  NUM_OF_THREADS; //get the remaining length 

    //make threadInfo struct arrays
    threadInfo data1[NUM_OF_THREADS];
    threadInfo data2[NUM_OF_THREADS];
    threadInfo data3[NUM_OF_THREADS];
    
    //store the appropriate data into the data1 array
    for(i=0; i < NUM_OF_THREADS; i++) {
        if(remaininglength1 != 0 && i < (NUM_OF_THREADS-1)) { //if we are at the last thing to sort
            data1[i].tid = i; 
            data1[i].start = &info[0].array[i * lengthperthread1]; //start goes up by i times the number of swaps to be performed
            data1[i].numberPerThread = lengthperthread1; 
            data1[i].remainingLength = remaininglength1;
            data1[i].size = info[0].size;
            data1[i].finalstart = final[0].array; 
        }
        else {
            data1[i].tid = i;
            data1[i].start = &info[0].array[i * lengthperthread1]; //start goes up by i times the number of swaps to be performed
            data1[i].numberPerThread = lengthperthread1;
            data1[i].remainingLength = remaininglength1;
            data1[i].size = info[0].size;
            data1[i].finalstart = final[0].array; 
        }

        pthread_create(&threads[i], NULL, swap, &data1[i]); //create a thread for swapping
    }
    //join the threads back together
    for(i=0; i < NUM_OF_THREADS; i++) { 
        pthread_join(threads[i], NULL);
    }
    //print the results for array 1
    printArray(final[0].array,info[0].size);

    //store the appropriate data into the data2 array
    for(i=0; i < NUM_OF_THREADS; i++) {
        if(remaininglength2 != 0 && i < (NUM_OF_THREADS-1)) { //if we are at the last thing to sort
            data2[i].tid = i;
            data2[i].start = &info[1].array[i * lengthperthread2]; //start goes up by i times the number of swaps to be performed
            data2[i].numberPerThread = lengthperthread2;
            data2[i].remainingLength = remaininglength2;
            data2[i].size = info[1].size;
            data2[i].finalstart = final[0].array; 
        }
        else {
            data2[i].tid = i;
            data2[i].start = &info[1].array[i * lengthperthread2]; //start goes up by i times the number of swaps to be performed
            data2[i].numberPerThread = lengthperthread2;
            data2[i].remainingLength = remaininglength2;
            data2[i].size = info[1].size;
            data2[i].finalstart = final[0].array; 
        }

        pthread_create(&threads[i], NULL, swap, &data2[i]); //create a thread for swapping
    }
    //join the threads back together
    for(i=0; i < NUM_OF_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    //print the final result for second array
    printArray(final[0].array, info[1].size);

    //store the appropriate data into the data3 array
    for(i=0; i < NUM_OF_THREADS; i++) {
        if(remaininglength3 != 0 && i < (NUM_OF_THREADS-1)) { //if we are at the last thing to sort
            data3[i].tid = i;
            data3[i].start = &info[2].array[i * lengthperthread3]; //start goes up by i times the number of swaps to be performed
            data3[i].numberPerThread = lengthperthread3;
            data3[i].remainingLength = remaininglength3;
            data3[i].size = info[2].size;
            data3[i].finalstart = final[0].array;
        }
        else {
            data3[i].tid = i;
            data3[i].start = &info[2].array[i * lengthperthread3]; //start goes up by i times the number of swaps to be performed
            data3[i].numberPerThread = lengthperthread3;
            data3[i].remainingLength = remaininglength3;
            data3[i].size = info[2].size;
            data3[i].finalstart = final[0].array;
        }

        pthread_create(&threads[i], NULL, swap, &data3[i]); //create a thread for swapping
    }
    //join the threads back together
    for(i=0; i < NUM_OF_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    //print the final result for third array
    printArray(final[0].array, info[2].size);

}

void printArray(int arr[], int size) {
    int i;
    for(i=0;i<size;i++) { //goes through the loop and prints the data out
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void* swap (void *data) {
    int position, length;
    threadInfo* d = (threadInfo*)data; //stores data into d
    position = (d->tid) * (d->numberPerThread); // sets position to be tid (which is equal to the corresponding i) times the number of swaps
    length = d->size;
    int u;
    for(u = position; u < (position + d->numberPerThread + d->remainingLength); u++) { //this loop will take the starting value and put it at the end until there is no more swapping
        d->finalstart[length - u -1] = (*(d->start));
        d->start++; 
    }
    pthread_exit(NULL); //exits the thread
}
