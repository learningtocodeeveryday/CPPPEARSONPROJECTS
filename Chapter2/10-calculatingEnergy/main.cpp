#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>

// Enter the amount of water in kilograms: 55.5
// Enter the initial temperature: 3.5
// Enter the final temperature: 10.5
// The energy needed is 1.62548e+006

using namespace std;

const int SPECIFIC_HEAT_OF_WATER_PER_KILOGRAM = 4184;

double energyRequiredToModifySubstanceTemperature(double initialTemp, double finalTemp, int specificHeatOfSubstance, double massOfSubstanceInKilograms)
{
	double energyRequired = massOfSubstanceInKilograms * (finalTemp - initialTemp) * specificHeatOfSubstance;

	return energyRequired;
}

int main()
{
	cout << "Enter the amount of water in kilograms: ";
	double kilogramsOfWater;
	cin >> kilogramsOfWater;

	cout << "Enter the initial temperature: ";
	double initialTemp;
	cin >> initialTemp;

	cout << "Enter the final temperature: ";
	double finalTemp;
	cin >> finalTemp;

	double energyRequiredInJoules = energyRequiredToModifySubstanceTemperature(initialTemp, finalTemp, SPECIFIC_HEAT_OF_WATER_PER_KILOGRAM, kilogramsOfWater);


	cout << "The energy needed is " << energyRequiredInJoules;

	
	return 0;
}