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

class Point
{
	private:
		double x;
		double y;

	public:
		Point() = default;
		Point(double x, double y)
		: x(x), y(y)
		{}
		double getX() const
		{
			return x;
		}
		double getY() const
		{
			return y;
		}
		void setX(double x)
		{
			this->x = x;
		}
		void setY(double y)
		{
			this->y = y;
		}
		string toString() const
		{
			return ( "(" + to_string(x) + ", " + to_string(y) + ")");
		}

		friend ostream& operator<<(ostream& os, const Point& obj);


};

ostream& operator<<(ostream& os, const Point& obj)
{
	os << obj.toString();
	return os;
}

const int POINTS_IN_A_LINE = 2;

class Line
{
	private:
		double slope;
		double constant;
	public:
		Line() = default;
		Line(Point first, Point second)
		{
			setLine(first, second);
		}
		Line(Point points[POINTS_IN_A_LINE])
		{
			Point first = points[0];
			Point second = points[1];
			setLine(first, second);
		}
		void setLine(Point first, Point second)
		{
			slope = (second.getY() - first.getY())/(second.getX() - first.getX());
			constant = first.getY() - (first.getX() * slope);
		}
		double getSlope() const
		{
			return slope;
		}
		double getConstant() const
		{
			return constant;
		}
};

int main()
{
	cout << "Enter the coordinates for two points: ";

	double x, y;
	Point points[POINTS_IN_A_LINE];
	
	for(int point = 0; point < POINTS_IN_A_LINE; point++)
	{
		cin >> x;
		points[point].setX(x);

		cin >> y;
		points[point].setY(y);

	}

	Line myLine(points);


	cout << "The slope for the line that connects two points " << points[0] << " and " << points[1] << "is " << myLine.getSlope();
	
	return 0;
}