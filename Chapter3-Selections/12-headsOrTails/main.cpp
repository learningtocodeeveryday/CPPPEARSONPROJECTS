#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
using namespace std;

const int NUMBER_OF_COINFLIP_OUTCOMES = 2;

namespace Coinflip
{
	const int HEADS = 0;
	const int TAILS = 1;
}

int generateCoinFlip()
{
	return rand() % NUMBER_OF_COINFLIP_OUTCOMES;
}


int main()
{
	srand(time(0));

	cout << "Guess head or tail? Enter 0 for head and 1 for tail: ";

	int userGuess;
	cin >> userGuess;

	int randomlyGeneratedFlip = generateCoinFlip();

	string result;

	if(userGuess == randomlyGeneratedFlip)
	{
		result = "Correct guess";
	}
	else if(randomlyGeneratedFlip == Coinflip::HEADS)
	{
		result = "Sorry, it is a head";
	}
	else if(randomlyGeneratedFlip == Coinflip::TAILS)
	{
		result = "Sorry, it is a tail";
	}

	cout << result << endl;

	
	return 0;
}