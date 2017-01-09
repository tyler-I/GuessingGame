#ifndef GUESSING_GAME_H
#define GUESSING_GAME_H

namespace Game
{
	/*
	Class designed by Tyler Ingham.
	Copywrite 2017 Tyler Ingham

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
	
	
	GuessingGame is a simplistic C++ console based guessing game.
	To use, have GuessingGame.h and GuessingGame.cpp in your working directory
	and make sure to have #include "GuessingGame.h" in your main file then simply
	create an instance of GuessingGame and call GuessingGame.Play().
	*/
	class GuessingGame
	{
	private:
		/*
		Const variables
		*/

		//Number of turns allowed in each difficulty
		const int cm_EASY_NUM_TRIES = 12;
		const int cm_MEDIUM_NUM_TRIES = 7;
		const int cm_HARD_NUM_TRIES = 4;

		//Upper and lower bounds on range for generated number
		const int cm_LOWER_BOUND = 0;
		const int cm_UPPER_BOUND = 15;

		//Private member variables
		int m_numberToGuess, m_playerGuess, m_tries, m_difficulty;
		bool m_playing;	//loop control

		//Private Member functions
		void _Init();
	public:
		//Contructors and destructors
		GuessingGame() { };
		~GuessingGame() { };

		//Getter functions
		int GetNumberToGuess();
		int GetGuess();
		int GetEasyNumTries();
		int GetMediumNumTries();
		int GetHardNumTries();
		int GetTries();
		int GetLowerBound();
		int GetUpperBound();
		int GetDifficulty();
		bool GetPlaying();

		//Debug setter functions
		void SetNumberToGuess(int num);
		void SetPlayerGuess(int num);
		void SetNumTries(int num);
		void SetDiffiulty(int num);
		void SetPlaying(bool val);

		//Public member functions
		void GenerateNumberToGuess();
		void PrintGreeting();
		void MakeGuess();
		bool CheckGuess();
		void ProcessTurn(bool val);
		int Play();	//Runs game
	};
}

#endif

/*
Designer: Tyler Ingham
Developer: Tyler Ingham
Version: 1.0
Last Updated: 1/9/17 (Ver. 1.0)
*/