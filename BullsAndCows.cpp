/* 
 This is the console executable that makes use of the bull cow class.
 This acts as the view in the MVC pattern, and is responsible for all
 user interaction. For game logic see the FBullCowGame class.
 */

#include <iostream>
#include <string>

#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
void PrintGuess(FText Guess);
bool AskToPlayAgain();

FBullCowGame BCGame;

int main()
{
	bool ContinuePlaying = false;

	PrintIntro();

	PlayGame();

	ContinuePlaying = AskToPlayAgain();

	std::cout << "So we are going to continue? " << ContinuePlaying << std::endl;
	std::cout << std::endl;

	return 0;
}

void PlayGame()
{
	constexpr int32 DefaultCurrentTry = 1;
	constexpr int32 MaxTries = 8;

	BCGame.Reset(DefaultCurrentTry, MaxTries);

	int32 AllowedMaxTries = BCGame.GetMaxTries();
	FText Guess = "";

	// TODO change from "for" to "while" loop once
	// finished validating tries
	for (int32 i = 0; i < AllowedMaxTries; i++)
	{
		Guess = GetGuess(); // TODO make loop checking valid

		// Submit valid guess to the game
		// print number of bulls and cows
		PrintGuess(Guess);
	}

	// TODO summarise game
}


void PrintIntro()
{
	// Intro to game and word length
	constexpr int32 WORD_LENGTH = 4;

	std::cout << "Welcome to Bulls and Cows" << std::endl;
	printf("Can you guess the %d letter isogram\n", WORD_LENGTH);

	std::cout << std::endl;

	return;
}

FText GetGuess()
{
	FText Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();

	// Input guess
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	getline(std::cin, Guess);

	return Guess;
}

void PrintGuess(FText Guess)
{
	std::cout << "You guessed " << Guess << std::endl;

	std::cout << std::endl;
}

bool AskToPlayAgain()
{
	FText Response = "";
	std::cout << "Do you want to play again(y/n): ";
	getline(std::cin, Response);

	std::cout << std::endl;

	return (tolower(Response[0]) == 'y' ? true : false);
}
