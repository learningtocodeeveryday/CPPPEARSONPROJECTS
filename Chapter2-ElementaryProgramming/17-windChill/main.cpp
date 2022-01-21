#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>

using namespace std;

namespace WIND_CHILL
{

	const double WINDCHILL_CONSTANT = 35.74;
	const double AIR_TEMPERATURE_COEFFICIENT = .6215;
	const double AIR_VELOCITY_COEFFICIENT = 35.75;
	const double AIR_TEMPERATURE_AND_VELOCITY_COEFFICIENT = .4275;

	const int LOWER_BOUND_TEMPERATURE = -58;
	const int UPPER_BOUND_TEMPERATURE = 41;

	const int LOWER_BOUND_AIR_SPEED = 2;

}


double calculateWindChillTemperature(double outsideTemp, double airVelocityMPH)
{
	double windChillTemperature = WIND_CHILL::WINDCHILL_CONSTANT + (WIND_CHILL::AIR_TEMPERATURE_COEFFICIENT * outsideTemp) - (WIND_CHILL::AIR_VELOCITY_COEFFICIENT * pow(airVelocityMPH, .16)) + (WIND_CHILL::AIR_TEMPERATURE_AND_VELOCITY_COEFFICIENT * outsideTemp * pow(airVelocityMPH, .16));

	return windChillTemperature;
}

bool validAirTemperature(double airTemperature)
{
	return (airTemperature >= WIND_CHILL::LOWER_BOUND_TEMPERATURE && airTemperature <= WIND_CHILL::UPPER_BOUND_TEMPERATURE);
}

bool validAirSpeed(double airSpeed)
{
	return (airSpeed >= WIND_CHILL::LOWER_BOUND_AIR_SPEED);
}

int main()
{
	cout << "Enter the temperature in Fahrenheit between " <<  WIND_CHILL::LOWER_BOUND_TEMPERATURE << " and " << WIND_CHILL::UPPER_BOUND_TEMPERATURE << ": ";
	double airTempInFahrenheit;
	cin >> airTempInFahrenheit;

	while(!validAirTemperature(airTempInFahrenheit))
	{
		cout << "Invalid air temperature: please enter value between " << WIND_CHILL::LOWER_BOUND_TEMPERATURE << " and " << WIND_CHILL::UPPER_BOUND_TEMPERATURE << ": ";
		cin >> airTempInFahrenheit;

	}

	cout << "Enter the wind speed miles per hour greater than or above " << WIND_CHILL::LOWER_BOUND_AIR_SPEED << " : ";
	double windSpeed;
	cin >> windSpeed;
	
	while(!validAirSpeed(windSpeed))
	{
		cout << "Invalid air speed: please enter value greater than or above " << WIND_CHILL::LOWER_BOUND_AIR_SPEED << " : ";
		cin >> windSpeed;
	}

	double windChillTemperature = calculateWindChillTemperature(airTempInFahrenheit, windSpeed);

	cout << "The wind chill index is " << windChillTemperature;
	
	return 0;
}