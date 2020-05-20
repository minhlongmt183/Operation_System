#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void* simple_malloc(size_t size){
	void *p1, *p2;
	p1 = sbrk(0);
	printf("sbrk(0): %p\n", p1);
	
	if ((p2 = sbrk(size)) == (void *)-1)
		return NULL;

	printf("sbrk(0): %p\n", p1);
	printf("sbrk(size): %p\n", p2);
	p2 = sbrk(size); 
	printf("sbrk(size): %p\n", p2);
	p2 = sbrk(0); 
	printf("sbrk(size): %p\n", p2);
	p2 = sbrk(0); 
	printf("sbrk(size): %p\n", p2);

	return p1;
}

int main(int argc, char** argv){
	simple_malloc(16);
	return 0;
}
