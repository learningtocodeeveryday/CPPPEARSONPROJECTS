#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>

using namespace std;

const double AREA_OF_HEXAGON_COEFFICIENT= (3 * sqrt(3) ) / 2;

double calculateAreaOfHexagon(double sideLength)
{
	return AREA_OF_HEXAGON_COEFFICIENT * pow(sideLength, 2);
}

int main()
{
	cout << "Enter the side: ";
	double sideLength;
	cin >> sideLength;

	double areaOfHexagon = calculateAreaOfHexagon(sideLength);

	cout << "The area of the hexagon is " << areaOfHexagon;
	
	return 0;
}