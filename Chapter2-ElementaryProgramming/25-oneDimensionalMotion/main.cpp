#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>

using namespace std;


//eq1 v1 = v0 + a * t
//eq2 d = avgSpeed * t          ... avgSpeed = (v0 + v1) / 2
//eq3 d = v0 * t + (a * t^2)/2  ... derived from eq1 and eq2
//eq4 v1^2 = v0^2 + 2 * a * d   ... derived from eq1 and eq2

//v1 is final velocity m/s
//v0 is initial velocity m/s
//t is time in seconds
//a is object acceleration in m/s^2
//d is distance in meters

const double GRAVITY_ACCELERATION_METERS_PER_SECOND_SQUARED = 9.8;

//ball is released from top of building - no initial velocity
const double INITIAL_VELOCITY = 0;

//determine distance from top of building to ground given a travel time
double determineHeightOfBuildingFromFreeFallObject(double travelTime, double initialVelocity, double acceleration)
{
	double buildingHeight = (initialVelocity * travelTime) + (acceleration * pow(travelTime, 2)) / 2;

	return buildingHeight;
}

int main()
{
	cout << "Enter the ball travel time in seconds: ";
	double travelTime;
	cin >> travelTime;

	double buildingHeight = determineHeightOfBuildingFromFreeFallObject(travelTime, INITIAL_VELOCITY, GRAVITY_ACCELERATION_METERS_PER_SECOND_SQUARED);

	cout << "The height of the building is " << buildingHeight;
	
	return 0;
}