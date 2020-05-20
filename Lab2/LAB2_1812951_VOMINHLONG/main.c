// main.c
#include <stdio.h>
#include "readline.h"
#include "findsubstr.h"

const int SIZE =  100;

int main(int argc, char* argv[]){
	

	if (argc != 3){
		printf("Invalid argc\n");
		return(-1);
	}
	
	
	// 1. Read string of file
	FILE *inFile = fopen(argv[1], "r");
	if (inFile == NULL){
		printf("Error! Could not open file\n");
		return(-1);
	}

	char line[SIZE];
	
	while(fgets(line, 100, inFile) != NULL){
		if (find_sub_string(line, argv[2]) >= 0)
			printf("%s", line);
	}
	 
	return 0;

}
