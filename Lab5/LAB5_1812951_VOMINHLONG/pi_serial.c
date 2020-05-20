#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(int argc, char *argv[]){	

	if (argc < 2){
		fprintf(stderr, "usage ./pi_serial [integer]\n");
		return -1;
	}

	int numOfPoint = atoi(argv[1]);
	if (numOfPoint < 0){
		fprintf(stderr, "%d must be >= 0\n", numOfPoint);
		return -1;
	}

	int i;
	float  x, y;
	int seed = time(NULL);
	int num = 0;


	for (i = 0; i < numOfPoint; ++i){
		x =   (float)rand_r(&seed) / RAND_MAX ;
		y =   (float)rand_r(&seed) / RAND_MAX ;
	
		if (x*x + y*y <= 1)
			++num;
	} 
	
	printf("pi = %lf\n", 4 * ((float)num / atoi(argv[1])));
	
	return 0;
}
