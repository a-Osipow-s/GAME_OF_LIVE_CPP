
#include "pch.h"
#include <iostream>
#include <random>
#include <windows.h>
#define msleep(x) Sleep(x)

static const int GRID_SIZE =10;
using namespace std;
class GameofLife
{
private:
	bool Generation[GRID_SIZE][GRID_SIZE];
	bool cashGeneration[GRID_SIZE][GRID_SIZE];
public:
	
	void SetfirstGenerationRandomCells();
	void GetGeneration();
	int countNeighbors(int, int);
	int cmpGenerations();
	void processOfLife();
};

void GameofLife::SetfirstGenerationRandomCells()
{
	
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(1,100);

		unsigned int i, j;
		for (i = 0; i < GRID_SIZE; i++) {
			for (j = 0; j <GRID_SIZE; j++) {
				unsigned int num = dis(gen);
				if (num % 2 == 0) {
					Generation[i][j] = 1;
				}
				else {
					Generation[i][j] = 0;
				}
			}
		}
	
}

void GameofLife::GetGeneration()
{
	unsigned int i, j;
	
	for (i = 0; i < GRID_SIZE; i++) {
		for (j = 0; j < GRID_SIZE; j++) {
			if (Generation[i][j] == true) {
				cout << '*';
			}
			else {
				cout << '-';
			}
			cout << '|';
		}
		cout << endl;
	}
	
}
int GameofLife::countNeighbors(int x ,int y) {
	int count = 0;
	for (int dx = -1; dx < 2; dx++) {

		for (int dy = -1; dy < 2; dy++) 
		{
			
				int nX = x + dx;

				int nY = y + dy;
				
				if (nX < 0)  nX = GRID_SIZE - 1;

				if (nY < 0)  nY = GRID_SIZE - 1;

				if (nX > GRID_SIZE - 1) nX = 0;

				if (nY > GRID_SIZE - 1) nY = 0;


				if (Generation[nX][nY])
					count++;

		}
	}
		if (Generation[x][y])
			count--;
	return count;
}
	


int GameofLife::cmpGenerations()
{
	
	for (int x = 0; x < GRID_SIZE; x++) {
		for (int y = 0; y < GRID_SIZE; y++) {
			if (cashGeneration[x][y] != Generation[x][y]) {
				return -1;
			}
		}
	}
	
	return 0 ;
}
void GameofLife::processOfLife()
{
	bool nextGeneration[GRID_SIZE][GRID_SIZE];
		for (int x = 0; x < GRID_SIZE; x++) {
			for (int y = 0; y < GRID_SIZE; y++) {
				cashGeneration[x][y] = Generation[x][y];
				int count = countNeighbors(x, y);
				nextGeneration[x][y] = Generation[x][y];
				if ((count < 2) || (count > 3)) nextGeneration[x][y] = false;
				if (count == 3)  nextGeneration[x][y] = true;
				
			}
		}
		for (int x = 0; x < GRID_SIZE; x++) {
			for (int y = 0; y < GRID_SIZE; y++)
				Generation[x][y] = nextGeneration[x][y];
		}
		
}
 
 int main()
 {

	 GameofLife World;
	 World.SetfirstGenerationRandomCells();
	 World.GetGeneration();
	 system("cls");
	 int numbofitarations = 0;
	 while (true) {
	
		 World.processOfLife();
		 if (!World.cmpGenerations())break;
		 numbofitarations++;
		 World.GetGeneration();
		 msleep(150);
		 system("cls");
	 }

	 World.GetGeneration();
	 cout <<"Cycle of life has ended.Number of iterations:"<< numbofitarations << endl;
	 return 0;

 }