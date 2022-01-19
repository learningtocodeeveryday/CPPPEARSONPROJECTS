#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

const double PI = 3.1415;

int main()
{
    cout << "Enter radius: ";
    double radius;
    cin >> radius;

    cout << "Enter length: ";
    double length;
    cin >> length;

    double area = pow(radius, 2) * PI;
    double volume = area * length;

    cout << "The area is " << area << endl;
    cout << "The volume is " << volume << endl;

    return 0;
}