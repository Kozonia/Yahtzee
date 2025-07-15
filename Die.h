#ifndef DIE
#define DIE
class Die
{
private:
	const int numOfSides;
	int faceValue;
public:
	Die();
	void roll();
	const int getFaceValue();
};
#endif

