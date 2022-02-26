//
// Created by leshenya on 12.02.2022.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Controller.h"
#include "FieldModel.h"
#include "View.h"

Controller::Controller() {
    view = nullptr;
    cur = nullptr;
    buf = nullptr;
}

Controller::~Controller() {
    if (view != nullptr) {
        delete view;
        delete cur;
        delete buf;
    }
}

void Controller::init() {
    view = new View();
    view->initWin();
    view->detectWinSize();
    cur = new FieldModel(view->getMaxX(), view->getMaxY());
    buf = new FieldModel(view->getMaxX(), view->getMaxY());
}

void Controller::readFile(char *fileName) {
    char cell;
    int x = view->getMaxX();
    int y = view->getMaxY();
    //char *file = argv[0];

    printf("%s \n", fileName);
    std::ifstream inf(fileName);

    if (!inf) {
        std::cerr << "Uh oh, this file could not be opened for reading!" << std::endl;
        exit(1);
    }

    inf >> x;
    inf >> y;
    printf("%d %d \n", x, y);

    for (int i = 0; i < y; i++) {
        for (int k = 0; k < x; k++) {
            inf.get(cell);
            if (cell == ' ' || cell == '#') {
                printf("%c", cell);
                cur->set(k, i, cell);
            } else {
                k--;
            }
        }
        printf(".\n");
    }
}

int Controller::calcNb(int x, int y) {
    int nb = 0;
    int maxX = view->getMaxX();
    int maxY = view->getMaxY();
    for (int a = y - 1; a <= y + 1; a++) {
        for (int b = x - 1; b <= x + 1; b++) {
            if (a == y && b == x) {
                continue;
            }

            if (cur->get((b + maxX) % maxX, (a + maxY) % maxY) == '#') {
                nb++;
            }

        }
    }
    return nb;
}

int Controller::setPixel(int x, int y, int nb) {
    char c = buf->get(x, y);
    switch (nb) {
        case 3:
            buf->set(x, y, '#');
            break;
        case 2:
            buf->set(x, y, cur->get(x, y));
            break;
        default:
            buf->set(x, y, ' ');
    }
//	if (c==buf[y][x]){
//		return 0;
//	}
//	else{
//		return 1;
//	}
    return (c == buf->get(x, y)) ? 0 : 1;
}

int Controller::nextStep(){
    FieldModel *temp;
    int nb = 0;
    int alive = 0;
    int x = view->getMaxX();
    int y = view->getMaxY();
    view->render(cur);

    for (int k = 0; k < y; k++) {
        for (int i = 0; i < x; i++) {
            nb = calcNb(i, k);
            if (setPixel(i, k, nb) == 1) {
                alive = 1;
            }
        }
    }

    temp = cur;
    cur = buf;
    buf = temp;

    return alive;
}