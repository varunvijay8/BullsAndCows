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
	int MaxTries = BCGame.GetMaxTries();
	std::string Guess = "";

	for (int i = 0; i < MaxTries; i++)
	{
		Guess = GetGuess();
		PrintGuess(Guess);
	}
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
	std::cout << "Try "<< CurrentTry <<". Enter your guess: ";
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
