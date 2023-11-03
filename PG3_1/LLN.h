/*
	Smith River CS222
	Header file for LLN to allow the data from the maze to be placed into a node.

*/


#ifndef _LLN_
#define _LLN_

#include <iostream>
#include <string>
#include <cstdlib>
#include "QObj.h"
using namespace std;

class QObj;
class LLN {

private:
	QObj* info;
	LLN* next;
public:
	LLN(QObj* obj);
	~LLN();
	LLN* getnext();
	QObj* getinfo();
	void setnext(LLN* n);
	void setinfo(QObj* obj);
};




#endif