#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <time.h>
#include <stdlib.h>
#include <vector>


class Draw
{
private: //initialize variables only for this class
	int x;
	int y;
	int delaycounter;

public:
	bool damage;
	int score;

	Draw()
	{
		//Default Constructor
		x = 10;
		y = 10;
		score = 100;
		delaycounter = 0;
		damage = false;
	}

	Draw(int x,int y)
	{
		this->x = x;
		this->y = y;
		score = 100;
		damage = false;
	}

	//Getters and setters to allow access the variable outside the class scope, as variables are private:

	void setDrawPoint(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	
	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}


	//Declaring the function is the header file, these will later be coded int he Draw.cpp file!

	void draw(char character );

	void drawShip();

	void deleteOldDrawingOfShip(int x, int y);

	void drawEnemy(const char arrayOne[5]);

	void drawEnemyAtLocation(int indexLocation, int delayTime, int& location, bool flag);

	void deleteOldEnemy();
	
	void deleteOldEnemyAt(int x, int y);

	void drawShipScore();
	
	void currentLevel(int startingLevel);

	void deleteSingleCharacter();
	
	void deleteSingleCharacter(int x, int y);
};

