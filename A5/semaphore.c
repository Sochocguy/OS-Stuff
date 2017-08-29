/*
Justen Pacsai
CS4540 Operating Systems
Semaphores
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>


typedef struct {
	char * name;
	sem_t sem;
}Semaphore;

int getSemephore(int index,Semaphore s, Semaphore k);

int main() {
//initialize the two semaphores Screen and Keyboard
Semaphore screen;
Semaphore keyboard;
screen.name="screen";
keyboard.name="keyboard";
//opens the semaphores
sem_open(screen.name,O_CREAT,1,1);  
sem_open(keyboard.name,O_CREAT,1,2);
//fork 4 processes
pid_t pid;
int i,count;
for(i=0;i<4;i++){
	printf("I am Process %ld\n",(long) getpid());
	pid = fork();
	//if forked failed
	if(pid < 0) {
		perror("Fork failed");
	}
	//if in child process
	else if(pid == 0) {
		int index = i+1;
		printf("I am child process %d\n", index);
		char input;
		for(i=0;i<2;i++) {
			count = getSemephore(index,screen,keyboard);
			//while input isn't q, prompt, read, and echo
			while(input != 'q') {
				printf("This is process %ld and it has %d deadlocks\n",(long)pid,count);
				printf("Enter a letter or enter q to quit\n");
				scanf("%c",&input);
				printf("\n");
				printf("%c\n",input);
			}
		printf("Quit was called\n");
		input = 'a';	
		//posts and closes the semaphores
		sem_post(&screen.sem);
		sem_post(&keyboard.sem);
		sem_close(&screen.sem);
		sem_close(&keyboard.sem);
	}
	printf("PROCESS %ld IS DYING BLERGEREGERERGERGERGERERF..........................\n",(long)pid);
	_exit(0);
	}
	//if in parent process
	else {
		printf("I am the parent process\n");
	}
	//waits for all the childs to complete
	wait(NULL);
	}
	//unlink the semaphores
	sem_unlink(screen.name);
	sem_unlink(keyboard.name);
	return 0;
}
//Not sure what to do here
int getSemephore(int index,Semaphore s, Semaphore k) {
	int count = 0; // WILL CHANGE THIS LATER
	int b =0;
	struct timespec ts;
	ts.tv_sec = 10;
	int x=0;
	//re opens semaphores
	sem_open(s.name,O_CREAT,1,1);  
	sem_open(k.name,O_CREAT,1,2);
	//if we are at a odd index
	if(index % 2 == 1) {
		while(b == 0) {
			sem_wait(&s.sem);
			x = sem_timedwait(&k.sem, &ts);
			//if a timeout occurs
			if(x != 0) {
				printf("Timeout Occured!");
				sem_post(&s.sem);
				sleep(10);
				count++;
			}
			else {
				//Have both true. NEED MORE EXPLANATION HERE. break goes here?
				b = -1;
				
			}
		}
	}
	//at even index
	else {
		while(b == 0) {
			sem_wait(&k.sem);
			x = sem_timedwait(&s.sem, &ts);
			//if a timeout occurs
			if(x != 0) {
					printf("Timeout Occured!");
					sem_post(&k.sem);
					sleep(2);
					count++;
				}
			else {
				//Have both true. NEED MORE EXPLANATION HERE. break goes here?
				b = -1;

			}
		}
	}
	return count;
}
