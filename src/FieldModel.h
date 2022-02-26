#ifndef SRC_FIELDMODEL_H_
#define SRC_FIELDMODEL_H_
#include <cstring>
#include <exception>
#include <cstdio>

class FieldModel {
public:
	FieldModel(int x, int y);
	virtual ~FieldModel();
	inline char get(int x, int y){
        if (x >= 0 && x < width && y >= 0 && y < height) {
            return field[y][x];
        } else {
            throw new std::exception();
        }
        return ' ';
    };
	inline void set(int x, int y, char cell){
        if (x >= 0 && x < width && y >= 0 && y < height) {
            field[y][x] = cell;
        } else {
            printf("%d %d %d %d \n", x, y, width, height);
            throw new std::exception();
        }
    };
	inline int getWidth(){
        return width;
    };
	inline int getHeight() {
        return height;
    };
private:
	char **field;
	int width, height;
};

#endif /* SRC_FIELDMODEL_H_ */
