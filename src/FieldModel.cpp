#include "FieldModel.h"
#include <stdio.h>
#include <stdlib.h>
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

inline void FieldModel::set(int x, int y, char cell) {
	if (x >= 0 && x < width && y >= 0 && y < height) {
		field[y][x] = cell;
	} else {
		throw new std::exception();
	}
}

inline char FieldModel::get(int x, int y) {
	if (x >= 0 && x < width && y >= 0 && y < height) {
		return field[y][x];
	} else {
		throw new std::exception();
	}
	return ' ';
}

inline int FieldModel::getWidth(){
	return width;
}
inline int FieldModel::getHeigh(){
	return height;
}

