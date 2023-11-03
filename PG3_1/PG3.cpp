/*
	Smith River CS222
	Creates the Maze and then solves it using QObj to get info and Queue to store each object.

*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "PG3.h"
#include "QObj.h"
#include "Queue.h"
using namespace std;

char** Maze; //global Maze variable to allow easy access to manipulate and delete
int w, h;
Queue* Q; //global Queue object to allow anywhere in this file to access the Queue and manipulate it as seen fit.
QObj* obj; //global queue object object to have info stored from the queue to be accessed.

int main(int argc, char** argv) {

	int r, c; //var to store rows and columns

	cout << "Enter the amount of columns: ";
	cin >> c;
	cin.ignore();
	cout << "Enter the amount of rows: "; //Creates the boundries for the maze
	cin >> r;
	cin.ignore();
	

	Q = new Queue();

	GetMaze(r, c); //creates the maze based from user input

	Q->ENQUEUE(obj); //after maze has been made Enqueue it to the stack so it isn't empty

	while (true) { //Loop to check every possible move. If there is a move make Move and Enqueue it. Then Dequeue it to receive it's info
		obj = Q->DEQUEUE();
		Maze = obj->getM();
		int x = obj->getx(); //gets the cords of last known 'X' position
		int y = obj->gety();

		if (Solve(r, c, x - 1, y, Maze) == true) break; //checks north,south,west,and east positions for possible moves.
		if (Solve(r, c, x + 1, y, Maze) == true) break;
		if (Solve(r, c, x, y - 1, Maze) == true) break;
		if (Solve(r, c, x, y + 1, Maze) == true) break;
		DisposeMaze(); //deletes the maze after all moves have been attempted

	}
	while (!Q->EMPTY()) { //after maze has reached the end dequeue the entire stack
		Q->DEQUEUE();
	}
	delete Q; //once Q no longer has QObjs, set to empty.
	return 0;

}

void GetMaze(int r, int c) { //Creates the Maze based on the user input
	h = r;
	w = c;
	string line;
	cout << "Enter maze:" << endl;
	char** M = new char* [r]; //maze 2d char array
	for (int i = 0; i < r; i++) { //loop to go through every column and row
		M[i] = new char[c];
		getline(cin, line); 
		for (int x = 0; x < c; x++) {
			M[i][x] = line[x]; //inputs the data into the specific field for the maze
		}

	}
	Maze = M; //change global maze var to new created maze
	Maze[0][0] = 'X'; //Maze will always start in top left corner therefore first move is always at [0][0]
	obj = new QObj(r, c, Maze, 0, 0); //Creates the object with the Maze inside with [0][0] as its starting/last known 'X' position
	

}

void DisposeMaze() { //deletes the maze

	for (int i = 0; i < h; i++)
		delete[] Maze[i]; //deletes info
	delete[] Maze; //deletes the 2d array
}

void PrintMaze(char** M,int r,int c) { //Prints the maze

	for (int i = 0; i < r; i++) {
		for (int x = 0; x < c; x++) {
			cout << M[i][x]; //goes through every piece of info and prints it out
		}
		cout << endl;
	}
}

int height() { //Gets the Y dimension

	return h;
}

int width() { //Gets the X dimension

	return w;
}

bool Solve(int r, int c, int condx, int condy, char** tmpMaze) { //Takes the size of the maze, possible moves to make from 'X' position, and the Maze itself
	if (condx >= 0 && condx < r && condy >= 0 && condy < c) { //Ensures that the x-1 or y-1 / any movement is within the bounds of the Maze.
		if (tmpMaze[condx][condy] == '*' || tmpMaze[condx][condy] == 'X') { //If the movement lands on a * or X invalid move return from this method.
			return false;
		}
		else {
			tmpMaze[condx][condy] = 'X'; //if it doesn't hit and barriers place move.
			QObj* tmpObj = new QObj(r, c, tmpMaze, condx, condy); //new object to enqueue and not override any info from the original object.
			if (condx == r - 1 && condy == c - 1) { //checks to see if its at the end of Maze
				PrintMaze(tmpMaze, r, c);
				cout << "Shortest Solved Maze" << endl; //if it is at end print and return true.
				return true;
			}
			Q->ENQUEUE(tmpObj); //if not at end of maze Enqeue this Maze and undo the movement to ensure that the movement isn't updated to the rest of the move sets to be made.
			tmpMaze[condx][condy] = ' ';
		}
	}
	return false;
}

