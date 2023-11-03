/*
	Smith River CS222
	Header file for the QObj to allow the data fields of the Maze,rows,columns,x position, and y position to compile and be used to solve.

*/

#ifndef _QOBJ_
#define _QOBJ_

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class QObj {

private:
	int r, c, x, y;
	char** M;
public:
	QObj(int R, int C, char** MZ,int posx,int posy);
	~QObj();
	int getr();
	int getc();
	int getx();
	int gety();
	char** getM();
};
#endif