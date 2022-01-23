#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>

using namespace std;

const int DOLLAR_IN_CENTS = 100;
const int QUARTER_IN_CENTS = 25;
const int DIME_IN_CENTS = 10;
const int NICKEL_IN_CENTS = 5;
const int PENNY_IN_CENTS = 1;

const int NUMBER_OF_CHANGE_DENOMINATIONS = 5;

const string DENOMINATIONS[] = {"Dollar", "Quarter", "Dime", "Nickel", "Penny"};

int calculateTotalCentsFromChange(double change)
{
	return (change * 100);
}

void printADenomination(const string& denomination, int amount)
{
	if(amount)
	{
		cout << amount << " " << denomination;

		cout << ((amount > 1) ? "s" : "");

		cout << endl;
	}
}

struct MonetaryChange
{
	int dollars = 0;
	int quarters = 0;
	int dimes = 0;
	int nickels = 0;
	int pennies = 0;

	void printChange(double change)
	{
		int totalCents = calculateTotalCentsFromChange(change);

		cout << "Your amount " << totalCents << " consists of" << endl;
		printADenomination(DENOMINATIONS[0], dollars);
		printADenomination(DENOMINATIONS[1], quarters);
		printADenomination(DENOMINATIONS[2], dimes);
		printADenomination(DENOMINATIONS[3], nickels);
		printADenomination(DENOMINATIONS[4], pennies);
	}
};

void calculateChange(MonetaryChange& myChange, double change)
{
	int totalCents = calculateTotalCentsFromChange(change);

	myChange.dollars = totalCents / DOLLAR_IN_CENTS;
	totalCents %= DOLLAR_IN_CENTS;

	myChange.quarters = totalCents / QUARTER_IN_CENTS;
	totalCents %= QUARTER_IN_CENTS;

	myChange.dimes = totalCents / DIME_IN_CENTS;
	totalCents %= DIME_IN_CENTS;

	myChange.nickels = totalCents / NICKEL_IN_CENTS;
	totalCents %= NICKEL_IN_CENTS;

	myChange.pennies = totalCents;
}

int main()
{
	cout << "Enter an amount of change: ";
	double change;
	cin >> change;

	MonetaryChange myChange;

	calculateChange(myChange, change);

	myChange.printChange(change);
	
	return 0;
}