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

const string DAY_OF_THE_WEEK[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

const int DAYS_PER_WEEK = 7;


int main()
{
	cout << "Enter today's day: ";
	int dayOfTheWeekInteger;
	cin >> dayOfTheWeekInteger;

	cout << "Enter the number of days elapsed since today: ";
	int numberOfDaysElapsed;
	cin >> numberOfDaysElapsed;

	const string& dayOfTheWeekString = DAY_OF_THE_WEEK[dayOfTheWeekInteger];

	int futureDayOfTheWeekInteger = (dayOfTheWeekInteger + numberOfDaysElapsed) % DAYS_PER_WEEK;

	const string& futureDayOfWeekString = DAY_OF_THE_WEEK[futureDayOfTheWeekInteger];

	cout << "Today is " << dayOfTheWeekString << " and the future day is " << futureDayOfWeekString << endl;

	
	
	return 0;
}