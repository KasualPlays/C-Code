#include "AsteroidGame.h"

void AsteroidGame :: findPositionX(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void AsteroidGame::setCursor(bool visible, DWORD size)
{
	if (size == 0) {
		size = 20;
	}
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}

//Game mechanic Pause Function:

//create object to call functions:
AsteroidGame asteroidGameOne;


void AsteroidGame::menuStartingScreen()
{
	system("cls");
	cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "//////////////////////////////////////////               WELCOME TO:      ////////////////////////////////////////" << endl;
	cout << "/////////////////////////////////////////////////SHIP SHOOTER 5000        ////////////////////////////////////////" << endl;
	cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << "\tWelcome to Asteroids! Use the Arrow keys to move Left and Right. Press the Spacebar at any time to pause." << endl;
	cout << "\n\t\t\t\t\tGuide Your Spaceship past Asteroids \n\t\t\t and Lasers while you try to pick up Powerups to boost your score." << endl;
	cout << "\n\t\t\t\t\tPress the Spacebar to Begin." << endl;
	cout << "\n\t\t\t (Tip: For a Smoother Experience, make this Window Fullscreen.)" << endl;


}

void AsteroidGame::menuGameOverScreen(vector<int>& scoreList, vector<string>& namelist, int newScore)
{
	system("cls");

	cout << "\n\n\n\n\n\n\n////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "///////////////////////////////////////////////////                  ///////////////////////////////////////////////////" << endl;
	cout << "//////////////////////////////////////////////////     GAME OVER    ////////////////////////////////////////////////////" << endl;
	cout << "/////////////////////////////////////////////////                  /////////////////////////////////////////////////////" << endl;
	cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "\t\t\t\t\t\tPress R to continue." << endl;
	Sleep(1500);

	while (_getch() != 'r') {}

	int position = 6;
	for (int i = 0; i < scoreList.size(); i++)
	{
		if (newScore > scoreList[i])
		{
			position = i;
			break;
		}
	}

	int previousScore = 0;
	string previousName = "";
	for (int i = scoreList.size() - 1; i > position; i--)
	{
		scoreList[i] = scoreList[i - 1];
		scoreList[i - 1] = 0;
		namelist[i] = namelist[i - 1];
		namelist[i - 1] = "";
	}

	if (position != 6) {
		scoreList[position] = newScore;
		cout << "\t\t\t\tYou Got a High Score! Enter your name and then press Period: ";
		char op = ' ';
		string newname = "";
		while (op != '.')
		{
			op = _getch();
			cout << op;
			if (op == 127) {
				newname = newname.substr(0, newname.size() - 1);
				cout << newname << "";
			}
			else newname += op;
		}
		namelist[position] = newname.substr(0, newname.size() - 1);
	}
	asteroidGameOne.findPositionX(55, 14);
	cout << "LEADERBOARD";

	for (int i = 0; i < scoreList.size(); i++) {
		asteroidGameOne.findPositionX(50, i + 15);
		cout << namelist[i] << endl;
		asteroidGameOne.findPositionX(65, i + 15);
		cout << scoreList[i] << endl;
	}

	cout << "\n\t\t\t\tPress 'R' to Start Over, or press the Spacebar to Exit." << endl;

}
   

      


void AsteroidGame::pauseGame()
{
	asteroidGameOne.findPositionX(57, 15);
	cout << "GAME PAUSED" << endl;
	asteroidGameOne.findPositionX(57, 15);
	cout << "PRESS SPACE" << endl;
	asteroidGameOne.findPositionX(57, 15);
	cout << "TO RESUME" << endl;
	asteroidGameOne.findPositionX(57, 15);
	cout << "PLAYING" << endl;

}

void AsteroidGame::unPauseGame()
{
	asteroidGameOne.findPositionX(57, 15);
	cout << "           " << endl;
	asteroidGameOne.findPositionX(57, 15);
	cout << "           " << endl;
	asteroidGameOne.findPositionX(57, 15);
	cout << "         " << endl;
	asteroidGameOne.findPositionX(57, 15);
	cout << "       " << endl;
}
