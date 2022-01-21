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

const int WIDTH_SPACING = 10;
const int COLUMNS = 3;

const string COLUMN_HEADINGS[COLUMNS] = {"a", "b", "pow(a, b)"};

void printTableOfExponents(int base, int exponent, int iterations)
{
	cout << left;

	for(int column = 0; column < COLUMNS; column++)
	{
		cout << setw(WIDTH_SPACING) << COLUMN_HEADINGS[column];
	}
	cout << endl;

	

	for(int iteration = 0; iteration < iterations; iteration++, base++, exponent++)
	{
		cout << setw(WIDTH_SPACING) << base;
		cout << setw(WIDTH_SPACING) << exponent;
		cout << setw(WIDTH_SPACING) << pow(base, exponent) << endl;
	}
}

int main()
{
	const int STARTING_BASE = 1;
	const int STARTING_EXPONENT = 2;
	const int ITERATIONS = 5;

	printTableOfExponents(STARTING_BASE, STARTING_EXPONENT, ITERATIONS);


	
	
	return 0;
}