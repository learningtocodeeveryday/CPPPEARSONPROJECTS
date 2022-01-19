#include <iostream>
#include <cassert>
using namespace std;

const double CELSIUS_TO_FAHRENHEIT_RATIO = 9.0 / 5;
const int CELSIUS_TO_FAHRENHEIT_ADDITION = 32;


constexpr double celsiusToFahrenheit(double celsius)
{
    double fahrenheit = CELSIUS_TO_FAHRENHEIT_RATIO * celsius + CELSIUS_TO_FAHRENHEIT_ADDITION;
    return fahrenheit;
}

int main()
{
    const int celsius0 = 0;
    const int celsius100 = 100;

    constexpr double fahrenheit0 = celsiusToFahrenheit(celsius0);
    constexpr double fahrenheit100 = celsiusToFahrenheit(celsius100);

    assert(fahrenheit0 == 32);
    assert(fahrenheit100 == 212);

    static_assert(fahrenheit0 == 32, "Celsius of 0 is fahrenheit of 32");
    static_assert(fahrenheit100 == 212, "Celsius of 100 is fahrenheit of 212");

    int number;
    cin >> number;
    cout << number;
    
    return 0;
}