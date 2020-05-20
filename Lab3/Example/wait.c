#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
       #include <sys/types.h>
       #include <sys/wait.h>


int main(int argc, char** argv){
	int a= 10;
	
	if (fork() == 0) {
		a++;
	}
	else {
		wait(NULL);
		printf("parent wait: %d\n", a);
	}

	return 0;
}
