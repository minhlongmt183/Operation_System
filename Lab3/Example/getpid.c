#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	printf("Process Id: %d\n", getpid());	
	printf("Parent Process Id: %d\n", getppid());	
	printf("My group: %d\n", getpgrp());	



	return 0;
}
