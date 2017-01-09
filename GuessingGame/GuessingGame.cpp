/*
Implementation of GuessingGame class designed by Tyler Ingham
Developed by Tyler Ingham
Copywrtie 2017 Tyler Ingham

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include "GuessingGame.h"

using namespace Game;

/*
Private memeber function that initializes all memeber variables
to default values or gets value by prompting user. Also seeds rand().
Values set by default: m_tries, m_numberToGuess, m_playerGuess
Values set by user: m_difficulty
*/
void GuessingGame::_Init()
{
	m_tries = 0;
	m_numberToGuess = 0;
	m_playerGuess = 0;

	std::cout << std::endl;
	do
	{
		std::cout << "===================\n"
			<< "Difficulty Settings\n"
			<< "Easy(12 tries) - 1\n"
			<< "Medium(7 tries) - 2\n"
			<< "Hard(4 tries) - 3\n"
			<< "Pick Difficulty: ";
		std::cin >> m_difficulty;
		std::cout << "===================" << std::endl;
	} while (!(m_difficulty > 0 && m_difficulty < 4));
	std::cout << std::endl;

	srand(time(NULL));

	return;
}

/*
Getter for member variable: m_numberToGuess
*/
int GuessingGame::GetNumberToGuess()
{
	return m_numberToGuess;
}

/*
Getter for member variable: m_playerGuess
*/
int GuessingGame::GetGuess()
{
	return m_playerGuess;
}

/*
Getter for member variable: cm_EASY_NUM_TRIES
*/
int GuessingGame::GetEasyNumTries()
{
	return cm_EASY_NUM_TRIES;
}

/*
Getter for member variable: cm_MEDIUM_NUM_TRIES
*/
int GuessingGame::GetMediumNumTries()
{
	return cm_MEDIUM_NUM_TRIES;
}

/*
Getter for member variable: cm_HARD_NUM_TRIES
*/
int GuessingGame::GetHardNumTries()
{
	return cm_HARD_NUM_TRIES;
}

/*
Getter for member variable: m_tries
*/
int GuessingGame::GetTries()
{
	return m_tries;
}

/*
Getter for member variable: cm_LOWER_BOUND
*/
int GuessingGame::GetLowerBound()
{
	return cm_LOWER_BOUND;
}

/*
Getter for member variable: cm_UPPER_BOUND
*/
int GuessingGame::GetUpperBound()
{
	return cm_UPPER_BOUND;
}

/*
Getter for member variable: m_difficulty
*/
int GuessingGame::GetDifficulty()
{
	return m_difficulty;
}

/*
Getter for member variable: m_playing
*/
bool GuessingGame::GetPlaying()
{
	return m_playing;
}

/*
Debugging member function for setting member variable: m_numberToGuess
*/
void GuessingGame::SetNumberToGuess(int num)
{
	if (!(num > cm_LOWER_BOUND && num < cm_UPPER_BOUND))
		m_numberToGuess = num;
	else
		m_numberToGuess = -1;

	return;
}

/*
Debugging member function for setting member variable: m_playerGuess
*/
void GuessingGame::SetPlayerGuess(int num)
{
	m_playerGuess = num;

	return;
}

/*
Debugging member function for setting member variable: m_tries
*/
void GuessingGame::SetNumTries(int num)
{
	switch (m_difficulty)
	{
	case 1:
		if (!(num > 0 && num < cm_EASY_NUM_TRIES))
			m_tries = num;
		else
			m_tries = -1;
		break;
	case 2:
		if (!(num > 0 && num < cm_MEDIUM_NUM_TRIES))
			m_tries = num;
		else
			m_tries = -1;
		break;
	case 3:
		if (!(num > 0 && num < cm_HARD_NUM_TRIES))
			m_tries = num;
		else
			m_tries = -1;
		break;
	case -1:
		m_tries = -1;
	}

	return;
}

/*
Debugging member function for setting member variable: m_difficulty
*/
void GuessingGame::SetDiffiulty(int num)
{
	if (!(num > 0 && num < 4))
		m_difficulty = num;
	else
		m_difficulty = -1;

	return;
}

/*
Debugging member function for setting member variable: m_playing
*/
void GuessingGame::SetPlaying(bool val)
{
	m_playing = val;

	return;
}

/*
Public member function that generates the random number to be guessed
by user by calling rand() using member variable: cm_UPPER_BOUND as the
upper limit on the mod opperator
*/
void GuessingGame::GenerateNumberToGuess()
{
	m_numberToGuess = rand() % cm_UPPER_BOUND + 1;

	return;
}

/*
Public member function that greets user, displays rules and calls
private member function: _Init()
*/
void GuessingGame::PrintGreeting()
{
	std::cout << "\nWelcome to Tyler's Guessing Game!";
	std::cout << "\nRules are simple, Tyler will pick a number between "
		<< cm_LOWER_BOUND << " and " << cm_UPPER_BOUND << " inclusive"
		<< "\nand then you try to guess it!";
	std::cout << std::endl << std::endl;
	_Init();

	return;
}

/*
Public member function that prompts user for his/her guess,
validates that the guess is an integer, and if it is, sets
member variable: m_guess to players guess.
Sets member variable: m_guess to -1 otherwise
*/
void GuessingGame::MakeGuess()
{
	int guess = -1;
	bool valid = false;

	do
	{
		std::cout << "Enter a guess: ";
		std::cin >> guess;
		if (std::cin.good())
			valid = true;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input!\nError: Value entered not an integer" << std::endl;
		}
	} while (!valid);
	m_playerGuess = guess;

	return;
}

/*
Public member function that checks member variables: m_numberToGuess and m_guess
for equivalency and returns true if they are, false otherwise
*/
bool GuessingGame::CheckGuess()
{
	bool guessed = false;

	if (m_playerGuess == m_numberToGuess)
		guessed = true;

	return guessed;
}

/*
Public member function that takes a boolean value to be obtained from 
member function: CheckGuess(), and prompts the user the he/she won if val
is true, otherwise prompts user that he/she has not guessed the number
*/
void GuessingGame::ProcessTurn(bool val)
{
	if (val)
	{
		std::cout << "\n\nCongratulations! You guessed the number!" << std::endl;
		m_playing = false;
	}
	else
	{
		std::cout << "That is not the correct number!" << std::endl;
		m_tries++;
	}

	return;
}

/*
Public member function to be called to play the game. Calls all necessary
functions to be able to play game and prompts user to play again upon finishing.
Returns a value of 1 if the user wants to play again, 0 if they do not, and a
value of -1 if an error occured while creating/playing the game.
*/
int GuessingGame::Play()
{
	PrintGreeting();
	GenerateNumberToGuess();
	/*
	std::cout << m_numberToGuess << std::endl;	//Debug
	*/
	m_playing = true;
	bool guessed;

	while (m_playing)
	{
		switch (m_difficulty)
		{
		case 1:
			while (m_tries < cm_EASY_NUM_TRIES)
			{
				MakeGuess();
				guessed = CheckGuess();
				ProcessTurn(guessed);
				if (guessed)
					break;
				std::cout << "Guess again! You have " << cm_EASY_NUM_TRIES - m_tries << " tries left!" << std::endl;
			}
			break;
		case 2:
			while (m_tries < cm_MEDIUM_NUM_TRIES)
			{
				MakeGuess();
				guessed = CheckGuess();
				ProcessTurn(guessed);
				if (guessed)
					break;
				std::cout << "Guess again! You have " << cm_MEDIUM_NUM_TRIES - m_tries << " tries left!" << std::endl;
			}
			break;
		case 3:
			while (m_tries < cm_HARD_NUM_TRIES)
			{
				MakeGuess();
				guessed = CheckGuess();
				ProcessTurn(guessed);
				if (guessed)
					break;
				std::cout << "Guess again! You have " << cm_HARD_NUM_TRIES - m_tries << " tries left!" << std::endl;
			}
			break;
		case -1:
			std::cout << "An error occured while creating the game!\nError: Game difficulty setting(-1)" << std::endl;
			return -1;
		}
		if(!guessed)
		{
			std::cout << "Sorry, you did not guess the correct number within the allowed number of tries."
				<< "\nThe correct number was: " << m_numberToGuess << std::endl;
		}
		char again;
		std::cout << "Would you like to play again? (Y or y for yes)" << std::endl;
		std::cin >> again;
		if (again == 'Y' || again == 'y')
			return 1;
	}

	return 0;
}

/*
Designer: Tyler Ingham
Developer: Tyler Ingham
Version: 1.0
Last Updated: 1/9/17 (Ver. 1.0.1)
*/
