#include <pthread.h>
#include <stdio.h>

int sum;
void *runner (void *param);

int main(int argc, char *argv[]){
	pthread_t pid;
	pthread_attr_t attr;
	
	if (argc != 2){
		fprintf(stderr, "usage: a.out <interger value>\n");
		return -1;
	}

	if (atoi(argv[1]) < 0){
		fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
		return -1;
	}
	
	pthread_attr_init(&attr);
	pthread_create(&pid, &attr, runner, argv[1]);
	pthread_join(pid, NULL);
	
	printf("sum = %d\n", sum); 

	return 0;
}

void *runner (void *param){
	int i, upper = atoi(param);
	sum = 0;
	for (i = 1; i <= upper ; ++i)
		sum += i;
	pthread_exit(0);

}
