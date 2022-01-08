#include <curses.h>

void printField(char **field, int x, int y) {
//	printf("----------------------------------------\n");
	clear();
	for (int k = 0; k < y; k++) {
		for (int i = 0; i < x; i++) {
			if (field[k][i] == ' ') {
				printw(" ");

			} else {
				//printw("😛");//👻
				printw("#");
				//rand();

			}
		}
		printw("\n");
	}
	refresh();
}
