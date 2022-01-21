#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>

using namespace std;

// Enter x1 and y1: 1.5 -3.4
// Enter x2 and y2: 4 5
// The distance of the two points is 8.76413

class Point
{
	private:
	double x;
	double y;
	public:
	Point()
	: x(0), y(0)
	{}
	Point(double x, double y)
	: x(x), y(y)
	{}
	double getDistance(const Point& secondPoint) const
	{
		//     distance = sqrt of      (x2 - x1)^2 + (y2 - y1)^2
		double distance = sqrt( (pow(secondPoint.x - this->x, 2) ) + pow((secondPoint.y - this->y), 2) );

		return distance;
	}
};



int main()
{
	double xValue, yValue;

	cout << "Enter x1 and y1: ";
	cin >> xValue >> yValue;

	Point firstPoint(xValue, yValue);

	cout << "Enter x2 and y2: ";
	cin >> xValue >> yValue;

	Point secondPoint(xValue, yValue);

	double distanceBetweenPoints = firstPoint.getDistance(secondPoint);

	cout << "The distance of the two points is " << distanceBetweenPoints;
	
	return 0;
}