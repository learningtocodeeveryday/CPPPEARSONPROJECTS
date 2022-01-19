#include <iostream>
#include <cassert>
using namespace std;

const double FEET_TO_METERS_CONVERSION = .305;
const double METERS_TO_FEET_CONVERSION = 1/FEET_TO_METERS_CONVERSION;

double convertFeetToMeters(double feet)
{
    return feet * FEET_TO_METERS_CONVERSION;
}

int main()
{
    cout << "Enter number of feet: ";
    double feet;
    cin >> feet;

    double meters = convertFeetToMeters(feet);
    cout << "The meter is " << meters;

    return 0;
}