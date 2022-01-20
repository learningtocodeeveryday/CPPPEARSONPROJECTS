#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>

// Enter v0, v1, and t: 5.5 50.9 4.5
// The average acceleration is 10.0889

using namespace std;

double calculateAverageAcceleration(double initialVelocity, double finalVelocity, double timeInSeconds)
{
	return ((finalVelocity - initialVelocity) / timeInSeconds);
}

int main()
{
	cout << "Enter v0, v1, and t: ";
	double initialVelocity, finalVelocity, timeInSeconds;

	cin >> initialVelocity >> finalVelocity >> timeInSeconds;

	double averageAcceleration = calculateAverageAcceleration(initialVelocity, finalVelocity, timeInSeconds);

	cout << "The average acceleration is " << averageAcceleration;
	
	return 0;
}