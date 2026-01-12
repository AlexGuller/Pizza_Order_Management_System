#include <stdio.h>
#include <stdlib.h>
#include "project3.h"

char *get_item(){
  // Allocate memory for the ingredient name.
	char *item = malloc(61 * sizeof(char));
	if(item == NULL){
		printf("Memory allocation failed...");
		exit(1);
	}

	// Scan the ingredient stopping at each new line(because thats how the program set up.
	int ch = getchar();
	int count = 0;
	while(ch != '\n'){
		*(item + count) = (char)ch;
		count++;
		ch = getchar();
	}
	*(item + count) = '\0';

	// Return the ingredient.
	return item;
}
