/*
	Smith River CS222
	Creates the stack to store the QObj that will then be extracted from said stack to retrieve it's info.

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "Queue.h"
#include "LLN.h"
#include "QObj.h"
using namespace std;

Queue::Queue() { //Queue itself

	head = nullptr;
}

Queue::~Queue() { //Removes the Queue

	delete head;
}


void Queue::ENQUEUE(QObj* obj) { //Pushes the QObj onto the stack, adds the QObj to the end of the stack. FIFO

	if (!head) head = tail = new LLN(obj); //creates the pointer setup for the Q stack itself
	else {
		tail->setnext(new LLN(obj)); //adds the QObj as a LLN to the end of the stack then sets it as a tail.
		tail = tail->getnext();
	}
}

QObj* Queue::DEQUEUE() { //Pulls the QObj from the stack and returns it's object so that the info may be extracted.

	if (!head) return nullptr;
	QObj* obj = head->getinfo(); //gets the first object from the Q stack. FIFO
	LLN* t = head;
	head = head->getnext(); //changes the head to be the node after head.
	t->setnext(nullptr);
	t->setinfo(nullptr);
	delete t; //removes memory leak from temp LLNode
	return obj;
}

bool Queue::EMPTY() { //Makes the stack empty.

	return !head;
}