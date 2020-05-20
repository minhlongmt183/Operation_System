#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


const int MAX_SIZE = 100;
const int MAX_NUM_LENGTH = 79;
int main(int argc, char** argv){
	if (argc != 2){
		perror("It must be have 2 arg\n");
		exit(-1);
	}

	// Read file and store to array
	FILE* file;
	file = fopen(argv[1], "r");

	char chrArr[MAX_SIZE][MAX_NUM_LENGTH];
	char number[MAX_NUM_LENGTH];

	int lengArr = 0, i, j;
	while(fgets(number,MAX_NUM_LENGTH, file) > 0){
		strncpy(chrArr[lengArr++], number, MAX_NUM_LENGTH);
	}
	fclose(file);


	// Count number
	pid_t pid1, pid2;
	pid1 = fork();

	if (pid1 == -1){
		perror("Fork Fail\n");
		exit(-1);
	}
	else if (pid1 == 0){
		//Child 1 div 2 == 0
		int NumOfIntDiv2 = 0;
		for (i = 0; i < lengArr; ++i){
			int NumLength = strlen(chrArr[i]);
			
			if((chrArr[i][NumLength-2] - '0') % 2 == 0)
				++NumOfIntDiv2;
		}
		printf("%d\n", NumOfIntDiv2);
	
	}
	else{
		// parent of child 1
		// wait child1 has done
		wait(NULL);

		// create child 2
		pid2 = fork();
		
		if (pid2 == -1){
			perror("Fork Fail!\n");
			exit(-1);
		}
		else if (pid2 == 0){
			// child 2

			int NumOfIntDiv3 = 0;
 			
			for (i = 0; i < lengArr; ++i){
				int NumLength = strlen(chrArr[i]);
				int SumOfChar = 0;
				
				for (j = 0; j < NumLength - 1; ++j)
					SumOfChar += chrArr[i][j] - '0';
			
				if(SumOfChar % 3 == 0)
					++NumOfIntDiv3;
			}

			printf("%d\n", NumOfIntDiv3);
		}
		else{
		//parent of Child 2
		// Wait for child 2 has done!
			wait(NULL);
		
			int NumOfIntDiv5 = 0;
		
			for (i = 0; i < lengArr; ++i){
				int NumLength = strlen(chrArr[i]);
			
				if((chrArr[i][NumLength-2] - '0') % 5 == 0)
					++NumOfIntDiv5;
			}

			printf("%d\n", NumOfIntDiv5);
		}
	}

	return 0;
}
