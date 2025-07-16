#ifndef GAMELOGIC
#define GAMELOGIC
#include "Die.h"
#include <iostream>

class GameLogic
{
private:
	Die* diceHand;
	const int numOfDice;
	int totalScore;
	const int rounds;
	int subRounds;
	void printRolledValues();
	void rollDiceHand();
public:
	GameLogic();
	~GameLogic();
	void playGame();
	void printScore();
	int getRounds();
	int getSubRounds();
	int getScore();

};
#endif

