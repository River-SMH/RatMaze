/*
	Smith River CS222
	Header file for PG3 that compiles the methods that create the maze and solve it.

*/

#ifndef _PG3_
#define _PG3_

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv);
void GetMaze(int r, int c);
void DisposeMaze();
void PrintMaze(char** M,int r,int c);
int height();
int width();

bool Solve(int r, int c, int condx, int condy, char** tmpMaze);
#endif