#ifndef SRC_FIELDMODEL_H_
#define SRC_FIELDMODEL_H_

class FieldModel {
public:
	FieldModel(int x, int y);
	virtual ~FieldModel();
	inline char get(int x, int y);
	inline void set(int x, int y, char cell);
private:
	char **field;
	int width, height;
};

#endif /* SRC_FIELDMODEL_H_ */
