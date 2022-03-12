#include "View.h"
#include <curses.h>
#include <locale.h>

View::View() {
    maxWidth = 0;
    maxHeight = 0;
}

View::~View() {
}

void View::render(FieldModel *model) {
	clear();
	for (int k = 0; k < model->getHeight(); k++) {
		for (int i = 0; i < model->getWidth(); i++) {
			if (model->get(i, k) == ' ') {
				printw(" ");

			} else {
				printw("#");
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
    maxWidth--;
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