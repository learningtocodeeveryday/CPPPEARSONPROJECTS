#include <iostream>
#include <cassert>
using namespace std;



int main()
{
    cout << "Enter the subtotal and a gratuity rate: ";
    double subtotal, gratuityRatePercentage;
    cin >> subtotal >> gratuityRatePercentage;

    double gratuityRateDecimal = gratuityRatePercentage / 100;

    double gratuity = subtotal * gratuityRateDecimal;

    double total = gratuity + subtotal;

    cout << "The gratuity is " << gratuity << " and total is " << total << endl;


    return 0;
}