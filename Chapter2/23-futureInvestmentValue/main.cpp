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

double calculateMonthlyInterestRateDecimal(double annualInterestRatePercenatage)
{
	double monthlyInterestRateDecimal = annualInterestRatePercenatage / 1200;

	return monthlyInterestRateDecimal;
}

double calculateFutureInvestmentValue(double principal, double annualInterestRate, double numberOfYears)
{
	double monthlyInterestRate = calculateMonthlyInterestRateDecimal(annualInterestRate);

	double futureInvestmentValue = principal * pow(1 + monthlyInterestRate, numberOfYears * MONTHS_PER_YEAR);

	return futureInvestmentValue;
}

int main()
{
	cout << "Enter investment amount: ";
	double principal;
	cin >> principal;

	cout << "Enter annual interest rate: ";
	double annualInterestRatePercentage;
	cin >> annualInterestRatePercentage;

	cout << "Enter number of years: ";
	double numberOfYears;
	cin >> numberOfYears;

	double futureInvestmentValue = calculateFutureInvestmentValue(principal, annualInterestRatePercentage, numberOfYears);

	cout << "Future value is $" << futureInvestmentValue;
	
	return 0;
}