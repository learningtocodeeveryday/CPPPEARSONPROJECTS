#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>

using namespace std;

// Enter v and a: 60.5 3.5
// The minimum runway length for this airplane is 522.893

double minimumLengthRunwayToTakeOff(double velocity, double acceleration)
{
	return (pow(velocity, 2) / (2 * acceleration));
}

int main()
{
	cout << "Enter v and a: ";
	double velocityMetersPerSecond, accelerationMetersPerSecondSquared;
	cin >> velocityMetersPerSecond >> accelerationMetersPerSecondSquared;

	double minimumRequiredLengthForTakeOff = minimumLengthRunwayToTakeOff(velocityMetersPerSecond, accelerationMetersPerSecondSquared);

	cout << "The minimum runway length for this airplane is " << minimumRequiredLengthForTakeOff;

	char c;
	cin.get(c);

	
	return 0;
}