#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <curses.h>

char fetchCharFromUser() {
	char cell;

	do {
//		read(0, &cell, 1);
		scanf("%c", &cell);
	} while (cell != '#' && cell != ' ');

	return cell;
}

int fetchIntFromUser() {
	int number;
	scanf("%d", &number);
	return number;
}

void getField(char **field, int x, int y) {
	for (int k = 0; k < y; k++) {
		for (int i = 0; i < x; i++) {
			field[k][i] = fetchCharFromUser();
		}
	}
}

