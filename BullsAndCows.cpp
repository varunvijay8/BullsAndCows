#include <iostream>
#include <string>

#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
void PrintGuess(std::string Guess);
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
	constexpr int DefaultCurrentTry = 1;
	constexpr int MaxTries = 8;

	BCGame.Reset(DefaultCurrentTry, MaxTries);

	int AllowedMaxTries = BCGame.GetMaxTries();
	std::string Guess = "";

	// TODO change from "for" to "while" loop once
	// finished validating tries
	for (int i = 0; i < AllowedMaxTries; i++)
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
	constexpr int WORD_LENGTH = 4;

	std::cout << "Welcome to Bulls and Cows" << std::endl;
	printf("Can you guess the %d letter isogram\n", WORD_LENGTH);

	std::cout << std::endl;

	return;
}

std::string GetGuess()
{
	std::string Guess = "";
	int CurrentTry = BCGame.GetCurrentTry();

	// Input guess
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	getline(std::cin, Guess);

	return Guess;
}

void PrintGuess(std::string Guess)
{
	std::cout << "You guessed " << Guess << std::endl;

	std::cout << std::endl;
}

bool AskToPlayAgain()
{
	std::string Response = "";
	std::cout << "Do you want to play again(y/n): ";
	getline(std::cin, Response);

	std::cout << std::endl;

	return (tolower(Response[0]) == 'y' ? true : false);
}
