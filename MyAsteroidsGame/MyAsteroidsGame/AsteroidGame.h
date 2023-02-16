#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
using namespace std;


class AsteroidGame
{
public:
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPosition;

	void setCursor(bool visible, DWORD size);
	
	void menuStartingScreen();

	void menuGameOverScreen(vector<int>& scoreList, vector<string>& namelist, int newScore);


	void findPositionX(int x, int y);

	void pauseGame();

	void unPauseGame();
	
};

