#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>

using namespace std;

double convertInterestRatePercentageToDecimal(double interestRatePercentage)
{
	return interestRatePercentage / 100;
}

double convertYearlyInterestRateToMonthly(double yearlyInterestRate)
{
	return yearlyInterestRate / 12;
}

double calculateInterestForOneMonthPeriod(double balance, double yearlyInterestRatePercentage)
{
	double yearlyInterestRateDecimal = convertInterestRatePercentageToDecimal(yearlyInterestRatePercentage);

	double monthlyinterestRateDecimal = convertYearlyInterestRateToMonthly(yearlyInterestRateDecimal);

	return balance * monthlyinterestRateDecimal;
}

int main()
{
	cout << "Enter balance and interest rage (e.g. 3 for 3%): ";
	double balance, annualInterestRatePercentage;
	cin >> balance >> annualInterestRatePercentage;

	double interest = calculateInterestForOneMonthPeriod(balance, annualInterestRatePercentage);

	cout << "The balance is " << balance << endl;
	cout << "The interest is $" << interest;
	
	return 0;
}