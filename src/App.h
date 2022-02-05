/*
 * App.h
 *
 *  Created on: 29 янв. 2022 г.
 *      Author: leshenya
 */

#ifndef SRC_APP_H_
#define SRC_APP_H_

class App {
public:
	App();
	virtual ~App();
	void init();
	void run();

private:
	int x, y;
	char **cur, **buf;
};

#endif /* SRC_APP_H_ */
