#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

size_t size = 100;

int read_line (char *line){
	
	int numchar = 0;
	char ch;
	
	do{
		ch = fgetc (stdin);
	
		if (ch == '\n' || ch == EOF){
			line[numchar] = '\0';		
			return ch == '\n' ? numchar : -1;
		}

		line[numchar] = ch;
		++numchar;
		
	} while (1);
	

}
/*
int  main(){
	char line[100];
	int count = 0;
	while(count>=0){
		count=read_line(line);
		printf("%s: %d\n", line, count);
	}
	return 0;
}
*/
