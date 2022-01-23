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

const int RANGE_OF_INTEGERS = 100;

int sum(int first, int second)
{
	return first + second;
}

int generateRandomInt(int range)
{
	return (rand() % range + 1);
}

bool determineCorrectness(int answer, int result)
{
	return (answer == result);
}


int main()
{
	srand(time(0));

	int firstRandom = generateRandomInt(RANGE_OF_INTEGERS);

	int secondRandom = generateRandomInt(RANGE_OF_INTEGERS);

	int answer = sum(firstRandom, secondRandom);

	cout << "What is " << firstRandom << " + " << secondRandom << "? ";

	int guess;
	cin >> guess;

	bool result = determineCorrectness(answer, guess);

	if(result)
	{
		cout << "Correct" << endl;
	}
	else
	{
		cout << firstRandom << " + " << secondRandom << " should be " << answer << endl;
	}
	
	return 0;
}