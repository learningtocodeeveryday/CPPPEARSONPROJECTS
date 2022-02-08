#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
using namespace std;


struct Point
{
	double x, y;

	Point()
	{}

	Point(double x, double y)
	: x(x), y(y)
	{}

	double getDistance(Point other)
	{
		double dist = sqrt(pow(other.y - y, 2) + pow(other.x - x, 2));
		return dist;
	}

};


struct Circle
{
	Point point;
	double radius;


	Circle()
	{
		point.x = 0;
		point.y = 0;
		radius = 1;
	}

	Circle(double x, double y, double radius)
	{
		point.x = x;
		point.y = y;
		this->radius = radius;
	}

	bool pointInACircle(Point thePoint)
	{
		double distance = point.getDistance(thePoint);
		return (distance <= radius);

	}


};


int main()
{
	Circle example(0,0,10);

	cout << "Enter a point with two coordinates: ";
	double x, y;
	cin >> x >> y;

	Point thePoint(x,y);

	bool isWithinCircle = example.pointInACircle(thePoint);

	cout << ((isWithinCircle) ? "It is in the circle" : "It is not in the circle");
	
	return 0;
}