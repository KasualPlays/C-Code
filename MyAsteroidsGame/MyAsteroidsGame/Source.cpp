#include <iostream>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "AsteroidGame.h"
#include "Draw.h"
#include "GameLogic.h"

using namespace std;



Draw drawingGame;
GameLogic ship;
AsteroidGame asteroidGameInstance;


int main()
{

	vector<int> scores = { 60000,50000,40000,50,0 };
	vector<string> names = { "Sally", "Leo","Rigby","Ben","Brandon" };

MAINMENU:
	//We can declare all the objects we need here this way we can easily access them in the gameLogic.cpp file ~

	//Declaring all the objects to creat the playable board, via columns:
	Draw leftColumn;
	Draw middleColumnLeft;
	Draw middleColumnRight;
	Draw rightColumn;

	//Declaring the types of enemies to allow us to spawn multiple:
	Draw enemyOne;
	Draw enemyTwo;
	Draw enemyThree;
	Draw enemyFour;
	Draw enemyFive;
	bool show = true;

	//Our UI elements:
	Draw score;

	//We need to set the initial starting point of the ship when beginning the game:
	Draw ship;
	ship.setDrawPoint(60, 25);

	//Start the game on lowest difficutly:
	int gameDifficulty = 1;
	int speed = 100;
	int scoreMultiplier = 2;

	//Create characters to read keyboard input and begin the game:

	char op = ' ';
	char restartGame;

	//Initialise the X positions for the gameBoard:
	int firstRowNumber = 50;
	int secondRowNumber = 60;
	int thirdRowNumber = 70;
	int fourthRowNumber = 70;
	int fifthRowNumber = 70;

	//Initialise the delay for each of the enemies:
	int enemyDelayOne = 0;
	int enemyDelayTwo = 6;
	int enemyDealyThree = 12;
	int enemyDelayFour = 18;
	int enemyDelayFive = 24;

	//Keep track of the y location for the oncoming enemies:
	int i = 0;
	int j = 0;

	//Add counter for the level to increase game difficulty:
	int level = 1;

	//Move the cursor away from the game into the corner to avoid errors:
	asteroidGameInstance.setCursor(0, 0);


	//start screen time;

	asteroidGameInstance.menuStartingScreen();

	while (_getch() != ' '){
	}
	system("cls");
	Draw pauseGame;

	while (true){
		
		if (i == 29){
			
			i = 0;
			j += 1;
			firstRowNumber = ship.getX();


			if (j >= 0){
				gameDifficulty = 2;
			}

			if (j >= 30){
				gameDifficulty = 3;
			}

			if (j >= 70){
				gameDifficulty = 4;
			}

			if (j >= 110){
				gameDifficulty = 5;
			}
		}



		ship.score += scoreMultiplier;
		ship.drawShipScore();
		ship.currentLevel(level);

		//check to see if its time to increase the level difficulty:

		bool show = true;

		if (gameDifficulty == 1)
		{
			enemyOne.drawEnemyAtLocation(i, enemyDelayOne, firstRowNumber, show);


		}

		else if (gameDifficulty == 2)
		{
			enemyOne.drawEnemyAtLocation(i, enemyDelayOne, firstRowNumber, show);
			enemyTwo.drawEnemyAtLocation(i, enemyDelayTwo, secondRowNumber, show);

		}

		else if (gameDifficulty == 3)
		{
			enemyOne.drawEnemyAtLocation(i, enemyDelayOne, firstRowNumber, show);
			enemyTwo.drawEnemyAtLocation(i, enemyDelayTwo, secondRowNumber, show);
			enemyThree.drawEnemyAtLocation(i, enemyDealyThree, thirdRowNumber, show);

		}

		else if (gameDifficulty == 4)
		{
			enemyOne.drawEnemyAtLocation(i, enemyDelayOne, firstRowNumber, show);  //
			enemyTwo.drawEnemyAtLocation(i, enemyDelayTwo, secondRowNumber, show);
			enemyThree.drawEnemyAtLocation(i, enemyDealyThree, thirdRowNumber, show);
			enemyFour.drawEnemyAtLocation(i, enemyDelayFour, fourthRowNumber, show);


		}

		else if (gameDifficulty == 5);
		{
			//enemyOne.drawEnemyAtLocation(i, enemyDelayOne, firstRowNumber, show);
			//enemyTwo.drawEnemyAtLocation(i, enemyDelayTwo, secondRowNumber, show);
			//enemyThree.drawEnemyAtLocation(i, enemyDealyThree, thirdRowNumber, show);
			//enemyFour.drawEnemyAtLocation(i, enemyDelayFour, fourthRowNumber, show);
			//enemyFive.drawEnemyAtLocation(i, enemyDelayFive, fifthRowNumber, show);

		}



		//set the location of the gameboard dividers, however not being printed right now // checked
		leftColumn.setDrawPoint(45, i);
		middleColumnLeft.setDrawPoint(55, i);
		middleColumnRight.setDrawPoint(65, i);
		rightColumn.setDrawPoint(75, i);

		//Now we draw them to the screen: // checked
		leftColumn.draw('|');
		middleColumnLeft.draw('|');
		middleColumnRight.draw('|');
		rightColumn.draw('|');
		ship.drawShip();


		//check for for collisons bewtween ship, and enemy: // checked 

		if (enemyOne.getX() == ship.getX() && (enemyOne.getY() >= ship.getY() && enemyOne.getY() <= 29)) {
			ship.damage = true;
		}

		if (enemyTwo.getX() == ship.getX() && (enemyTwo.getY() >= ship.getY() && enemyTwo.getY() <= 29)) {
			ship.damage = true;
		}

		if (enemyThree.getX() == ship.getX() && (enemyThree.getY() >= ship.getY() && enemyThree.getY() <= 29)) {
			ship.damage = true;
		}

		if (enemyFour.getX() == ship.getX() && (enemyFour.getY() >= ship.getY() && enemyFour.getY() <= 29)) {
			ship.damage = true;
		}

		if (enemyFive.getX() == ship.getX() && (enemyFive.getY() >= ship.getY() && enemyFive.getY() <= 29)) {
			ship.damage = true;
		}

		//Initiate dmg and cause a gameover:

		if (ship.damage == true)
		{
			ship.deleteOldDrawingOfShip(ship.getX(), 25);
			asteroidGameInstance.menuGameOverScreen(scores, names, ship.score);

		CHECK: restartGame = _getch();

			if (restartGame == 'r') {
				goto MAINMENU;
			}
			else if (restartGame == ' ') {
				break;
			}
			else goto CHECK;
		}


		//lets read the keyboard input:

		if (_kbhit())
		{
			op = _getch();
		}

		//left: //checked

		if ((int)op == 75) {
			if (ship.getX() == 70) {
				ship.setDrawPoint(60, 25);
				ship.deleteOldDrawingOfShip(70, 25);
			}
			else if (ship.getX() == 60) {
				ship.setDrawPoint(50, 25);
				ship.deleteOldDrawingOfShip(60, 25);
			}
			else { ship.setDrawPoint(50, 25); }

			op = 'l';

		}

		//right
		if ((int)op == 77) {
			if (ship.getX() == 50) {
				ship.setDrawPoint(60, 25);
				ship.deleteOldDrawingOfShip(50, 25);
			}
			else if (ship.getX() == 60) {
				ship.setDrawPoint(70, 25);
				ship.deleteOldDrawingOfShip(60, 25);
			}
			else { ship.setDrawPoint(70, 25); }

			op = 'l';

		}

		if (op == ' ')
		{
			asteroidGameInstance.pauseGame();
			while (_getch() != ' ') {

			}
			asteroidGameInstance.unPauseGame();
			op = 'l';
		}
		else {}

		//everytime we spawn a new enemy we want to incrase the speed of the game:

		if (i == 0) speed -= 3;

		//make sure the game doesnt go to fastr and crash:
		if (speed < 65 && ship.score < 5000) speed = 65;
		if (speed < 55 && ship.score < 20000) speed = 55;

		if (speed < 45 && ship.score < 50000) speed = 45;

		if (speed < 35 && ship.score < 100000) speed = 35;
		if (speed < 25 && ship.score < 200000) speed = 25;
		if (ship.score % 1000 == 0 || ship.score % 1000 == 500) { level += 1; }

		i += 1;

		Sleep(speed);
		//system("cls");





	}
	
	return 0;

}





	

	









