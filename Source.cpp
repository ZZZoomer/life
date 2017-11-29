// Author: Mario Talevski
#include<iostream>
#include<cstdlib>
#include<windows.h>

using namespace std;

const int gridSize = 25;
void printGrid(bool gridOne[gridSize + 1][gridSize + 1]);
void determineState(bool gridOne[gridSize + 1][gridSize + 1]);

int main() {

	system("color A");
	bool gridOne[gridSize + 1][gridSize + 1] = {};
	int x, y, n;
	char start;
	cout << "                         THE GAME OF life - Implementation in C++" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Also known simply as life, " << endl;
	cout << "is a cellular automaton devised by the British mathematician John Horton Conway in 1970." << endl;
	cout << endl;
	cout << "Rules" << endl;
	cout << "The universe of the Game of life is an infinite two-dimensional orthogonal grid of square cells," << endl;
	cout << "each of which is in one of two possible states, life or dead. Every" << endl;
	cout << "cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent." << endl;
	cout << "At each step in time, the following transitions occur:" << endl;
	cout << "1. Any live cell with fewer than two live neighbours dies, as if caused by under-population." << endl;
	cout << "2. Any live cell with two or three live neighbours lives on to the next generation." << endl;
	cout << "3. Any live cell with more than three live neighbours dies, as if by over-population." << endl;
	cout << "4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction." << endl;
	cout << endl;
	cout << "O - living cell" << endl;
	cout << ". - dead cell" << endl;
	cout << endl;
	cout << "Enter the number of cells: ";
	cin >> n;
	
	for (int i = 0; i<n; i++)
	{
		cout << "Enter the coordinates of cell " << i + 1 << " : ";
		cin >> x >> y;
		gridOne[x][y] = true;
		printGrid(gridOne);
	}

	cout << "Grid setup is done. Start the game ? (y/n)" << endl;
	printGrid(gridOne);
	cin >> start;

	if (start == 'y' || 'Y')
	{
		while (true)
		{
			printGrid(gridOne);
			determineState(gridOne);
			Sleep(1000);
			system("CLS");
		}
	}
	else
	{
		return 0;
	}

}

void printGrid(bool gridOne[gridSize + 1][gridSize + 1]) {
	for (int a = 1; a < gridSize; a++)
	{
		for (int b = 1; b < gridSize; b++)
		{
			if (gridOne[a][b] == true)
			{
				cout << " O ";
			}
			else
			{
				cout << " . ";
			}
			if (b == gridSize - 1)
			{
				cout << endl;
			}
		}
	}
}

void compareGrid(bool gridOne[gridSize + 1][gridSize + 1], bool gridTwo[gridSize + 1][gridSize + 1]) {
	for (int a = 0; a < gridSize; a++)
	{
		for (int b = 0; b < gridSize; b++)
		{
			gridTwo[a][b] = gridOne[a][b];
		}
	}
}

void determineState(bool gridOne[gridSize + 1][gridSize + 1]) {
	bool gridTwo[gridSize + 1][gridSize + 1] = {};
	compareGrid(gridOne, gridTwo);

	for (int a = 1; a < gridSize; a++)
	{
		for (int b = 1; b < gridSize; b++)
		{
			int alive = 0;
			for (int c = -1; c < 2; c++)
			{
				for (int d = -1; d < 2; d++)
				{
					if (!(c == 0 && d == 0))
					{
						if (gridTwo[a + c][b + d])
						{
							++alive;
						}
					}
				}
			}
			if (alive < 2)
			{
				gridOne[a][b] = false;
			}
			else if (alive == 3)
			{
				gridOne[a][b] = true;
			}
			else if (alive > 3)
			{
				gridOne[a][b] = false;
			}
		}
	}
}
