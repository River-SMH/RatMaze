/*
	Smith River CS222
	Creates an object that holds a 2d char Maze that includes width and height and the last position known in the maze.
	Makes it an object to allow to be pushed and pulled from the stack from Queue.

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "QObj.h"
#include "PG3.h"
using namespace std;

QObj::QObj(int R, int C, char** MZ,int posx, int posy) { //Takes in the maze with its size and last 'X' position on the 2d char array.

	x = posx; //last known position from the last Maze move.
	y = posy;

	r = R;
	c = C;
	M = new char* [height()];
	for (int i = 0; i < height(); i++) { //puts the Maze 2d char array into the QObj
		M[i] = new char[width()];
		for (int j = 0; j < width(); j++)
			M[i][j] = MZ[i][j];
	}

}

QObj::~QObj() { //Removes the obj to avoid memory leaks.

	for (int i = 0; i < height(); i++)
		delete M[i]; //deletes the 2d char array element
	delete M; //deletes the 2d array
}

int QObj::getr() { //gets the rows from the object.

	return r;
}

int QObj::getx() { //gets the x position from the object of last known 'X'
	return x;
}

int QObj::gety() { //gets the y position from the object of last known 'X'
	return y;
}

int QObj::getc() { //gets the columns from the object.

	return c;
}

char** QObj::getM() { //gets the maze itself

	return M;
}
