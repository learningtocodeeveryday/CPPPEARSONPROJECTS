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


void sortTwoIntegers(int& a, int& b)
{
	if(a > b)
	{
		int temp = b;
		b = a;
		a = temp;
	}
}

void sortThreeIntegers(int& a, int& b, int& c)
{
	sortTwoIntegers(a, b);
	sortTwoIntegers(b, c);
	sortTwoIntegers(a, b);
}


int main()
{
	cout << "Enter three integers: ";
	int a, b, c;
	cin >> a >> b >> c;

	sortThreeIntegers(a, b, c);

	cout << "n1, n2, and n3 are " << a << ", " << b << ", and " << c << endl;
	
	return 0;
}