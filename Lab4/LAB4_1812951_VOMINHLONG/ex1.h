#ifndef EX1_H
#define EX1_H

#include <stdio.h>
#include <stdlib.h>


	typedef struct blockInfo{
		int Size;
		int isFree;
		struct blockInfo* Next;
	} blockInfo;
	
	static blockInfo* head;
	static blockInfo* tail;

	void* aligned_malloc(unsigned int size, unsigned int align);
	void* aligned_free(void* ptr);

#endif 
