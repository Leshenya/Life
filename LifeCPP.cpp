#include "src/App.h"

int main(int argc, char **argv) {
	App app;
	app.init(argc, argv);
	app.run();
	return 0;
}
