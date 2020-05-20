#include <stdio.h>
#include <stdlib.h>

void *aligned_malloc(size_t bytes, size_t alignment){
	void *p1;
	void *p2;

	size_t offset = alignment - 1 + sizeof(void*);
	if ((p1 = (void *) malloc(bytes + offset)) == NULL)
		return NULL;
	
	size_t addr = (size_t)p1 + offset;

	p2 = (void *)(addr  - addr % alignment);

	*((size_t *)p2-1) = (size_t)p1;

	return p2;
}

void aligned_free(void *p){
	free((void*)(*((size_t *)p-1)));
}

int main(int argc, char ** argv){
	

	int * p1 = aligned_malloc(16, 64);

	printf("%p\n", p1);

	aligned_free(p1);
	
	return 0;
}
