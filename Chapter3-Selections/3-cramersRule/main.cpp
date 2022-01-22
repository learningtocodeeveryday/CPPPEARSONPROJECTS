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

const double EPSILON = 1e-10;


struct LinearEquationComponents
{
	double a;
	double b;
	double c;
};

//first  a b c
//second d e f

void cramersRule(LinearEquationComponents first, LinearEquationComponents second, bool& solvable, double& x, double& y)
{
	double denominator = (first.a * second.a) - (first.b * first.c);

	//if it is non-zero then it is solvable
	solvable = fabs(denominator) > EPSILON;

	if(solvable)
	{
		x = ( (second.b * second.a) - (first.b * second.c) ) / denominator;

		y = ( (first.a * second.c) - (second.b * first.c) ) / denominator;
	}

}


int main()
{
	cout << "Enter a, b, c, d, e, f: ";
	double a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	LinearEquationComponents first {a, b, c};
	LinearEquationComponents second {d, e, f};

	double x , y;

	bool solvable;

	cramersRule(first, second, solvable, x, y);

	if(solvable)
	{
		cout << "X is " << x << " and Y is " << y << endl;
	}
	else
	{
		cout << "The equation has no solution" << endl;
	}
	
	return 0;
}