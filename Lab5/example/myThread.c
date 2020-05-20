#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *myThreadFun(void *vargp){
	sleep(1);
	printf("param: %d\n", *((int*)vargp));
	printf("Printing hello\n");
	return 7;

}

int main(){
	pthread_t thread_id;
	printf("Before thread\n");
	int n = 5;
	pthread_create(&thread_id, NULL, myThreadFun, (void*)(&n));
	
	int ret;
	pthread_join(thread_id, &ret);
	printf("After thread: ret = %d\n", ret);

	return 0;
}
