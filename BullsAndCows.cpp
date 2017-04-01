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
FText GetValidGuess();
void PrintGuess(FText Guess);
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame;

int main()
{
	bool ContinuePlaying = false;

	PrintIntro();

	do
	{
		PlayGame();

		ContinuePlaying = AskToPlayAgain();

		std::cout << "So we are going to continue? " << ContinuePlaying << std::endl;
		std::cout << std::endl;
	} while (ContinuePlaying);

	return 0;
}

void PlayGame()
{
	constexpr int32 DefaultCurrentTry = 1;
	constexpr int32 MaxTries = 8;

	BCGame.Reset(DefaultCurrentTry, MaxTries);

	int32 AllowedMaxTries = BCGame.GetMaxTries();
	FText Guess = "";

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		Guess = GetValidGuess();

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		// print number of bulls and cows
		std::cout << "Number of Bulls: " << BullCowCount.Bulls;
		std::cout << " Cows: " << BullCowCount.Cows << std::endl;
	}

	PrintGameSummary();

	return;
}


void PrintIntro()
{
	// Intro to game and word length
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	printf("Can you guess the %d letter isogram\n", BCGame.GetHiddenWordLength());

	std::cout << std::endl;

	return;
}

FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid;
	FText Guess = "";

	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();

		// Input guess
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter word length: " << BCGame.GetHiddenWordLength() << "\n";
			break;
		case EGuessStatus::Not_LowerCase:
			std::cout << "Please enter guess in lowercase.\n" << std::endl;
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Guess must be an isogram.\n";
			break;
		default:
			// assume guess valid
			break;
		}

		std::cout << std::endl;

	} while (Status != EGuessStatus::OK);

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
	std::cout << "Do you want to play again with the same word (y/n): ";
	getline(std::cin, Response);

	std::cout << std::endl;

	return (tolower(Response[0]) == 'y' ? true : false);
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "\nYou Won!!!!\n";;
	}
	else
	{
		std::cout << "\nBetter luck next time!!!!\n";
	}

	std::cout << std::endl;
}
