#include <iostream>
#include <cassert>
using namespace std;


const double POUNDS_TO_KILOGRAMS_CONVERSION = .454;
const double KILOGRAMS_TO_POUNDS_CONVERSION = 1 / POUNDS_TO_KILOGRAMS_CONVERSION;

double convertPoundsToKilograms(double pounds)
{
    return pounds * POUNDS_TO_KILOGRAMS_CONVERSION;
}

int main()
{
    cout << "Enter a number in pounds: ";
    double numberOfPounds;
    cin >> numberOfPounds;

    double kilograms = convertPoundsToKilograms(numberOfPounds);

    cout << "The kilograms is " << kilograms << endl;

    return 0;
}