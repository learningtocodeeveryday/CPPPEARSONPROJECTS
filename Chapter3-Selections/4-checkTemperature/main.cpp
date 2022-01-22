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

const string COLD = "too cold";
const string HOT = "too hot";
const string RIGHT = "just right";

const int COLD_RIGHT_BORDER = 30;
const int RIGHT_HOT_BORDER = 100;

const string& temperatureFeeling(double temperature)
{
	if(temperature > RIGHT_HOT_BORDER)
	{
		return HOT;
	}
	else if(temperature >= COLD_RIGHT_BORDER)
	{
		return RIGHT;
	}
	else
	{
		return COLD;
	}
}


int main()
{
	cout << "Enter a temperature: ";
	double temp;
	cin >> temp;

	cout << temperatureFeeling(temp);
	
	return 0;
}