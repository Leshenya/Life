//
// Created by leshenya on 12.02.2022.
//

#include "Controller.h"

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
    cur = new FieldModel(view->getMaxX(), view->getMaxY());
    buf = new FieldModel(view->getMaxX(), view->getMaxY());
}


