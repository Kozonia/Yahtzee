#include "GameLogic.h"
#include "ConsoleUI.h"
#include <iostream>
#include <string>
using namespace std;



GameLogic::GameLogic() : numOfDice(5), subRounds(3), numOfCategories(6), rounds(6)
{
	diceHand = new Die[numOfDice];
	scoreBoard = new int[numOfCategories] {0, 0, 0, 0, 0, 0};
	totalScore = 0;
	pickedDice = 0;
	pickedDiceAmount = 0;
	scoreCategory = 0;
	roundCount = 1;
	subRoundCount = 1;
}

GameLogic::~GameLogic()
{
	delete[] diceHand;
	delete[] scoreBoard;
}

void GameLogic::printRolledValues()
{
	for (int i = 0; i < numOfDice; i++)
	{
		cout << "[ " << diceHand[i].getFaceValue() << " ] ";
	}
	cout << endl;
}

void GameLogic::rollDiceHand()
{
	cout << "Roll " << subRoundCount << endl;
	for (int i = 0; i < numOfDice; i++)
	{
		diceHand[i].roll();
	}
	

}

void GameLogic::reRollDice(int amount)
{
	cout << "Enter Which Dice to roll (one at a time): " << endl;
	for (int i = 0; i < amount; i++)
	{
		do {
			cin >> pickedDice;
			if (pickedDice > 0 && pickedDice <= numOfDice)
			{
				diceHand[pickedDice - 1].roll();
			}
			else
			{
				cout << "error" << endl;
			}
		} while (1 > pickedDice || pickedDice > numOfDice);
	}
	cout << "Roll " << subRoundCount << endl;
}

void GameLogic::printScore()
{
	cout << totalScore;
}

int GameLogic::getRoundsCount()
{
	return rounds;
}

int GameLogic::getSubRoundsCount()
{
	return subRounds;
}

int GameLogic::getScore()
{
	return totalScore;
}

int GameLogic::countNums(int target)
{
	int totalNums = 0;
	for (int i = 0; i < numOfDice; i++)
	{
		if (diceHand[i].getFaceValue() == target)
		{
			totalNums += target;
		}
	}
	return totalNums;
}

void GameLogic::ScoreDice()
{
	
	cout << "Which category do you want to score under this round?" << endl
		<< "1.Aces" << endl << "2.Twos" << endl << "3.Threes" << endl
		<< "4.Fours" << endl << "5.Fives" << endl << "6.Sixes" << endl;
	do {
		cin >> scoreCategory;

		if (0 < scoreCategory && scoreCategory <= 6)
		{
			scoreBoard[scoreCategory - 1] = countNums(scoreCategory);
		}
		else
		{
			cout << "error" << endl;
			
		}
	} while (0 > scoreCategory || scoreCategory > 6);

	if (roundCount == 6)
	{
		for (int i = 0; i < numOfCategories; i++)
		{
			totalScore += scoreBoard[i];
		}
	}
	
}

void GameLogic::playGame()
{
	roundCount = 1;

	do {
		subRoundCount = 1;
		do {

			if (subRoundCount == 1)
			{
				rollDiceHand();
				printRolledValues();
			}
			else
			{
				cout << "Enter how many dice you want to re-roll (Enter 0 to lock in dice): " << endl;
				do {
					cin >> pickedDiceAmount;

					if (0 < pickedDiceAmount && pickedDiceAmount <= numOfDice)
					{
						reRollDice(pickedDiceAmount);
						printRolledValues();
					}
					else if (pickedDiceAmount > numOfDice)
					{
						cout << "error" << endl;
					}
					else
					{
						subRoundCount = 3;
					}
				} while (0 > pickedDiceAmount || pickedDiceAmount > numOfDice);
			}
			subRoundCount++;
		} while (subRoundCount <= subRounds);
		ScoreDice();
		roundCount++;
	} while (roundCount <= rounds);

	cout << "Score: ";
	printScore();
}