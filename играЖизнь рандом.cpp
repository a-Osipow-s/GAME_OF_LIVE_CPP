// игра∆изнь рандом.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>  
#include <random> 
using namespace std;

static const int width = 10, height = 10;
int world[width][height];

void RandomInit()
{
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(1,100);

		unsigned int i, j;

		for (i = 0; i < width; i++) {
			for (j = 0; j <height; j++) {
				unsigned int num = dis(gen);
				if (num % 2 == 0) {
					world[i][j] = 1;
				}
				else {
				    world[i][j] = 0;
				}
			}
		}
	}
}

int main()
 {
	 	 RandomInit();
	 
	 return 0;
 }