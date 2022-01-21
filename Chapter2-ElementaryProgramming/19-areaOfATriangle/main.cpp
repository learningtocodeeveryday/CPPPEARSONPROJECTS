#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>

using namespace std;


const int POINTS_IN_A_TRIANGLE = 3;
const int COORDINATES_IN_A_POINT = 2;

class Point
{
	private:
	double x;
	double y;
	public:
	Point() = default;
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	double getDistance(const Point& second)
	{
		double xComponent = pow(second.x - this->x, 2);
		double yComponent = pow(second.y - this->y, 2);
		return sqrt(xComponent + yComponent);
	}
	void setX(double x)
	{
		this->x = x;
	}
	void setY(double y)
	{
		this->y = y;
	}
};

class Triangle
{
	private:
	double side1;
	double side2;
	double side3;
	public:
	Triangle(double side1, double side2, double side3)
	: side1(side1), side2(side2), side3(side3)
	{}
	Triangle(Point first, Point second, Point third)
	{
		this->side1 = first.getDistance(second);
		this->side2 = second.getDistance(third);
		this->side3 = third.getDistance(first);
	}
	Triangle(Point myPoints[POINTS_IN_A_TRIANGLE])
	{
		Point first = myPoints[0];
		Point second = myPoints[1];
		Point third = myPoints[2];

		this->side1 = first.getDistance(second);
		this->side2 = second.getDistance(third);
		this->side3 = third.getDistance(first);
	}
	double getS() const
	{
		return (this->side1 + this->side2 + this->side3) / 2;
	}
	double getArea() const
	{
		double s = getS();
		return sqrt( s * (s - this->side1) * (s - this->side2) * (s - this->side3) );
	}
};

int main()
{
	cout << "Enter three points for a triangle: ";
	
	Point trianglePoints[POINTS_IN_A_TRIANGLE];

	double x, y;


	for(int point = 0; point < POINTS_IN_A_TRIANGLE; point++)
	{
		cin >> x;
		trianglePoints[point].setX(x);

		cin >> y;
		trianglePoints[point].setY(y);

	}

	Triangle myTriangle(trianglePoints);

	cout << "The area of the triangle is " << myTriangle.getArea();
	
	return 0;
}