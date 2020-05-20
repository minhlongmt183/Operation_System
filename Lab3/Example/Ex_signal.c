#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int agrc, char** argv){
	
	pid_t child_pid;
	sigset_t mask, oldmask;

	child_pid = fork();

	if (child_pid == -1){
		perror("fork");
		exit(1);
	}

	if (child_pid == 0){
		signal(SIGUSR1, parentdone);
		sigemptyset(&mask);
		sigaddset(&mask, SIGUSR1);

		sigprocmask (SIG_BLOCK, &mask, &oldmask);
		while (!usr_interrupt)
			sigsuspend(&oldmask);
		sigprocmask(SIG_UNBLOCK, &mask, NULL);

		printf("World!\n");
		fflush(stdout);
	}
	else{
		printf("Hello, ");
		fflush(stdout);
		kill(child_pid, SIGUSR1);
		wait(NULL);
	}


	return 0;
}
