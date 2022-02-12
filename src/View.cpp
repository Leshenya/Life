/*
 * View.cpp
 *
 *  Created on: 11 февр. 2022 г.
 *      Author: leshenya
 */

#include "View.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <curses.h>
#include <locale.h>
#include <cstring>
#include <exception>

View::View() {
	// TODO Auto-generated constructor stub
    maxWidth = 0;
    maxHeight = 0;
}

View::~View() {
	// TODO Auto-generated destructor stub
}

void View::render(FieldModel *model) {
	clear();
	for (int k = 0; k < model->getHeigh(); k++) {
		for (int i = 0; i < model->getWidth(); i++) {
			if (model->get(i, k) == ' ') {
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

void View::initWin(){
    setlocale(LC_CTYPE,"");
    initscr();
    curs_set(0);
}
void View::detectWinSize(){
    getmaxyx (stdscr, maxHeight, maxWidth);
}
int View::getMaxX(){
    return maxWidth;
}
int View::getMaxY(){
    return maxHeight;
}
void View::closeWin(){
    endwin();
}