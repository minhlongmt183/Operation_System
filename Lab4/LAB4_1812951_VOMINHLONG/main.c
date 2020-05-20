#include "ex1.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
	int i = 0;
	while(1){
		srand(time(0));
		long long a = rand() % 10 + 1;
		a = pow(2, a);
		void* p = aligned_malloc(16, a);
		
		if ((size_t)p % a != 0){
			printf("Error: %lx --- %d\n", p, a);
			exit(-1);
		}
		else{
			printf("Success: %lx --- %d\n", p, a);
		}
		
		aligned_free(p);
		i += 1;
		if (i == 1000000)
			break;

	}	
	return 0;
}
