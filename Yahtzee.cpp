#include "Die.h"
#include "GameLogic.h"
#include "ConsoleUI.h"
#include <iostream>
#include <time.h>
using namespace std;


int main()
{
	srand(time(0));

	//Die GameDie;
	GameLogic Game;
	

	Game.playGame();


	return 0;
}