/*
 * View.h
 *
 *  Created on: 11 февр. 2022 г.
 *      Author: leshenya
 */

#include "FieldModel.h"
#ifndef SRC_VIEW_H_
#define SRC_VIEW_H_

class View {
public:
	View();
	virtual ~View();
	void render(FieldModel *model);
    void initWin();
    void detectWinSize();
    void closeWin();
    int getMaxX();
    int getMaxY();

private:
    int maxWidth;
    int maxHeight;
};

#endif /* SRC_VIEW_H_ */
