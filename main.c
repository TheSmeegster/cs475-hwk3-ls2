#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include "stack.h"
#include "ls2.h"

/**
 * Main function
 * Usage: ls2 <path> [exact-match-pattern]
 */
int main(int argc, char* argv[]) {

	// struct inputManager{
	// 	char inputPath[MAX_PATH];
	// 	char optionalInput[MAX_PATH];
	// };
	// struct inputManager userInput;

	if(argc < 2){
		printf("Usage: ./ls2 <path> [optional-file]\n");
	} else {
		readDIR(argv[1]);
		if(argc == 3){
			
		}
	}
	// char cwdPath[MAX_PATH];
	// getcwd(cwdPath, sizeof(cwdPath));
	// printf("%s", cwdPath);



	// stack stores the lines to print out
	stack_t *s = initstack();

	push(s, "Hello1");
	push(s, "Hello2");
	push(s, "Hello3");

	// print stack
	printstack(s);

	// free up stack
	freestack(s);
	return 0;
}
