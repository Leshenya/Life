/*
 * App.h
 *
 *  Created on: 29 янв. 2022 г.
 *      Author: leshenya
 */

#ifndef SRC_APP_H_
#define SRC_APP_H_
#include "Controller.h"

class App {
public:
	App();
	virtual ~App();
    void init(int argc, char **argv);
    void init();
	void run();

private:
	int x, y;
	char **cur, **buf;
    Controller controller;
};

#endif /* SRC_APP_H_ */
