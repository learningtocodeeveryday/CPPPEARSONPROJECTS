#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>
#include <iomanip>
#include <fstream>
using namespace std;


//0      			1             		2
//scissor         rock               paper

enum PlayType
{
	Scissor = 0,
	Rock = 1,
	Paper = 2
};

enum Outcome
{
	ComputerWin = 1,
	PlayerWin = 0,
	Draw = -1
};

class Entity
{
	public:

	PlayType type;

	Entity() = default;

	Entity(PlayType type)
	: type(type)
	{}

	Outcome play(Entity& player)
	{
		Outcome myOutcome;

		PlayType computer = this->type;

		if(computer == player.type)
		{
			myOutcome = Outcome::Draw;
			return myOutcome;
		}

		if(computer == PlayType::Scissor)
		{
			myOutcome = (player.type == PlayType::Rock) ? Outcome::PlayerWin : Outcome::ComputerWin;
		}
		else if(computer == PlayType::Rock)
		{
			myOutcome = (player.type == PlayType::Paper) ? Outcome::PlayerWin : Outcome::ComputerWin;
		}
		else if(computer == PlayType::Paper)
		{
			myOutcome = (player.type == PlayType::Scissor) ? Outcome::PlayerWin : Outcome::ComputerWin;
		}

		return myOutcome;
	}

	void printResults(Entity& player, Outcome result)
	{
		cout << "The computer is " << *(this) << ". ";
		cout << "You are " << player << ". ";
		
		if(result == Outcome::PlayerWin)
		{
			cout << "You won." << endl;
		}
		else if(result == Outcome::ComputerWin)
		{
			cout << "Computer won." << endl;
		}
		else if(result == Outcome::Draw)
		{
			cout << "It is a draw." << endl;
		}
	}

	friend istream& operator>>(istream& in, Entity& obj);
	friend ostream& operator<<(ostream& out, Entity& obj);
};

istream& operator>>(istream& in, Entity& obj)
{
	int myType;

	in >> myType;

	obj.type = static_cast<PlayType>(myType);

	return in;
}

ostream& operator<<(ostream& out, Entity& obj)
{
	if(obj.type == PlayType::Rock)
	{
		out << "Rock";
	}
	else if(obj.type == PlayType::Paper)
	{
		out << "Paper";
	}
	else if(obj.type == PlayType::Scissor)
	{
		out << "Scissor";
	}

	return out;
}

//This didn't work out how I expected using inheritance and overriding the play method :(
// class Rock : public Entity
// {
// 	public:

// 	Rock()
// 	: Entity(PlayType::Rock)
// 	{}

// 	bool play(Entity& opponent) override
// 	{
// 		if(opponent)
// 	}

// };

PlayType generatePlayType()
{
	return static_cast<PlayType>(rand() % 3);
}


int main()
{
	srand(time(0));

	Entity computerPlayer(generatePlayType());

	cout << "Select your player: Scissor (0), Rock (1), Paper (2): ";

	Entity player;
	cin >> player;


	Outcome myOutcome = computerPlayer.play(player);


	computerPlayer.printResults(player, myOutcome);
	
	return 0;
}