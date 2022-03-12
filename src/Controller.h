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
