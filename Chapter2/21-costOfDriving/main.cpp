#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>

using namespace std;

double calculateCostForDrivingTrip(double distance, double MPG, double pricePerGallon)
{
	return (distance / MPG) * pricePerGallon;
}

int main()
{
	cout << "Enter the driving distance: ";
	double drivingDistance;
	cin >> drivingDistance;

	cout << "Enter the miles per gallon: ";
	double milesPerGallon;
	cin >> milesPerGallon;

	cout << "Enter the price per gallon: ";
	double pricePerGallon;
	cin >> pricePerGallon;

	double costOfDriving = calculateCostForDrivingTrip(drivingDistance, milesPerGallon, pricePerGallon);

	cout << "The cost of driving is $" << costOfDriving;
	
	return 0;
}