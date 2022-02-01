#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <algorithm>
using namespace std;

const int RANGE = 1000;

int generateRandomNumber(int range)
{
	return (rand() % range);
}

string generateThreeDigitString(int randomNumber)
{
	string randomString = to_string(randomNumber);

	if(randomString.size() == 1)
	{
		randomString = "00" + randomString;
	}
	else if(randomString.size() == 2)
	{
		randomString = "0" + randomString;
	}

	return randomString;

}

void generateThreeDigitString(string& randomString)
{
	if(randomString.size() == 1)
	{
		randomString = "00" + randomString;
	}
	else if(randomString.size() == 2)
	{
		randomString = "0" + randomString;
	}
}

const string FULL_AWARD = "$10,000";

const string ANAGRAM_AWARD = "$3,000";

const string ONE_DIGIT_AWARD = "$1,000";

bool isAnagram(string first, string second)
{
	std::sort(first.begin(), first.end());
	std::sort(second.begin(), second.end());

	return first == second;

}

bool oneMatchingCharacter(string first, string second)
{
	for(char firstChar: first)
	{
		for(char secondChar: second)
		{
			if(firstChar == secondChar)
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	srand(time(0));

	cout << "Enter your lottery pick (three digits): ";
	string userInput;
	cin >> userInput;

	generateThreeDigitString(userInput);

	string randomString = generateThreeDigitString(generateRandomNumber(RANGE));

	cout << "The lottery number is " << randomString << endl;

	if(userInput == randomString)
	{
		cout << FULL_AWARD << endl;
	}
	else if(isAnagram(userInput, randomString))
	{
		cout << ANAGRAM_AWARD << endl;
	}
	else if(oneMatchingCharacter(userInput, randomString))
	{
		cout << ONE_DIGIT_AWARD << endl;
	}
	else
	{
		cout << "Sorry, no match" << endl;
	}

	
	return 0;
}