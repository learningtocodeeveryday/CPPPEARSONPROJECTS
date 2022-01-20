#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>

using namespace std;

const int MONTHS_PER_YEAR = 12;

const int YEARLY_INTEREST_RATE = 5;
const double YEARLY_INTEREST_RATE_PERCENTAGE = YEARLY_INTEREST_RATE / 100.0;
const double MONTHLY_INTERST_RATE_PERCENTAGE = YEARLY_INTEREST_RATE_PERCENTAGE / MONTHS_PER_YEAR;

const int MONTHS_RESULT = 6;

// Enter the monthly saving amount: 100
// After the first month, the account value is 100.417
// After the second month, the account value is 201.252
// After the third month, the account value is 302.507
// After the sixth month, the account value is 608.811

double compoundedSavings(int monthsCompounded, double monthlySavings, double currentSavings, double monthlyInterestRatePercentage)
{
	for(int currentMonth = 1; currentMonth <= monthsCompounded; currentMonth++)
	{
		currentSavings = (currentSavings + monthlySavings) * (1 + monthlyInterestRatePercentage);
	}

	return currentSavings;
}

int main()
{
	cout << "Enter the monthly savings amount: ";
	double monthlySavingsAmount;
	cin >> monthlySavingsAmount;

	double currentSavings = 0;

	currentSavings = compoundedSavings(MONTHS_RESULT, monthlySavingsAmount, currentSavings, MONTHLY_INTERST_RATE_PERCENTAGE);

	// double currentSavings = 0;

	// for(int currentMonth = 1; currentMonth <= MONTHS_RESULT; currentMonth++)
	// {
	// 	currentSavings = (currentSavings + monthlySavingsAmount) * (1 + MONTHLY_INTERST_RATE_PERCENTAGE);

	// }

	cout << "After the sixth month, the account value is " << currentSavings;
	
	return 0;
}