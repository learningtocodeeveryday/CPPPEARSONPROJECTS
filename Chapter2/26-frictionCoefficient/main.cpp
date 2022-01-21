#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>

using namespace std;

//F = u * m * g + m * a

//solve for u (friction coefficient) given F, m, and a
//u = (F - (m * a)) / m * g

//F force applied to push/pull object in Newtons
//u is a coefficient of friction (uk small for smooth surface and large for rough surface)
//m is the object's mass in kilograms kg
//g is the acceleration due to gravity which is 9.8 m/s^2
const double GRAVITY_ACCELERATION = 9.8;
//a is the object's acceleration in m/s^2

double calculateFrictionCoefficient(double frictionForceInNewtons, double objectMassKilograms, double objectAcceleration, double gravitationalAcceleration)
{
	return (frictionForceInNewtons - (objectMassKilograms * objectAcceleration)) / (objectMassKilograms * gravitationalAcceleration);
}


int main()
{
	cout << "Enter the friction force in Newtons: ";
	double frictionForceInNewtons;
	cin >> frictionForceInNewtons;

	cout << "Enter the object's mass is kg: ";
	double objectMassKilograms;
	cin >> objectMassKilograms;

	cout << "Enter the object's acceleration in m/s^2: ";
	double objectAcceleration;
	cin >> objectAcceleration;

	double frictionCoefficient = calculateFrictionCoefficient(frictionForceInNewtons, objectMassKilograms, objectAcceleration, GRAVITY_ACCELERATION);

	cout << "The coefficient for friction is " << frictionCoefficient;
	
	return 0;
}