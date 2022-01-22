#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>

using namespace std;

// Enter weight in pounds: 95.5
// Enter height in inches: 50
// BMI is 26.8573

enum BMI
{
	UNDERWEIGHT = 0,
	NORMAL = 1,
	OVERWEIGHT = 2,
	OBESE = 3
};

const string BMI_READINGS[] = {"Underweight", "Normal", "Overweight", "Obese"};

const double POUND_TO_KILOGRAM_CONVERSION = .45359237;
const double INCH_TO_METER_CONVERSION = .0254;


const double UNDERWEIGHT_TO_NORMAL_BORDER = 18.5;
const double NORMALWEIGHT_OVERWEIGHT_BORDER = 25;
const double OVERWEIGHT_TO_OBESE_BORDER = 30;

const int INCHES_PER_FEET = 12;


using namespace std;

double convertHeightFeetAndInchesToInches(double feet, double inches)
{
	return (feet * INCHES_PER_FEET) + inches;
}

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

const string& retrieveBMIReading(double BMI)
{
	if(BMI < UNDERWEIGHT_TO_NORMAL_BORDER)
	{
		return BMI_READINGS[BMI::UNDERWEIGHT];
	}
	else if(BMI < NORMALWEIGHT_OVERWEIGHT_BORDER)
	{
		return BMI_READINGS[BMI::NORMAL];
	}
	else if(BMI < OVERWEIGHT_TO_OBESE_BORDER)
	{
		return BMI_READINGS[BMI::OVERWEIGHT];
	}
	else
	{
		return BMI_READINGS[BMI::OBESE];
	}
}

int main()
{
	cout << "Enter the weight in pounds: ";
	double weightInPounds;
	cin >> weightInPounds;

	cout << "Enter feet: ";
	double heightFeet;
	cin >> heightFeet;

	cout << "Enter inches: ";
	double heightInches;
	cin >> heightInches;

	double totalHeightInInches = convertHeightFeetAndInchesToInches(heightFeet, heightInches);

	double BMI = calculateBMIWithConversionsToMetric(weightInPounds, totalHeightInInches);

	const string& BMIReading = retrieveBMIReading(BMI);

	cout << "Your BMI is " << BMI << endl;
	cout << BMIReading << endl;
	
	return 0;
}