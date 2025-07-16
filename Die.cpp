#include "Die.h"
#include <iostream>
using namespace std;

Die::Die() : numOfSides(6)
{
	faceValue = 1;
}

void Die::roll()
{
	faceValue = rand() % 6 + 1;
}

const int Die::getFaceValue()
{
	return faceValue;
}