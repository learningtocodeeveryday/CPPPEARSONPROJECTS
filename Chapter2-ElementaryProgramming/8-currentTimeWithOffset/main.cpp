#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>

using namespace std;

// Enter the time zone offset to GMT: -5
// Current time is 17:13:53

const int SECONDS_PER_MINUTE = 60;
const int MINUTES_PER_HOUR = 60;
const int HOURS_PER_DAY = 24;
const int SECONDS_PER_HOUR = SECONDS_PER_MINUTE * MINUTES_PER_HOUR;
const int SECONDS_PER_DAY = SECONDS_PER_MINUTE * MINUTES_PER_HOUR * HOURS_PER_DAY;

const int MAX_CLOCK_HOUR = 12;

const int LOWER_BOUND_TIME = 0;

class Time
{
	private:
	int hour;
	int minute;
	int second;
	public:
	Time() = default;
	Time(int hour, int minute, int second)
	{
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}

	void offsetHour(int hourOffset)
	{
		this->hour += hourOffset;

		if(this->hour >= MAX_CLOCK_HOUR)
		{
			this->hour = this->hour % MAX_CLOCK_HOUR;
		}
		else if(this->hour <= LOWER_BOUND_TIME)
		{
			this->hour = this->hour % MAX_CLOCK_HOUR;
			this->hour += MAX_CLOCK_HOUR;
		}

	}

	string toString() const
	{
		return "Current time is " + to_string(this->hour) + ":" + to_string(this->minute) + ":" + to_string(this->second);
	}

	friend ostream& operator<<(ostream& os, const Time& timeObject);

};

int main()
{
	long long totalSecondsSinceLinuxEpoch = time(0);

	int totalDaysSinceLinuxEpoch = totalSecondsSinceLinuxEpoch / SECONDS_PER_DAY;

	//Know the seconds for the current day (then convert to hours:minutes:seconds)
	int currentDayInSeconds = totalSecondsSinceLinuxEpoch - (totalDaysSinceLinuxEpoch * SECONDS_PER_DAY);
	int remainingSecondsForDay = currentDayInSeconds;

	int currentHour = remainingSecondsForDay / SECONDS_PER_HOUR;
	remainingSecondsForDay = remainingSecondsForDay % SECONDS_PER_HOUR;

	int currentMinute = remainingSecondsForDay / SECONDS_PER_MINUTE;
	remainingSecondsForDay = remainingSecondsForDay % SECONDS_PER_MINUTE;

	Time timerObject(currentHour, currentMinute, remainingSecondsForDay);

	// Enter the time zone offset to GMT: -5
// Current time is 17:13:53
	cout << "Enter the time zone offset to GMT: ";
	int timeZoneOffset;
	cin >> timeZoneOffset;

	timerObject.offsetHour(timeZoneOffset);

	cout << timerObject;
	
	return 0;
}

ostream& operator<<(ostream& os, const Time& timeObject)
{
	os << timeObject.toString();
	return os;
}