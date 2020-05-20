#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




char* PATH1 = "/mnt/DATA/MinhLong/MT-183/_2019/_HK192/OS/Labs/Lab2/main";
char* PATH2 = "/mnt/DATA/MinhLong/MT-183/_2019/_HK192/OS/Labs/Lab2/main1";

int main(int argc, char** argv){
	pid_t  child_pid;
	child_pid = fork();

	char** new_argv = argv;
	char* new_envp = NULL;
	
	if (child_pid == 0){
		execve(PATH1, new_argv, new_envp);

	}
	else{
		execve(PATH2, new_argv, new_envp);
	}


	return 0;
}
