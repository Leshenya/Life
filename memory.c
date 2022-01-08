#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <curses.h>

char** mallocField(int x, int y) {
	char **field;
	field = malloc(y * sizeof(int*));
	for (int k = 0; k < y; k++) {
		field[k] = malloc(x * sizeof(int));
	}

	//	field = malloc(y* sizeof(int *));
	//	field[0] = malloc (x*y*sizeof(int));
	//	for (int k = 1; k < y; k++) {
	//		field[k] = field[0] + (x*k);
	//	}

	return field;
}

void freeField(char **field, int y) {
	for (int k = 0; k < y; k++) {
		free(field[k]);
	}
	free(field);
}
