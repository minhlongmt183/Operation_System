#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>



int main(int argc, char** argv){
	fork();
	(fork() && fork()) || fork();
	//fork();

	printf("forked\n");
	sleep(20);

	return 0;
}
