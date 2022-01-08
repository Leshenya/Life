#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <curses.h>

int calcNb(char **cur, int x, int y, int maxX, int maxY) {
	int nb = 0;
	for (int a = y - 1; a <= y + 1; a++) {
		for (int b = x - 1; b <= x + 1; b++) {
			if (a == y && b == x) {
				continue;
			}

			if (cur[(a + maxY) % maxY][(b + maxX) % maxX] == '#') {
				nb++;
			}

		}
	}
	return nb;
}

int setPixel(char **cur, char **buf, int x, int y, int nb) {
	char c = buf[y][x];
	switch (nb) {
	case 3:
		buf[y][x] = '#';
		break;
	case 2:
		buf[y][x] = cur[y][x];
		break;
	default:
		buf[y][x] = ' ';
	}
//	if (c==buf[y][x]){
//		return 0;
//	}
//	else{
//		return 1;
//	}
	return (c == buf[y][x]) ? 0 : 1;
}

//#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

