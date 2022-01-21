#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>

using namespace std;

const int SECONDS_PER_MINUTE = 60;
const int MINUTES_PER_HOUR = 60;
const int HOURS_PER_DAY = 24;
const int DAYS_PER_YEAR = 365;

const int STARTING_POPULATION = 312'032'486;

const int SECONDS_PER_YEAR = SECONDS_PER_MINUTE * MINUTES_PER_HOUR * HOURS_PER_DAY * DAYS_PER_YEAR;

const int SECONDS_PER_BIRTH = 7;
const int SECONDS_PER_DEATH = 13;
const int SECONDS_PER_IMMIGRATION = 45;

// One birth every 7 _seconds
// One death every 13 seconds
// One new immigrant every 45 seconds

int populationDeltaAfterXYears(int numberOfYears, int birthRate, int deathRate, int migrationRate)
{
	int totalSeconds = numberOfYears * SECONDS_PER_YEAR;

	int totalBirths = totalSeconds / SECONDS_PER_BIRTH;
	int totalDeaths = totalSeconds / SECONDS_PER_DEATH;
	int totalImmigrations = totalSeconds / SECONDS_PER_IMMIGRATION;

	int deltaPopulation = totalBirths + totalImmigrations - totalDeaths;

	return deltaPopulation;

}

int newPopulationAfterDeltaPopulation(int startingPopulation, int deltaPopulation)
{
	return startingPopulation + deltaPopulation;
}


int main()
{
	cout << "Enter the number of years: ";
	int numberOfYears;
	cin >> numberOfYears;

	int deltaPopulation = populationDeltaAfterXYears(numberOfYears, SECONDS_PER_BIRTH, SECONDS_PER_DEATH, SECONDS_PER_IMMIGRATION);

	int finalPopulation = newPopulationAfterDeltaPopulation(STARTING_POPULATION, deltaPopulation);

	cout << "The population in " << numberOfYears << " years is " << finalPopulation;
	
	return 0;
}