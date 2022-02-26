//
// Created by leshenya on 12.02.2022.
//

#ifndef LIFECPP_CONTROLLER_H
#define LIFECPP_CONTROLLER_H
#include "View.h"
#include "FieldModel.h"

class Controller {
public:
    Controller();
    virtual ~Controller();
    void init();
    void readFile(char *fileName);
    int calcNb(int x, int y);
    int setPixel(int x, int y, int nb);
    int nextStep();

private:
    View *view;
    FieldModel *cur;
    FieldModel *buf;
};


#endif //LIFECPP_CONTROLLER_H
// считалочка
// читалочка (из файла в модель с помощью FieldModel::set)
// для загрузки в модель использовать set, while не нужен (брать из test)
// добавить возможность ввода названия файла, из которого нужно читать