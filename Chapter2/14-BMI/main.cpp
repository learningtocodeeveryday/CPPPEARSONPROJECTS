#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>

// Enter weight in pounds: 95.5
// Enter height in inches: 50
// BMI is 26.8573

const double POUND_TO_KILOGRAM_CONVERSION = .45359237;
const double INCH_TO_METER_CONVERSION = .0254;

using namespace std;


double convertWeightPoundsToKilograms(double pounds)
{
	return pounds * POUND_TO_KILOGRAM_CONVERSION;
}

double convertHeightInchesToMeters(double inches)
{
	return inches * INCH_TO_METER_CONVERSION;
}

double calculateBMIWithConversionsToMetric(double weightInPounds, double heightInInches)
{
	double kilograms = convertWeightPoundsToKilograms(weightInPounds);
	double meters = convertHeightInchesToMeters(heightInInches);

	double BMI = kilograms / (pow(meters, 2));

	return BMI;
}

int main()
{
	cout << "Enter the weight in pounds: ";
	double weightInPounds;
	cin >> weightInPounds;

	cout << "Enter the height in inches: ";
	double heightInInches;
	cin >> heightInInches;

	double BMI = calculateBMIWithConversionsToMetric(weightInPounds, heightInInches);

	cout << "BMI is " << BMI << endl;
	
	return 0;
}