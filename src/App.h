#ifndef SRC_APP_H_
#define SRC_APP_H_
#include "Controller.h"

class App {
public:
	App();
	virtual ~App();
    void init(int argc, char **argv);
	void run();

private:
    Controller controller;
};

#endif /* SRC_APP_H_ */
