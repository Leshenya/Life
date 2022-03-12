#include "FieldModel.h"
#include <stdio.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <curses.h>
#include <locale.h>
#include <cstring>
#include <exception>


FieldModel::FieldModel(int x, int y) {
	// TODO Auto-generated constructor stub
	width = x;
	height = y;
	field = (char**) malloc(height * sizeof(int*));
	for (int k = 0; k < height; k++) {
		field[k] = (char*) malloc(width * sizeof(int));
		memset((void*) field[k], (int) ' ', width);
	}

}

FieldModel::~FieldModel() {
	// TODO Auto-generated destructor stub
	for (int k = 0; k < height; k++) {
		free(field[k]);
	}
	free(field);
}

