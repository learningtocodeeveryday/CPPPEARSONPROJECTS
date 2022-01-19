#include <iostream>


int main()
{
    std::cout << "Hello World" << std::endl;

    std::cout << "What is your favorite number? ";

    int favoriteNumber;
    std::cin >> favoriteNumber;

    std::cout << "Your favorite number is " << favoriteNumber << std::endl;

    return 0;
}