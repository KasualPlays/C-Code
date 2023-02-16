#include "Draw.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "AsteroidGame.h"

AsteroidGame asteroidGame;


//Creating a draw function to draw to the screen when only one character needs to be drawn ~

void Draw::draw(char character = 'O')
{
	asteroidGame.findPositionX(x, y);
	cout << character << endl;
}

void Draw::drawShip()
{
	//Go to each position on the board and print out the characters at that locations ~
	
	//top line ~
	asteroidGame.findPositionX(x, y);
	cout << '/' << '\\';

	//2nd line ~
	asteroidGame.findPositionX(x - 1, y + 1);
	cout << "(  " << ')';

	//3rd line ~
	asteroidGame.findPositionX(x - 2, y + 2);
	cout << " (  " <<')' << endl;
	
	//4th line ~
	asteroidGame.findPositionX(x - 3, y + 3);
	cout << " /|/" << "\\|\\" << endl;
	
	

}

void Draw::deleteOldDrawingOfShip(int x, int y)
{
	//Delete the old version of the ship, when the player moves left or right, to avoid having two copies at one time ~

	//replace each previous line with a blank space, essentially deleting it ~
	asteroidGame.findPositionX(x, y);
	cout << " " << " ";

	//2nd line ~
	asteroidGame.findPositionX(x - 1, y + 1);
	cout << "   " << " ";

	//3rd line ~
	asteroidGame.findPositionX(x - 2, y + 2);
	cout << "    " << " " << endl;

	//4th line ~
	asteroidGame.findPositionX(x - 3, y + 3);
	cout << "    " << "   " << endl;

}

void Draw :: drawEnemy(const char arrayOne[5] = "OOOOO")
{
	asteroidGame.findPositionX(x -1 , y);
	cout << arrayOne;
}

/*
we need to create a method to spawn in multiple enemies, but set up a delay so that they dont all spawn at the same time
but in intervals, this can be done with a delay variable, and then we need to spawn new enemies in when one reaches the bottom
*/

void Draw::drawEnemyAtLocation(int i, int delay, int& location, bool redo = true)
{
	if (i < delay && this->delaycounter == 0) return;
	if (i == delay) this->delaycounter = 0;
	if (redo == false && this->delaycounter == 0) {
		this->setDrawPoint(location, 0);
		return;
	}


	this->setDrawPoint(location, this->delaycounter);


	this->drawEnemy();
	this->deleteOldEnemy();
	

	this->delaycounter += 1;

	if (this->delaycounter == 29 && delay != 0) {
		this->delaycounter = 0;
		this->deleteOldEnemyAt(this->getX(), this->getY());
		location = rand() % 3;
		if (location == 0) { location = 50; }
		if (location == 1) { location = 60; }
		if (location == 2) { location = 70; }

	}

}

void Draw :: deleteOldEnemy()
{
	asteroidGame.findPositionX(x - 1, y - 1);
	cout << "     ";  //constantly deletes as they move down the screen, to create illusion of moving!
	
	if (this->getY() == 28)
	{
		asteroidGame.findPositionX(x - 1, 28);
		cout << "     ";
	}
}

void Draw::deleteOldEnemyAt(int x, int y)
{
	asteroidGame.findPositionX(x, y);
	cout << "     ";
}

void Draw :: drawShipScore()
{
	asteroidGame.findPositionX(20, 14); //Draw at these coordinates, on the screen
	cout << "Current Score: " << score << endl;
}

void Draw::currentLevel(int startingLevel)
{
	asteroidGame.findPositionX(20, 13);
	cout << "Current Level: " << startingLevel << endl;
}

//Setup two delete functions for the single characters to ~

void Draw :: deleteSingleCharacter()
{
	asteroidGame.findPositionX(x, y);
	cout << " ";
}

//Second, OVERLOADED, function

void Draw::deleteSingleCharacter(int x, int y)
{
	asteroidGame.findPositionX(x, y);
	cout << " " << " " << " " << endl;
}