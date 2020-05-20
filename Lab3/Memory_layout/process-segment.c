#include <stdio.h>
#include <stdlib.h>
int global_f = 10;
int func(){
	return 0;
}

int main(){
	int local_f = 100;
	int *dynamic_f = (int*)malloc(sizeof(int));

	printf("global_f:	%p\n", &global_f);
	printf("local_f:	%p\n", &local_f);
	printf("func:		%p\n", &func);
	printf("dynamic_f:	%p\n", dynamic_f);
sleep(1000);
}
