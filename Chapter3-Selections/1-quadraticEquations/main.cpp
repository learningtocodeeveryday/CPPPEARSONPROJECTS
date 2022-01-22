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

enum QUADRATIC_RESULTS
{
	NO_SOLUTION,
	ONE_SOLUTION,
	TWO_SOLUTIONS
};

struct Quadratic_Components
{
	double a;
	double b;
	double c;
};

QUADRATIC_RESULTS determineNumberOfQuadraticSolutions(const Quadratic_Components& obj)
{
	double discriminant = pow(obj.b, 2) - (4 * obj.a * obj.c);

	QUADRATIC_RESULTS result;

	if(discriminant > 0)
	{
		result = QUADRATIC_RESULTS::TWO_SOLUTIONS;
	}
	else if(discriminant == 0)
	{
		result = QUADRATIC_RESULTS::ONE_SOLUTION;
	}
	else
	{
		result = QUADRATIC_RESULTS::NO_SOLUTION;
	}

	return result;

}

void solveQuadraticEquations(const Quadratic_Components& obj, double& root1, double& root2)
{
	QUADRATIC_RESULTS solution = determineNumberOfQuadraticSolutions(obj);

	double sqrtDiscriminant = sqrt(pow(obj.b, 2) - (4 * obj.a * obj.c));

	if(solution == QUADRATIC_RESULTS::NO_SOLUTION)
	{
		root1 = root2 = NULL;
		cout << "The equation has no real roots" << endl;
	}
	else if(solution == QUADRATIC_RESULTS::ONE_SOLUTION)
	{
		root1 = root2 = (sqrtDiscriminant - obj.b) / (2 * obj.a);
		cout << "The root is " << root1 << endl;
	}
	else if(solution == QUADRATIC_RESULTS::TWO_SOLUTIONS)
	{
		root1 = (sqrtDiscriminant - obj.b) / (2 * obj.a);
		root2 = (-1 * sqrtDiscriminant - obj.b) / (2 * obj.a);
		cout << "The roots are " << root1 << " and " << root2 << endl;
	}

}


int main()
{
	cout << "Enter a, b, c: ";
	double a, b, c;
	cin >> a >> b >> c;

	double root1, root2;

	Quadratic_Components obj = {a, b, c};

	solveQuadraticEquations(obj, root1, root2);
	
	return 0;
}