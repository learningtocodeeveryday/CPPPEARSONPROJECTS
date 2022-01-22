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


bool checkFirstArgDivisibleBySecond(int first, int second)
{
	return (first % second == 0);
}

string getStringResult(bool isFirstDivisibleBySecond, int first, int second)
{
	string result = to_string(first) + " is ";

	result += (isFirstDivisibleBySecond) ? "" : "not ";

	result += "divisible by " + to_string(second);

	return result;

}


int main()
{
	cout << "Enter two integers: ";
	int first, second;
	cin >> first >> second;

	bool isFirstDivisibleBySecond = checkFirstArgDivisibleBySecond(first, second);

	string result = getStringResult(isFirstDivisibleBySecond, first, second);

	cout << result << endl;

	return 0;
}