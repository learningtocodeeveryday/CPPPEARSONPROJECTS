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


//reads three edges of a triangle and computes area if input is valid.

//input is valid if all three edges are equal

const double AREA_OF_EQUILATERAL_TRIANGLE_COEFFICIENT = sqrt(3) / 4;

class EquilateralTriangle
{
	private:
	int sideLength;
	bool validConstruction;
	const int theta = 60;

	public:
	EquilateralTriangle()
	:sideLength(1)
	{}

	EquilateralTriangle(int sL1, int sL2, int sL3)
	{
		validateConstruction(sL1, sL2, sL3);
	}

	void validateConstruction(int sL1, int sL2, int sL3)
	{
		if(sL1 == sL2 && sL2 == sL3)
		{
			validConstruction = true;
			sideLength = sL1;
		}
		else
		{
			validConstruction = false;
			sideLength = 1;
		}
	}

	double getArea()
	{
		return (AREA_OF_EQUILATERAL_TRIANGLE_COEFFICIENT * pow(sideLength, 2));
	}

	bool getValidConstruction() const
	{
		return validConstruction;
	}

};


int main()
{
	cout << "Enter three lengths as integers: ";

	int sL1, sL2, sL3;

	cin >> sL1 >> sL2 >> sL3;


	EquilateralTriangle myTriangle(sL1, sL2, sL3);

	if(myTriangle.getValidConstruction())
	{
		cout << "The area is " << myTriangle.getArea();
	}
	else
	{
		cout << "Invalid input" << endl;
	}
	
	return 0;
}