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


// cost of shipping
// 3.5 if 0 < w <= 1
// 5.5 if 1 < w <= 3
// 8.5 if 3 < w <= 10
// 10.5 if 10 < w <= 20

const int INVALID = -1;
const int CANNOT_SHIP = -2;

const double EXTRA_SMALL_COST = 3.5;
const double SMALL_COST = 5.5;
const double NORMAL_COST = 8.5;
const double LARGE_COST = 10.5;

const int MINIMUM_WEIGHT_BOUNDARY = 0;
const int EXTRA_SMALL_WEIGHT_BOUNDARY = 1;
const int SMALL_WEIGHT_BOUNDARY = 3;
const int NORMAL_WEIGHT_BOUNDARY = 10;
const int LARGE_WEIGHT_BOUNDARY = 20;

const double EPSILON = 1E-5;

bool floatsAreEqual(double first, double second)
{
	bool equal = fabs(first - second) < EPSILON;

	return equal;
}

bool floatsAreLessThanOrEqual(double first, double second)
{
	bool lessThan = first < second;

	bool equal = fabs(first - second) < EPSILON;

	return (lessThan || equal);
}


double costOfShipping(double weight)
{
	double cost;
	if(floatsAreLessThanOrEqual(weight, MINIMUM_WEIGHT_BOUNDARY))
	{
		cost = INVALID;
	}
	else if(floatsAreLessThanOrEqual(weight, EXTRA_SMALL_WEIGHT_BOUNDARY))
	{
		cost = EXTRA_SMALL_COST;
	}
	else if(floatsAreLessThanOrEqual(weight, SMALL_WEIGHT_BOUNDARY))
	{
		cost = SMALL_COST;
	}
	else if(floatsAreLessThanOrEqual(weight, NORMAL_WEIGHT_BOUNDARY))
	{
		cost = NORMAL_COST;
	}
	else if(floatsAreLessThanOrEqual(weight, LARGE_WEIGHT_BOUNDARY))
	{
		cost = LARGE_COST;
	}
	else
	{
		cost = CANNOT_SHIP;
	}

	return cost;
}

void printWeight(double cost)
{
	if(floatsAreEqual(cost, INVALID))
	{
		cout << "Invalid weight" << endl;
	}
	else if(floatsAreEqual(cost, CANNOT_SHIP))
	{
		cout << "The package cannot be shipped." << endl;
	}
	else
	{
		cout << "The shipping cost is " << cost << endl;
	}
}


int main()
{
	cout << "Enter package weight: ";
	double weight;
	cin >> weight;

	double cost = costOfShipping(weight);
	printWeight(cost);
	
	return 0;
}