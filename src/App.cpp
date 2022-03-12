#include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include "App.h"

App::App() {
}

App::~App() {
}

void App::init(int argc, char **argv) {
    setlocale(LC_CTYPE, "");

    controller.init();
    if (argc < 1) {
        printf("Нет загрузочного файла \n");
    } else {
        controller.readFile(argv[1]);
    }

}

void App::run() {
    int alive = 1;
    while (alive == 1) {
        alive = controller.nextStep();
        usleep(150000);
    }
}
