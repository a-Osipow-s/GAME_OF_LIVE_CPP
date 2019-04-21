
#include "pch.h"
#include <iostream>
#include <random>

using namespace std;
static const int GRID_SIZE = 10;
bool firstGeneration[GRID_SIZE][GRID_SIZE];

bool cashGeneration[GRID_SIZE][GRID_SIZE];


void FillRandomCellsButton()
{
	{
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(1,110);

		unsigned int i, j;

		for (i = 0; i < GRID_SIZE; i++) {
			for (j = 0; j <GRID_SIZE; j++) {
				unsigned int num = dis(gen);
				if (num % 2 == 0) {
					firstGeneration[i][j] = 1;
				}
				else {
				    firstGeneration[i][j] = 0;
				}
			}
		}
	}
}
void outputGrid(bool generationarr[GRID_SIZE][GRID_SIZE])
{
	unsigned int i, j;
	
	
	for (i = 0; i < GRID_SIZE; i++) {
		for (j = 0; j < GRID_SIZE; j++) {
			if (generationarr[i][j] == true) {
				cout << '*';
			}
			else {
				cout << '-';
			}
			cout << '|';
		}
		cout << endl;
	}
	cout << "#########################################################################" << endl;
}
int countNeighbors(int x ,int y, bool generationarr[GRID_SIZE][GRID_SIZE]) {
	int count = 0;
	
			

	

		for (int dx = -1; dx < 2; dx++) {

			for (int dy = -1; dy < 2; dy++) {

				int nX = x + dx;

				int nY = y + dy;

				if (nX < 0)  continue;

				if (nY < 0)  continue;

				if (nX > GRID_SIZE - 1) continue;

				if (nY > GRID_SIZE - 1) continue;


				if (generationarr[nX][nY])
					count++;

			}
		}
		if (generationarr[x][y])
			count--;

	

				
			
	return count;
}
	

int cmp_world(bool cashgenerationarr[GRID_SIZE][GRID_SIZE], bool generationarr[GRID_SIZE][GRID_SIZE])
{
	
	for (int x = 0; x < GRID_SIZE; x++) {
		for (int y = 0; y < GRID_SIZE; y++) {
			if (cashgenerationarr[x][y] != generationarr[x][y]) {
				return -1;
			}
		}
	}
	int num = 0;
	return num++ ;
}
void processOfLife(bool generationarr[GRID_SIZE][GRID_SIZE], bool cashgenerationarr[GRID_SIZE][GRID_SIZE])
{
	bool nextGeneration[GRID_SIZE][GRID_SIZE];
		for (int x = 0; x < GRID_SIZE; x++) {
			for (int y = 0; y < GRID_SIZE; y++) {
				cashgenerationarr[x][y] = generationarr[x][y];
				int count = countNeighbors(x, y,generationarr);
				nextGeneration[x][y] = generationarr[x][y];
				if ((count < 2) || (count > 3)) nextGeneration[x][y] = false;
				if (count == 3)  nextGeneration[x][y] = true;
				generationarr[x][y] = nextGeneration[x][y];
			}
		}
		
		
}
 
 int main()
 {
	 int numbofitarations = 0;
	 FillRandomCellsButton();
	 outputGrid(firstGeneration);
	 processOfLife(firstGeneration, cashGeneration);
	 outputGrid(firstGeneration);
	 while (cmp_world(firstGeneration,cashGeneration)) {
		 
		 numbofitarations++;
		 processOfLife(firstGeneration,cashGeneration);
		 outputGrid(firstGeneration);
	 }
	 cout <<"Cycle of life has ended.Number of iterations:"<< numbofitarations-1 << endl;
	
	  

	 
	
	
	 return 0;

 }