#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char** argv){
	if (fork() == 0){
		if(fork() > 0){
			fork();
		}
	}
	else{
		if(fork() == 0){
			if (fork() == 0){
				fork();
			}
		}
		else{
			fork();
		}
	}
	
	sleep(20);
	return 0;
}
