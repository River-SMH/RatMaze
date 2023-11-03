/*
	Smith River CS222
	file for LLN that stores the Maze QObj information into a node to allow the LL itself to act like a Queue if switched.

*/


#include <iostream>
#include <string>
#include <cstdlib>
#include "QObj.h"
#include "LLN.h"
using namespace std;

LLN::LLN(QObj* obj) {

	info = obj; //set node elements
	next = nullptr;
}

LLN::~LLN() {

	delete info; //deletes the elements in the node
	delete next;
}

QObj* LLN::getinfo() {

	return info;
}

void LLN::setinfo(QObj* obj) {

	info = obj; //puts the QOBj info into the LLN element
}

LLN* LLN::getnext() {

	return next;
}

void LLN::setnext(LLN* n) {

	next = n;
}