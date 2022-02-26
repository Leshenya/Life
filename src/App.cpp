#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <curses.h>
#include <locale.h>

extern "C" {
#include "../display.h"
#include "../input.h"
#include "../memory.h"
#include "../calculation.h"
}

#include "App.h"
#include "Controller.h"

App::App() {
    x = 0;
    y = 0;
    cur = nullptr;
    buf = nullptr;
}

App::~App() {
    // TODO очистить память
    freeField(cur, y);
    freeField(buf, y);
}

void App::init() {

}

void App::init(int argc, char **argv) {
    setlocale(LC_CTYPE, "");
    initscr();
    getmaxyx(stdscr, y, x);
    printf("%d %d \n", x, y);
    endwin();

    controller.init();
    if (argc < 1) {
        printf("Нет загрузочного файла \n");
    } else {
        controller.readFile(argv[1]);
    }

    cur = mallocField(x, y);
    buf = mallocField(x, y);
}

void App::run() {
    int alive = 1;
    char **temp;
    int nb;
    //mouse event
    //getField(cur, x, y);
//    initscr();
//    printf("\n");
//    curs_set(0);

    while (alive == 1) {
//		system("cls");
//        alive = 0;
//        printField(cur, x, y);
//
//        for (int k = 0; k < y; k++) {
//            for (int i = 0; i < x; i++) {
//                nb = calcNb(cur, i, k, x, y);
//                if (setPixel(cur, buf, i, k, nb) == 1) {
//                    alive = 1;
//                }
//            }
//        }
//
//        temp = cur;
//        cur = buf;
//        buf = temp;
        alive = controller.nextStep();
        usleep(200000);
    }
sleep(3);
    endwin();

//	for (int i = 0; i < 5; i++){
//		printf("%d", i % 3);
//		}

}
