#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <curses.h>
#include <locale.h>
#include "display.h"
#include "input.h"
#include "memory.h"
#include "calculation.h"

int main(int argc, char **argv) {
	int alive = 1;
	char **cur, **buf, **temp;
	int x, y;
	int nb;
//	printf("Ширина:");
//	x = fetchIntFromUser();
//	if (x<=0){
//		printf("Не надо так 😭\n");
//		return 1;
//	}
//	printf("Высота:");
//	y = fetchIntFromUser();
//	if (y<=0){
//		printf("Не надо так 😭\n");
//		return 1;
//	}

	setlocale(LC_CTYPE,"");
	initscr();
	getmaxyx (stdscr, y, x);
	printf("%d %d \n", x, y);
	endwin();

	cur = mallocField(x, y);
	buf = mallocField(x, y);


	//mouse event
	getField(cur, x, y);
	initscr();
	printf("\n");
	curs_set(0);

	while (alive == 1) {
//		system("cls");
		alive = 0;
		printField(cur, x, y);

		for (int k = 0; k < y; k++) {
			for (int i = 0; i < x; i++) {
				nb = calcNb(cur, i, k, x, y);
				if (setPixel(cur, buf, i, k, nb) == 1) {
					alive = 1;
				}
			}
		}

		temp = cur;
		cur = buf;
		buf = temp;
		usleep(200000);
	}

	freeField(cur, y);
	freeField(buf, y);
	endwin();
//	for (int i = 0; i < 5; i++){
//		printf("%d", i % 3);
//		}
}

