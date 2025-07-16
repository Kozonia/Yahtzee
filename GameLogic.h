#ifndef GAMELOGIC
#define GAMELOGIC
#include "Die.h"
#include "ConsoleUI.h"
#include <iostream>

class GameLogic
{
private:
	Die* diceHand;
	int* scoreBoard;
	const int numOfDice;
	int totalScore;
	const int rounds;
	const int subRounds;
	int pickedDiceAmount;
	int pickedDice;
	const int numOfCategories;
	int scoreCategory;
	int roundCount;
	int subRoundCount;
	void printRolledValues();
	void rollDiceHand();
	void reRollDice(int amount);
	int countNums(int target);
public:
	GameLogic();
	~GameLogic();
	void playGame();
	void printScore(); //MOVE TO CONSOLE UI
	int getRoundsCount();
	int getSubRoundsCount();
	int getScore();
	void ScoreDice();

};
#endif

