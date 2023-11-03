/*
	Smith River CS222
	Header file for the Queue CPP to compile the Queue Code and allow object usage.

*/


#ifndef _QUEUE_
#define _QUEUE_

#include <iostream>
#include <string>
#include <cstdlib>
#include "LLN.h"
#include "QObj.h"
using namespace std;

class LLN;
class Queue {

private:
	LLN* head, * tail;
public:
	Queue();
	~Queue();
	void ENQUEUE(QObj* obj);
	QObj* DEQUEUE();
	bool EMPTY();
};
#endif