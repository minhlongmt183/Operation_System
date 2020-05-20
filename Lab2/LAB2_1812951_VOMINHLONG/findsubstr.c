#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_sub_string(const char *str, const char *sub){
	int strLength = strlen(str);
	int subLength = strlen(sub);
	
	if (subLength > strLength)
		return -1;
	
	
	int i,j, firstOcc = -1;
	char isFounded = 0;

	for (i = 0; i < strLength; ++i){
		if (str[i] == sub[0]){
			firstOcc = i;
			isFounded = 1;			


			for (j = 0; j < subLength; ++j){
	
				if (str[i + j] != sub[j]){
					isFounded = 0;
					break;
				}
			}
			
			if (isFounded != 0){
				return firstOcc;
			}
		}	
	}
	return -1;

}

