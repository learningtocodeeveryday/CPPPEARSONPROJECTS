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

struct MonetaryChange
{
	int dollars = 0;
	int quarters = 0;
	int dimes = 0;
	int nickels = 0;
	int pennies = 0;

	void printChange(int totalCents)
	{
		cout << "Your amount " << totalCents << " consists of" << endl;
		cout << dollars << " dollars" << endl;
		cout << quarters << " quarters" << endl;
		cout << dimes << " dimes" << endl;
		cout << nickels << " nickels" << endl;
		cout << pennies << " pennies" << endl;
	}
};

void calculateChange(MonetaryChange& myChange, int totalCents)
{
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
	cout << "Enter an amount in integer, for example 1156 cents: ";
	int totalCents;
	cin >> totalCents;

	MonetaryChange myChange;

	calculateChange(myChange, totalCents);

	myChange.printChange(totalCents);
	
	return 0;
}