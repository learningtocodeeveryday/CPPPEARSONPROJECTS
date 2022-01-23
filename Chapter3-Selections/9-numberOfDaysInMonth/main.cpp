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

const int MONTH_OFFSET_TO_INDEX = -1;

const int FEBRUARY = 2;

const string MONTH_NAMES[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

const int MONTH_NUM_DAYS[] = {31, 28, 31,30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

string getResults(int monthInteger, int year)
{
	int monthIndex = monthInteger + MONTH_OFFSET_TO_INDEX;

	bool leapYear = isLeapYear(year);

	int numberOfDaysInAMonth = MONTH_NUM_DAYS[monthIndex];

	(leapYear && monthInteger == FEBRUARY) ? ++numberOfDaysInAMonth : numberOfDaysInAMonth;

	return (MONTH_NAMES[monthIndex] + " " + to_string(year) + " has " + to_string(numberOfDaysInAMonth) + " days"); 
}

int main()
{
	cout << "Enter a month in the year (e.g., 1 for Jan): ";
	int monthInteger;
	cin >> monthInteger;

	cout << "Enter a year: ";
	int year;
	cin >> year;

	cout << getResults(monthInteger, year);
	
	return 0;
}