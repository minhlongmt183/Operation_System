#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define NUM_THREADS  3
int totalPoint;
int numPoints = 0;
pthread_t threads[NUM_THREADS];
pthread_mutex_t lock;

void *CalPI(void* param){

	float x, y;
	int i;
	int tid = (int)param;

	int numCount = totalPoint / NUM_THREADS;
	unsigned int seed = rand() % 30000;
	
	pthread_mutex_lock(&lock);
	for (i = 0; i < numCount; ++i){
		x = ((float)rand_r(&seed) / RAND_MAX); 	
		y = ((float)rand_r(&seed) / RAND_MAX); 
		if (x*x + y*y <= 1)
			numPoints += 1;
	}
	
	if (tid == 0){
		int remainder = totalPoint % NUM_THREADS;

		for (i = 0; i < remainder; ++i){
			x = ((float)rand_r(&seed) / RAND_MAX); 	
			y = ((float)rand_r(&seed) / RAND_MAX); 	
			if (x*x + y*y <= 1)
				numPoints += 1;
		}
		

	}
	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
}

int main(int argc, char *argv[]){
	if (argc != 2){
		fprintf(stderr, "usage: ./pi_multi-thread [number]\n");
		return -1;
	}
	
	totalPoint = atoi(argv[1]);

	if (totalPoint <= 0){
		fprintf(stderr, "%d must be > 0\n", totalPoint);
		return -1;
	}


	int i;

	for (i = 0; i < NUM_THREADS; ++i){
		pthread_create(&threads[i], NULL, CalPI, (void*)i);
	}

	for (i = 0; i < NUM_THREADS; ++i){
		pthread_join(threads[i], NULL);
	}
	
	printf("pi = %lf\n", 4 *((float)numPoints / totalPoint));


	pthread_exit(NULL);

}


