#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>

using namespace std;

const int DAYS_PER_YEAR = 365;

const int MINUTES_PER_HOUR = 60;

const int HOURS_PER_DAY = 24;

const int MINUTES_PER_DAY = MINUTES_PER_HOUR * HOURS_PER_DAY;



int main()
{
	cout << "Enter a total number of minutes: ";

	int totalMinutes;

	cin >> totalMinutes;

	int totalDays = totalMinutes / MINUTES_PER_DAY;

	cin >> totalDays;

	int totalYears = totalDays / DAYS_PER_YEAR;

	int remainingDays = totalDays % DAYS_PER_YEAR;

	cout << totalMinutes << " is approximately " << totalYears << " years and " << remainingDays << " days.";
	
	return 0;
}