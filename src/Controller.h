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

private:
    View *view;
    FieldModel *cur;
    FieldModel *buf;
};


#endif //LIFECPP_CONTROLLER_H
// счеталочка
// читалочка (из файла в модель с помощью FieldModel::set)
// для загрузки в модель использовать set, while не нужен (брать из test)