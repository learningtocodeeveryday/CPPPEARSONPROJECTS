#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>

// Enter a number between 0 and 1000: 435
// The sum of the digits is 12

using namespace std;

const int LOW_ENDPOINT = 0;
const int HIGH_ENDPOINT = 1000;

bool validateValueBetweenRange(int inputValue, int lowEnd, int highEnd)
{
	return (inputValue >= lowEnd && inputValue <= highEnd);
}

int sumOfDigits(int inputValue)
{
	int sum = 0;

	while(inputValue > 0)
	{
		int lastDigit = inputValue % 10;
		sum += lastDigit;

		inputValue /= 10;
	}

	return sum;
}

int main()
{
	cout << "Enter a number between " << LOW_ENDPOINT << " and " << HIGH_ENDPOINT << ": ";
	int userInput;

	cin >> userInput;

	while(!validateValueBetweenRange(userInput, LOW_ENDPOINT, HIGH_ENDPOINT))
	{
		cout << "Invalid: Please enter a number between " << LOW_ENDPOINT << " and " << HIGH_ENDPOINT << ": ";
		cin >> userInput;
	}

	int sum = sumOfDigits(userInput);

	cout << "The sum of the digits is " << sum << endl;
	
	return 0;
}